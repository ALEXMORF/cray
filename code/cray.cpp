#include "cray.h"
#include "cray_memory.cpp"
#include "cray_obj.cpp"

/*TODO(chen):

. clean up the code
. work-around ugly padding issues & figure out a compact way to upload model (vertices, normals, materials)
. Progressive rendering
. Proper Sky model: http://blog.hvidtfeldts.net/index.php/2015/01/path-tracing-3d-fractals/
. Filmic tonemapping
. glass ball
. imgui for controlling lighting environments and such

*/

internal GLuint
CompileShader(char *FilePath, GLenum Type)
{
    GLuint Shader = glCreateShader(Type);
    
    char *SourceCode = ReadFileTemporarily(FilePath);
    glShaderSource(Shader, 1, &SourceCode, 0);
    glCompileShader(Shader);
    
    GLint ShaderIsCompiled;
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &ShaderIsCompiled);
    if (ShaderIsCompiled != GL_TRUE)
    {
        GLchar Message[1024];
        glGetShaderInfoLog(Shader, sizeof(Message), 0, Message);
        
        ASSERT(!"Fail to compile shader");
    }
    
    return Shader;
}

internal void
RunCRay(app_memory *Memory, input *Input, f32 dT, int Width, int Height)
{
    ASSERT(sizeof(cray) <= Memory->Size);
    cray *CRay = (cray *)Memory->Data;
    
    if (!Memory->IsInitialized)
    {
        u8 *RestOfMemory = (u8 *)Memory->Data + sizeof(cray);
        int RestOfMemorySize = Memory->Size - sizeof(cray);
        CRay->MainArena = InitMemoryArena(RestOfMemory, RestOfMemorySize);
        GlobalTempArena = PushMemoryArena(&CRay->MainArena, MB(2));
        
        // make shader
        {
            GLuint VShader = CompileShader("../code/vert.glsl", GL_VERTEX_SHADER);
            GLuint FShader = CompileShader("../code/frag.glsl", GL_FRAGMENT_SHADER);
            CRay->Shader = glCreateProgram();
            glAttachShader(CRay->Shader, VShader);
            glAttachShader(CRay->Shader, FShader);
            glLinkProgram(CRay->Shader);
            
            GLint ShaderIsLinked;
            glGetProgramiv(CRay->Shader, GL_LINK_STATUS, &ShaderIsLinked);
            if (ShaderIsLinked != GL_TRUE)
            {
                GLchar Message[1024];
                glGetProgramInfoLog(CRay->Shader, sizeof(Message), 0, Message);
                
                ASSERT(!"Shader failed to link");
            }
        }
        
        // make fullscreen VAO
        {
            f32 QuadVertices[] = {
                0.0f, 1.0f, 0.0f,
                1.0f, 0.0f, 0.0f,
                1.0f, 1.0f, 0.0f,
                
                0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f,
                1.0f, 0.0f, 0.0f,
            };
            
            GLuint VBO = 0;
            glGenBuffers(1, &VBO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(QuadVertices), QuadVertices, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            
            glGenVertexArrays(1, &CRay->QuadVAO);
            glBindVertexArray(CRay->QuadVAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
            glBindVertexArray(0);
        }
        
        CRay->CamP = {0.0f, 0.7f, -2.0f};
        CRay->DraggedRotation = Quaternion();
        CRay->CamOrientation = Quaternion(XAxis(), 0.1f);
        
        //obj_model MonkeyModel = LoadObj("../data/monkey", &CRay->MainArena);
        obj_model MonkeyModel = LoadObj("../data/lowpoly_monkey", &GlobalTempArena);
        
        for (int VertIndex = 0; VertIndex < MonkeyModel.VertexCount; ++VertIndex)
        {
            MonkeyModel.Vertices[VertIndex].P *= 0.5f;
            MonkeyModel.Vertices[VertIndex].P.Y += 0.6f;
            MonkeyModel.Vertices[VertIndex].P.Z *= -1.0f;
        }
        
        //NOTE(chen): upload vertices onto SSBO
        glGenBuffers(1, &CRay->SSBO);
        glBindBuffer(GL_SHADER_STORAGE_BUFFER, CRay->SSBO);
        glBufferData(GL_SHADER_STORAGE_BUFFER, 
                     MonkeyModel.VertexCount*sizeof(vertex), 
                     MonkeyModel.Vertices, GL_STATIC_DRAW);
        glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, CRay->SSBO);
        glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); 
        CRay->VertexCount = MonkeyModel.VertexCount;
        
        Memory->IsInitialized = true;
    }
    Clear(&GlobalTempArena);
    CRay->T += dT;
    
    //NOTE(chen): handle mouse dragging
    if (CRay->CamIsBeingDragged)
    {
        if (!Input->MouseIsDown)
        {
            CRay->CamIsBeingDragged = false;
            CRay->CamOrientation = CRay->DraggedRotation * CRay->CamOrientation;
            CRay->DraggedRotation = Quaternion();
        }
        else
        {
            v2 MousedP = Input->MouseP - CRay->StartMouseP;
            quaternion YRot = Quaternion(YAxis(), MousedP.X);
            v3 LocalXAxis = Rotate(XAxis(), YRot * CRay->CamOrientation);
            quaternion XRot = Quaternion(LocalXAxis, -MousedP.Y);
            CRay->DraggedRotation = XRot * YRot;
        }
    }
    else
    {
        if (Input->MouseIsDown)
        {
            CRay->CamIsBeingDragged = true;
            CRay->StartMouseP = Input->MouseP;
        }
    }
    
    v3 dP = {};
    if (Input->Keys['W']) dP.Z += 1.0;
    if (Input->Keys['S']) dP.Z -= 1.0;
    if (Input->Keys['A']) dP.X -= 1.0;
    if (Input->Keys['D']) dP.X += 1.0;
    dP = Rotate(dP, CRay->DraggedRotation * CRay->CamOrientation);
    dP.Y = 0.0f;
    if (Input->Keys['Z']) dP.Y -= 1.0;
    if (Input->Keys['X']) dP.Y += 1.0;
    
    float CamSpeed = 1.0f;
    CRay->CamP += CamSpeed * dT * Normalize(dP);
    CRay->CamLookAt = CRay->CamP + Rotate(ZAxis(), CRay->DraggedRotation * CRay->CamOrientation);
    
    glDisable(GL_DEPTH_TEST);
    glViewport(0, 0, Width, Height);
    glUseProgram(CRay->Shader);
    
    glUniform1i(glGetUniformLocation(CRay->Shader, "VertexCount"), CRay->VertexCount);
    
    glUniform3f(glGetUniformLocation(CRay->Shader, "CamP"), 
                CRay->CamP.X, CRay->CamP.Y, CRay->CamP.Z);
    glUniform3f(glGetUniformLocation(CRay->Shader, "CamLookAt"), 
                CRay->CamLookAt.X, CRay->CamLookAt.Y, CRay->CamLookAt.Z);
    glUniform1f(glGetUniformLocation(CRay->Shader, "Time"), CRay->T);
    f32 AspectRatio = (f32)Width / (f32)Height;
    glUniform1f(glGetUniformLocation(CRay->Shader, "AspectRatio"), AspectRatio);
    
    glBindVertexArray(CRay->QuadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}