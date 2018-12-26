inline void
PushUniformI32(gl_rasterizer *Rasterizer, char *Name, int Value)
{
    glUniform1i(glGetUniformLocation(Rasterizer->CurrentShader, Name), Value);
}

inline void
PushUniformB32(gl_rasterizer *Rasterizer, char *Name, b32 Value)
{
    glUniform1i(glGetUniformLocation(Rasterizer->CurrentShader, Name), Value);
}

inline void
PushUniformF32(gl_rasterizer *Rasterizer, char *Name, f32 Value)
{
    glUniform1f(glGetUniformLocation(Rasterizer->CurrentShader, Name), Value);
}

inline void
PushUniformV3(gl_rasterizer *Rasterizer, char *Name, v3 Vector)
{
    glUniform3f(glGetUniformLocation(Rasterizer->CurrentShader, Name), 
                Vector.X, Vector.Y, Vector.Z);
}

inline void
PushUniformMat4(gl_rasterizer *Rasterizer, char *Name, mat4 Mat)
{
    glUniformMatrix4fv(glGetUniformLocation(Rasterizer->CurrentShader, Name), 
                       1, GL_TRUE, (f32 *)Mat.Data);
}

internal GLuint
CompileShader(char *FilePath, GLenum Type)
{
    GLuint Shader = glCreateShader(Type);
    
    char *SourceCode = ReadFileTemporarily(FilePath);
    ASSERT(SourceCode);
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

internal GLuint
CompileShaderProgram(char *VShaderPath, char *FShaderPath)
{
    GLuint Shader = glCreateProgram();
    
    GLuint VShader = CompileShader(VShaderPath, GL_VERTEX_SHADER);
    GLuint FShader = CompileShader(FShaderPath, GL_FRAGMENT_SHADER);
    glAttachShader(Shader, VShader);
    glAttachShader(Shader, FShader);
    glLinkProgram(Shader);
    
    GLint ShaderIsLinked;
    glGetProgramiv(Shader, GL_LINK_STATUS, &ShaderIsLinked);
    if (ShaderIsLinked != GL_TRUE)
    {
        GLchar Message[1024];
        glGetProgramInfoLog(Shader, sizeof(Message), 0, Message);
        
        ASSERT(!"Shader failed to link");
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
UseShader(gl_rasterizer *Rasterizer, GLuint Shader)
{
    glUseProgram(Shader);
    Rasterizer->CurrentShader = Shader;
}

internal gl_rasterizer
InitRasterizer(int Width, int Height)
{
    gl_rasterizer Rasterizer = {};
    Rasterizer.SampleShader = CompileShaderProgram("../code/fullscreen_vert.glsl", "../code/sample_frag.glsl");
    Rasterizer.BlitShader = CompileShaderProgram("../code/fullscreen_vert.glsl", "../code/blit_frag.glsl");
    Rasterizer.GBufferPassShader = CompileShaderProgram("../code/geom_vert.glsl", "../code/gbuffer_frag.glsl");
    Rasterizer.QuadVAO = MakeQuadVAO();
    Rasterizer.BackBuffer = InitFramebuffer(Width, Height, 2);
    Rasterizer.GBuffer = InitFramebuffer(Width, Height, 4);
    
    Rasterizer.Width = Width;
    Rasterizer.Height = Height;
    Rasterizer.LastBufferIndex = 0;
    Rasterizer.BufferIndex = 1;
    
    Rasterizer.Settings.FOV = DegreeToRadian(45.0f);
    Rasterizer.Settings.RasterizeFirstBounce = true;
    Rasterizer.Settings.MaxBounceCount = 2;
    
    return Rasterizer;
}

internal void
Refresh(gl_rasterizer *Rasterizer)
{
    Rasterizer->SampleCountSoFar = 0;
    Rasterizer->LastBufferIndex = 0;
    Rasterizer->BufferIndex = 1;
}

internal void
PrepareForRasterization(gl_rasterizer *Rasterizer, int Width, int Height)
{
    if (Rasterizer->Width != Width ||
        Rasterizer->Height != Height)
    {
        Refresh(Rasterizer);
        DeleteFramebuffer(&Rasterizer->BackBuffer);
        DeleteFramebuffer(&Rasterizer->GBuffer);
        
        Rasterizer->BackBuffer = InitFramebuffer(Width, Height, Rasterizer->BackBuffer.TexCount);
        Rasterizer->GBuffer = InitFramebuffer(Width, Height, Rasterizer->GBuffer.TexCount);
        
        Rasterizer->Width = Width;
        Rasterizer->Height = Height;
    }
}

internal void
Rasterize(gl_rasterizer *Rasterizer, scene *Scene, 
          uploaded_data *Uploaded, f32 T)
{
    f32 AspectRatio = (f32)Rasterizer->Width / (f32)Rasterizer->Height;
    
    //NOTE(chen): G-buffer pass
    if (Rasterizer->Settings.RasterizeFirstBounce)
    {
        GLenum RenderTargets[] = {
            GL_COLOR_ATTACHMENT0, 
            GL_COLOR_ATTACHMENT1, 
            GL_COLOR_ATTACHMENT2, 
            GL_COLOR_ATTACHMENT3, 
        };
        
        glBindFramebuffer(GL_FRAMEBUFFER, Rasterizer->GBuffer.Handle);
        glDrawBuffers(ARRAY_COUNT(RenderTargets), RenderTargets);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, Rasterizer->Width, Rasterizer->Height);
        
        UseShader(Rasterizer, Rasterizer->GBufferPassShader);
        
        mat4 View = Mat4LookAt(Scene->CamP, Scene->CamLookAt);
        mat4 Projection = Mat4Perspective(Rasterizer->Settings.FOV, 
                                          AspectRatio, 0.1f, 1000.0f);
        
        PushUniformMat4(Rasterizer, "View", View);
        PushUniformMat4(Rasterizer, "Projection", Projection);
        
        glBindVertexArray(Uploaded->GeometryVAO);
        glDrawArrays(GL_TRIANGLES, 0, Uploaded->GeometryVertexCount);
    }
    
    //NOTE(chen): start sampling light
    {
        glBindFramebuffer(GL_FRAMEBUFFER, Rasterizer->BackBuffer.Handle);
        glDrawBuffer(GL_COLOR_ATTACHMENT0 + Rasterizer->BufferIndex);
        glDisable(GL_DEPTH_TEST);
        glViewport(0, 0, Rasterizer->Width, Rasterizer->Height);
        
        UseShader(Rasterizer, Rasterizer->SampleShader);
        
        PushUniformI32(Rasterizer, "TriangleCount", Uploaded->TriangleCount);
        PushUniformI32(Rasterizer, "BvhEntryCount", Uploaded->BvhEntryCount);
        PushUniformF32(Rasterizer, "Time", T);
        
        PushUniformV3(Rasterizer, "CamP", Scene->CamP);
        PushUniformV3(Rasterizer, "CamLookAt", Scene->CamLookAt);
        
        PushUniformF32(Rasterizer, "AspectRatio", AspectRatio);
        PushUniformF32(Rasterizer, "FOV", Rasterizer->Settings.FOV);
        PushUniformI32(Rasterizer, "MaxBounceCount", Rasterizer->Settings.MaxBounceCount);
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Rasterizer->BackBuffer.TexHandles[Rasterizer->LastBufferIndex]);
        PushUniformI32(Rasterizer, "PrevSamplesTex", 0);
        PushUniformI32(Rasterizer, "SampleCountSoFar", Rasterizer->SampleCountSoFar);
        
        PushUniformB32(Rasterizer, "RasterizeFirstBounce", Rasterizer->Settings.RasterizeFirstBounce);
        if (Rasterizer->Settings.RasterizeFirstBounce)
        {
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, Rasterizer->GBuffer.TexHandles[0]);
            PushUniformI32(Rasterizer, "PositionTex", 1);
            glActiveTexture(GL_TEXTURE2);
            glBindTexture(GL_TEXTURE_2D, Rasterizer->GBuffer.TexHandles[1]);
            PushUniformI32(Rasterizer, "NormalTex", 2);
            glActiveTexture(GL_TEXTURE3);
            glBindTexture(GL_TEXTURE_2D, Rasterizer->GBuffer.TexHandles[2]);
            PushUniformI32(Rasterizer, "AlbedoTex", 3);
            glActiveTexture(GL_TEXTURE4);
            glBindTexture(GL_TEXTURE_2D, Rasterizer->GBuffer.TexHandles[3]);
            PushUniformI32(Rasterizer, "EmissionTex", 4);
        }
        
        glBindVertexArray(Rasterizer->QuadVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        //NOTE(chen): blit framebuffer onto default framebuffer
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        {
            UseShader(Rasterizer, Rasterizer->BlitShader);
            
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, Rasterizer->BackBuffer.TexHandles[Rasterizer->BufferIndex]);
            PushUniformI32(Rasterizer, "HdrTex", 0);
            
            glBindVertexArray(Rasterizer->QuadVAO);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        }
        
        Rasterizer->SampleCountSoFar += 1;
        Rasterizer->LastBufferIndex = Rasterizer->BufferIndex;
        Rasterizer->BufferIndex = (Rasterizer->BufferIndex + 1) % Rasterizer->BackBuffer.TexCount;
    }
}
