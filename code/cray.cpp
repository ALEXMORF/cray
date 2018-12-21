#include "cray.h"
#include "cray_memory.cpp"

/*TODO(chen):

. Environment Map
. glass ball
. Import mesh
. Raytrace Susan's head
. Progressive rendering

*/

internal char *
ReadFileTemporarily(char *FilePath)
{
    char *Buffer = 0;
    
    FILE *File = fopen(FilePath, "rb");
    if (File)
    {
        fseek(File, 0, SEEK_END);
        int FileSize = ftell(File);
        rewind(File);
        
        Buffer = PushTempArray(FileSize+1, char);
        Buffer[FileSize] = 0;
        fread(Buffer, 1, FileSize, File);
        
        fclose(File);
    }
    
    return Buffer;
}

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
        GlobalTempArena = PushMemoryArena(&CRay->MainArena, KB(32));
        
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
            v3 LocalXAxis = Rotate(XAxis(), YRot);
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