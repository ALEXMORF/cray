#include "gl_imgui.cpp"

inline void
PushUniformI32(gl_renderer *Renderer, char *Name, int Value)
{
    glUniform1i(glGetUniformLocation(Renderer->CurrentShader, Name), Value);
}

inline void
PushUniformB32(gl_renderer *Renderer, char *Name, b32 Value)
{
    glUniform1i(glGetUniformLocation(Renderer->CurrentShader, Name), Value);
}

inline void
PushUniformF32(gl_renderer *Renderer, char *Name, f32 Value)
{
    glUniform1f(glGetUniformLocation(Renderer->CurrentShader, Name), Value);
}

inline void
PushUniformV3(gl_renderer *Renderer, char *Name, v3 Vector)
{
    glUniform3f(glGetUniformLocation(Renderer->CurrentShader, Name), 
                Vector.X, Vector.Y, Vector.Z);
}

inline void
PushUniformMat4(gl_renderer *Renderer, char *Name, mat4 Mat)
{
    glUniformMatrix4fv(glGetUniformLocation(Renderer->CurrentShader, Name), 
                       1, GL_TRUE, (f32 *)Mat.Data);
}

internal GLuint
CompileShader(char *Name, char *SourceCode, GLenum Type)
{
    GLuint Shader = glCreateShader(Type);
    
    ASSERT(SourceCode);
    glShaderSource(Shader, 1, &SourceCode, 0);
    glCompileShader(Shader);
    
    GLint ShaderIsCompiled;
    glGetShaderiv(Shader, GL_COMPILE_STATUS, &ShaderIsCompiled);
    if (ShaderIsCompiled != GL_TRUE)
    {
        GLchar Message[1024];
        glGetShaderInfoLog(Shader, sizeof(Message), 0, Message);
        char *ShaderType = Type == GL_VERTEX_SHADER? "Vertex Shader": "Fragment Shader";
        Panic("Failed to compile %s\n: %s error:\n %s", 
              Name, ShaderType, Message);
    }
    
    return Shader;
}

internal GLuint
CompileShaderProgram(char *ShaderName, char *VShaderSourceCode, char *FShaderSourceCode)
{
    GLuint Shader = glCreateProgram();
    
    GLuint VShader = CompileShader(ShaderName, VShaderSourceCode, GL_VERTEX_SHADER);
    GLuint FShader = CompileShader(ShaderName, FShaderSourceCode, GL_FRAGMENT_SHADER);
    glAttachShader(Shader, VShader);
    glAttachShader(Shader, FShader);
    glLinkProgram(Shader);
    
    GLint ShaderIsLinked;
    glGetProgramiv(Shader, GL_LINK_STATUS, &ShaderIsLinked);
    if (ShaderIsLinked != GL_TRUE)
    {
        GLchar Message[1024];
        glGetProgramInfoLog(Shader, sizeof(Message), 0, Message);
        Panic("Failed to link %s:\n %s", ShaderName, Message);
    }
    
    return Shader;
}

internal GLuint 
MakeQuadVAO()
{
    GLuint VAO = 0;
    
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
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glBindVertexArray(0);
    
    return VAO;
}

