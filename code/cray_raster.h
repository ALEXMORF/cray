#pragma once

struct framebuffer
{
    GLuint Handle;
    GLuint TexHandles[8];
    GLuint RBOHandle;
    
    int TexCount;
};

struct gl_rasterizer
{
    f32 FOV;
    
    b32 RasterizeFirstBounce;
    int MaxBounceCount;
    
    GLuint SampleShader;
    GLuint BlitShader;
    GLuint GBufferPassShader;
    
    GLuint CurrentShader;
    GLuint QuadVAO;
    
    int LastBufferIndex;
    int BufferIndex;
    int SampleCountSoFar;
    framebuffer GBuffer;
    framebuffer BackBuffer;
    int Width;
    int Height;
};