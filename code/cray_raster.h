#pragma once

struct framebuffer
{
    GLuint Handle;
    GLuint TexHandles[2];
    GLuint RBOHandle;
};

struct gl_rasterizer
{
    GLuint SampleShader;
    GLuint BlitShader;
    GLuint CurrentShader;
    
    GLuint QuadVAO;
    
    int LastBufferIndex;
    int BufferIndex;
    int SampleCountSoFar;
    framebuffer BackBuffer;
    int Width;
    int Height;
};