inline framebuffer
InitFramebuffer(int Width, int Height, int TexCount)
{
    framebuffer Framebuffer = {};
    Framebuffer.TexCount = TexCount;
    
    glGenTextures(TexCount, Framebuffer.TexHandles);
    for (int TexIndex = 0; TexIndex < TexCount; ++TexIndex)
    {
        glBindTexture(GL_TEXTURE_2D, Framebuffer.TexHandles[TexIndex]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, Width, Height, 0, 
                     GL_RGB, GL_FLOAT, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
    glGenRenderbuffers(1, &Framebuffer.RBOHandle);
    glBindRenderbuffer(GL_RENDERBUFFER, Framebuffer.RBOHandle);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, Width, Height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    
    glGenFramebuffers(1, &Framebuffer.Handle);
    glBindFramebuffer(GL_FRAMEBUFFER, Framebuffer.Handle);
    
    // bind RBO
    glBindRenderbuffer(GL_RENDERBUFFER, Framebuffer.RBOHandle);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, 
                              GL_RENDERBUFFER, Framebuffer.RBOHandle);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    
    for (int TexIndex = 0; TexIndex < TexCount; ++TexIndex)
    {
        glBindTexture(GL_TEXTURE_2D, Framebuffer.TexHandles[TexIndex]);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + TexIndex,
                               GL_TEXTURE_2D, Framebuffer.TexHandles[TexIndex],
                               0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    
    ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
    return Framebuffer;
}

internal void
DeleteFramebuffer(framebuffer *Framebuffer)
{
    glDeleteFramebuffers(1, &Framebuffer->Handle);
    glDeleteTextures(Framebuffer->TexCount, Framebuffer->TexHandles);
    glDeleteRenderbuffers(1, &Framebuffer->RBOHandle);
}

internal void
UseShader(gl_renderer *Renderer, GLuint Shader)
{
    glUseProgram(Shader);
    Renderer->CurrentShader = Shader;
}
internal void APIENTRY 
OpenglCallback(GLenum Source, GLenum Type,
               GLuint ID, GLenum Severity,
               GLsizei Length,
               const GLchar* Message,
               const void* UserData)
{
    switch (Type)
    {
        case GL_DEBUG_TYPE_ERROR:
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        case GL_DEBUG_TYPE_PORTABILITY:
        {
            Panic("OpenGL Error:\n %s", Message);
        } break;
        
        case GL_DEBUG_TYPE_PERFORMANCE:
        {
            //TODO(chen): record performance problems
        } break;
    }
    
#if 0
    if (Severity == GL_DEBUG_SEVERITY_MEDIUM || 
        Severity == GL_DEBUG_SEVERITY_HIGH)
    {
        ASSERT(!"High Severity issue");
    }
#endif
}

internal gl_renderer
InitGLRenderer(int Width, int Height)
{
    gl_renderer Renderer = {};
    
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(OpenglCallback, 0);
    
    Renderer.SampleShader = CompileShaderProgram("sample shader", fullscreen_vert, sample_frag);
    Renderer.BlitShader = CompileShaderProgram("blit shader", fullscreen_vert, blit_frag);
    Renderer.GBufferPassShader = CompileShaderProgram("gbuffer shader", geom_vert, gbuffer_frag);
    
    Renderer.QuadVAO = MakeQuadVAO();
    Renderer.BackBuffer = InitFramebuffer(Width, Height, 2);
    Renderer.GBuffer = InitFramebuffer(Width, Height, 4);
    
    Renderer.Width = Width;
    Renderer.Height = Height;
    Renderer.LastBufferIndex = 0;
    Renderer.BufferIndex = 1;
    Renderer.Exposure = 0.5f;
    
    Renderer.Settings.FOV = DegreeToRadian(45.0f);
    Renderer.Settings.RasterizeFirstBounce = false;
    Renderer.Settings.EnableGroundPlane = true;
    Renderer.Settings.MaxBounceCount = 2;
    Renderer.Settings.L = {0.5f, 0.4f, -0.5f};
    Renderer.Settings.SunRadiance = V3(4.0f);
    Renderer.Settings.Zenith = {0.0f, 0.44f, 2.66f};
    Renderer.Settings.Azimuth = {1.0f, 1.4f, 1.6f};
    
    InitImguiOpengl();
    
    return Renderer;
}

internal GLuint
BindSSBO(int BindingIndex, void *Data, int Size)
{
    //NOTE(chen): upload triangles onto SSBO
    GLuint SSBO = 0;
    glGenBuffers(1, &SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSBO);
    glBufferData(GL_SHADER_STORAGE_BUFFER, Size, Data, GL_STATIC_DRAW);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, BindingIndex, SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); 
    
    return SSBO;
}

internal void
UploadModelToGLRenderer(gl_renderer *Renderer, loaded_model Model)
{
    if (Renderer->GeometryVAO)
    {
        glDeleteVertexArrays(1, &Renderer->GeometryVAO);
        Renderer->GeometryVAO = 0;
    }
    if (Renderer->TrianglesSSBO)
    {
        glDeleteBuffers(1, &Renderer->TrianglesSSBO);
        Renderer->TrianglesSSBO = 0;
    }
    if (Renderer->BvhSSBO)
    {
        glDeleteBuffers(1, &Renderer->BvhSSBO);
        Renderer->BvhSSBO = 0;
    }
    
    //NOTE(chen): upload goemetry VAO
    {
        GLuint VBO = 0;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, Model.Vertices.Count*sizeof(vertex), 
                     Model.Vertices.Data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glGenVertexArrays(1, &Renderer->GeometryVAO);
        glBindVertexArray(Renderer->GeometryVAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 
                              sizeof(vertex), (void *)offsetof(vertex, P));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 
                              sizeof(vertex), (void *)offsetof(vertex, N));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 
                              sizeof(vertex), (void *)offsetof(vertex, Albedo));
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 
                              sizeof(vertex), (void *)offsetof(vertex, Emission));
        
        glBindVertexArray(0);
        
        glDeleteBuffers(1, &VBO);
    }
    
    Renderer->TrianglesSSBO = BindSSBO(0, Model.Triangles.Data, 
                                       Model.Triangles.Count * 
                                       sizeof(packed_triangle));
    Renderer->BvhSSBO = BindSSBO(1, Model.BVH.Data, 
                                 Model.BVH.Count * 
                                 sizeof(bvh_entry));
    
    Renderer->GeometryVertexCount = Model.Vertices.Count;
    Renderer->TriangleCount = Model.Triangles.Count;
    Renderer->BvhEntryCount = Model.BVH.Count;
}

