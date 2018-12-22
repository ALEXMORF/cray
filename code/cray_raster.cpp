inline void
PushUniformI32(gl_rasterizer *Rasterizer, char *Name, int Value)
{
    glUniform1i(glGetUniformLocation(Rasterizer->CurrentShader, Name), Value);
}

inline void
PushUniformV3(gl_rasterizer *Rasterizer, char *Name, v3 Vector)
{
    glUniform3f(glGetUniformLocation(Rasterizer->CurrentShader, Name), 
                Vector.X, Vector.Y, Vector.Z);
}

inline void
PushUniformF32(gl_rasterizer *Rasterizer, char *Name, f32 Value)
{
    glUniform1f(glGetUniformLocation(Rasterizer->CurrentShader, Name), Value);
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
InitFramebuffer(int Width, int Height)
{
    framebuffer Framebuffer = {};
    
    glGenTextures(2, Framebuffer.TexHandles);
    for (int TexIndex = 0; TexIndex < ARRAY_COUNT(Framebuffer.TexHandles); ++TexIndex)
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
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, Width, Height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    
    glGenFramebuffers(1, &Framebuffer.Handle);
    glBindFramebuffer(GL_FRAMEBUFFER, Framebuffer.Handle);
    
    // bind RBO
    glBindRenderbuffer(GL_RENDERBUFFER, Framebuffer.RBOHandle);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_COMPONENT, 
                              GL_RENDERBUFFER, Framebuffer.RBOHandle);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    
    for (int TexIndex = 0; TexIndex < ARRAY_COUNT(Framebuffer.TexHandles); ++TexIndex)
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
UseShader(gl_rasterizer *Rasterizer, GLuint Shader)
{
    glUseProgram(Shader);
    Rasterizer->CurrentShader = Shader;
}

internal gl_rasterizer
InitGLRasterizer(int Width, int Height)
{
    gl_rasterizer Rasterizer = {};
    Rasterizer.SampleShader = CompileShaderProgram("../code/vert.glsl", "../code/sample_frag.glsl");
    Rasterizer.BlitShader = CompileShaderProgram("../code/vert.glsl", "../code/blit_frag.glsl");
    Rasterizer.QuadVAO = MakeQuadVAO();
    Rasterizer.BackBuffer = InitFramebuffer(Width, Height);
    
    Rasterizer.Width = Width;
    Rasterizer.Height = Height;
    Rasterizer.LastBufferIndex = 0;
    Rasterizer.BufferIndex = 1;
    
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
        glDeleteFramebuffers(1, &Rasterizer->BackBuffer.Handle);
        glDeleteTextures(2, Rasterizer->BackBuffer.TexHandles);
        glDeleteRenderbuffers(1, &Rasterizer->BackBuffer.RBOHandle);
        
        Rasterizer->BackBuffer = InitFramebuffer(Width, Height);
        Rasterizer->Width = Width;
        Rasterizer->Height = Height;
    }
    
    glDisable(GL_DEPTH_TEST);
    glViewport(0, 0, Width, Height);
    
    UseShader(Rasterizer, Rasterizer->SampleShader);
}

internal void
Rasterize(gl_rasterizer *Rasterizer)
{
    glBindFramebuffer(GL_FRAMEBUFFER, Rasterizer->BackBuffer.Handle);
    glDrawBuffer(GL_COLOR_ATTACHMENT0 + Rasterizer->BufferIndex);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Rasterizer->BackBuffer.TexHandles[Rasterizer->LastBufferIndex]);
    PushUniformI32(Rasterizer, "PrevSamplesTex", 0);
    PushUniformI32(Rasterizer, "SampleCountSoFar", Rasterizer->SampleCountSoFar);
    
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
    Rasterizer->BufferIndex = (Rasterizer->BufferIndex + 1) % ARRAY_COUNT(Rasterizer->BackBuffer.TexHandles);
}
