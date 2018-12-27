#pragma once

struct framebuffer
{
    GLuint Handle;
    GLuint TexHandles[8];
    GLuint RBOHandle;
    
    int TexCount;
};

struct render_settings
{
    f32 FOV;
    b32 RasterizeFirstBounce;
    int MaxBounceCount;
    b32 EnableGroundPlane;
    
    v3 L;
    v3 SunRadiance;
    v3 Zenith;
    v3 Azimuth;
};

bool operator!=(render_settings A, render_settings B)
{
    return memcmp(&A, &B, sizeof(A)) != 0;
}

struct gl_rasterizer
{
    render_settings Settings;
    f32 Exposure;
    
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