#pragma once
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>

#pragma pack(push, 1)
struct packed_triangle
{
    v3 A;
    u32 Pad1;
    v3 B;
    u32 Pad2;
    v3 C;
    u32 Pad3;
    v3 N;
    u32 Pad4;
    v3 Albedo;
    u32 Pad5;
    v3 Emission;
    u32 Pad6;
};

struct packed_bvh_entry
{
    //NOTE(chen): bound
    v3 BoundMin;
    u32 Pad1;
    v3 BoundMax;
    u32 Pad2;
    
    union
    {
        i32 PrimitiveOffset;
        i32 SecondChildOffset;
    };
    i32 PrimitiveCount;
    i32 Axis;
    u32 Pad3;
};

struct render_settings
{
    f32 Exposure;
    f32 FOV;
    b32 RasterizeFirstBounce;
    i32 MaxBounceCount;
    b32 EnableGroundPlane;
    b32 DoCoherentSample;
    u32 Pad[2];
    
    v3 L;
    u32 Pad0;
    v3 SunRadiance;
    u32 Pad1;
    v3 Zenith;
    u32 Pad2;
    v3 Azimuth;
    u32 Pad3;
};

struct camera_data
{
    v3 P;
    f32 Aperture;
    v3 LookAt;
    f32 FocalDistance;
};

struct context_data
{
    f32 Time;
    i32 SampleCountSoFar;
    f32 AspectRatio;
    u32 Pad1;
    v2 RandSeed;
    u32 Pad2[2];
    
    mat4 View;
    mat4 Projection;
};

#pragma pack(pop)

struct dx_render_target
{
    ID3D11Texture2D *Tex;
    ID3D11RenderTargetView *RTV;
    ID3D11ShaderResourceView *SRV;
};

struct dx_renderer
{
    ID3D11Device1 *Device;
    ID3D11DeviceContext1 *DeviceContext;
    IDXGISwapChain1 *SwapChain;
    
#if CRAY_DEBUG
    ID3D11Debug *Debug;
    ID3D11InfoQueue *InfoQueue;
#endif
    
    ID3D11Texture2D *BackBuffer;
    ID3D11RenderTargetView *BackBufferView;
    
    dx_render_target SamplerBuffers[2];
    dx_render_target PositionBuffer;
    dx_render_target NormalBuffer;
    dx_render_target AlbedoBuffer;
    dx_render_target EmissionBuffer;
    ID3D11Texture2D *DepthStencilBuffer;
    ID3D11DepthStencilView *DepthStencilView;
    ID3D11DepthStencilState *DepthStencilState;
    ID3D11Texture2D *AutoFocusStagingTex; // for capturing camera center focal point
    
    // gpass
    ID3D11VertexShader *GPassVS;
    ID3D11PixelShader *GPassPS;
    ID3D11InputLayout *GPassInputLayout;
    
    // path tracer
    ID3D11VertexShader *FullscreenVS;
    ID3D11PixelShader *SamplePS;
    ID3D11PixelShader *OutputPS;
    
    ID3D11SamplerState *PointSampler;
    
    ID3D11RasterizerState1 *RasterizerState;
    
    ID3D11Buffer *VertexBuffer;
    int VertexCount;
    ID3D11Buffer *TriangleBuffer;
    ID3D11ShaderResourceView *TriangleBufferView;
    ID3D11Buffer *BVHBuffer;
    ID3D11ShaderResourceView *BVHBufferView;
    
    ID3D11Buffer *SettingsBuffer;
    ID3D11Buffer *CameraBuffer;
    ID3D11Buffer *ContextBuffer;
    
    render_settings OldSettings;
    render_settings Settings;
    camera_data Camera;
    context_data Context;
    b32 DoAutoFocus;
    int LastBufferIndex;
    int BufferIndex;
    int Width;
    int Height;
    f32 InitElapsedTime;
};