internal void
Refresh(gl_renderer *Renderer)
{
    Renderer->SampleCountSoFar = 0;
    Renderer->LastBufferIndex = 0;
    Renderer->BufferIndex = 1;
}

internal void
ResizeResources(gl_renderer *Renderer, int Width, int Height)
{
    if (Renderer->Width != Width ||
        Renderer->Height != Height)
    {
        Refresh(Renderer);
        DeleteFramebuffer(&Renderer->BackBuffer);
        DeleteFramebuffer(&Renderer->GBuffer);
        
        Renderer->BackBuffer = InitFramebuffer(Width, Height, Renderer->BackBuffer.TexCount);
        Renderer->GBuffer = InitFramebuffer(Width, Height, Renderer->GBuffer.TexCount);
        
        Renderer->Width = Width;
        Renderer->Height = Height;
    }
}

internal void
Render(gl_renderer *Renderer, camera *Camera, f32 T)
{
    f32 AspectRatio = (f32)Renderer->Width / (f32)Renderer->Height;
    
    //NOTE(chen): G-buffer pass
    if (Renderer->Settings.RasterizeFirstBounce)
    {
        GLenum RenderTargets[] = {
            GL_COLOR_ATTACHMENT0, 
            GL_COLOR_ATTACHMENT1, 
            GL_COLOR_ATTACHMENT2, 
            GL_COLOR_ATTACHMENT3, 
        };
        
        glBindFramebuffer(GL_FRAMEBUFFER, Renderer->GBuffer.Handle);
        glDrawBuffers(ARRAY_COUNT(RenderTargets), RenderTargets);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, Renderer->Width, Renderer->Height);
        
        UseShader(Renderer, Renderer->GBufferPassShader);
        
        mat4 View = Mat4LookAt(Camera->P, Camera->LookAt);
        mat4 Projection = Mat4Perspective(Renderer->Settings.FOV, 
                                          AspectRatio, 0.1f, 1000.0f);
        
        PushUniformMat4(Renderer, "View", View);
        PushUniformMat4(Renderer, "Projection", Projection);
        
        glBindVertexArray(Renderer->GeometryVAO);
        glDrawArrays(GL_TRIANGLES, 0, Renderer->GeometryVertexCount);
    }
    
    //NOTE(chen): start sampling light
    {
        glBindFramebuffer(GL_FRAMEBUFFER, Renderer->BackBuffer.Handle);
        glDrawBuffer(GL_COLOR_ATTACHMENT0 + Renderer->BufferIndex);
        glDisable(GL_DEPTH_TEST);
        glViewport(0, 0, Renderer->Width, Renderer->Height);
        
        UseShader(Renderer, Renderer->SampleShader);
        
        PushUniformI32(Renderer, "TriangleCount", Renderer->TriangleCount);
        PushUniformI32(Renderer, "BvhEntryCount", Renderer->BvhEntryCount);
        PushUniformF32(Renderer, "Time", T);
        
        PushUniformF32(Renderer, "AspectRatio", AspectRatio);
        PushUniformF32(Renderer, "FOV", Renderer->Settings.FOV);
        PushUniformI32(Renderer, "MaxBounceCount", Renderer->Settings.MaxBounceCount);
        PushUniformB32(Renderer, "EnableGroundPlane", Renderer->Settings.EnableGroundPlane);
        
        PushUniformV3(Renderer, "CamP", Camera->P);
        PushUniformV3(Renderer, "CamLookAt", Camera->LookAt);
        PushUniformV3(Renderer, "L", Normalize(Renderer->Settings.L));
        PushUniformV3(Renderer, "SunRadiance", Renderer->Settings.SunRadiance);
        PushUniformV3(Renderer, "Zenith", Renderer->Settings.Zenith);
        PushUniformV3(Renderer, "Azimuth", Renderer->Settings.Azimuth);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Renderer->BackBuffer.TexHandles[Renderer->LastBufferIndex]);
        PushUniformI32(Renderer, "PrevSamplesTex", 0);
        PushUniformI32(Renderer, "SampleCountSoFar", Renderer->SampleCountSoFar);
        
        PushUniformB32(Renderer, "RasterizeFirstBounce", Renderer->Settings.RasterizeFirstBounce);
        if (Renderer->Settings.RasterizeFirstBounce)
        {
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, Renderer->GBuffer.TexHandles[0]);
            PushUniformI32(Renderer, "PositionTex", 1);
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, Renderer->GBuffer.TexHandles[1]);
            PushUniformI32(Renderer, "NormalTex", 2);
            glActiveTexture(GL_TEXTURE3);
            glBindTexture(GL_TEXTURE_2D, Renderer->GBuffer.TexHandles[2]);
            PushUniformI32(Renderer, "AlbedoTex", 3);
            glActiveTexture(GL_TEXTURE4);
            glBindTexture(GL_TEXTURE_2D, Renderer->GBuffer.TexHandles[3]);
            PushUniformI32(Renderer, "EmissionTex", 4);
        }
        
        glBindVertexArray(Renderer->QuadVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        //NOTE(chen): blit framebuffer onto default framebuffer
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        {
            UseShader(Renderer, Renderer->BlitShader);
            PushUniformF32(Renderer, "Exposure", Renderer->Exposure);
            
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, Renderer->BackBuffer.TexHandles[Renderer->BufferIndex]);
            PushUniformI32(Renderer, "HdrTex", 0);
            
            glBindVertexArray(Renderer->QuadVAO);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }
        
        Renderer->SampleCountSoFar += 1;
        Renderer->LastBufferIndex = Renderer->BufferIndex;
        Renderer->BufferIndex = (Renderer->BufferIndex + 1) % Renderer->BackBuffer.TexCount;
    }
}
