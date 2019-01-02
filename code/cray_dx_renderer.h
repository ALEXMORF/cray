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
#pragma pack(pop)

#pragma pack(push, 1)
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
#pragma pack(pop)

struct render_settings
{
    f32 Exposure;
    f32 FOV;
    b32 RasterizeFirstBounce;
    i32 MaxBounceCount;
    b32 EnableGroundPlane;
    
    v3 L;
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
    u32 Pad1;
    v3 LookAt;
    u32 Pad2;
};

struct context_data
{
    f32 Time;
    i32 SampleCountSoFar;
    f32 AspectRatio;
    u32 Pad;
};

struct dx_renderer
{
    ID3D11Device1 *Device;
    ID3D11DeviceContext1 *DeviceContext;
    IDXGISwapChain1 *SwapChain;
    ID3D11Texture2D *BackBuffer;
    ID3D11RenderTargetView *BackBufferView;
    ID3D11Texture2D *SamplerBuffers[2];
    ID3D11RenderTargetView *SamplerBufferViews[2];
    
    ID3D11VertexShader *FullscreenVS;
    ID3D11PixelShader *SamplePS;
    ID3D11RasterizerState1 *RasterizerState;
    
    ID3D11Buffer *TriangleBuffer;
    ID3D11ShaderResourceView *TriangleBufferView;
    ID3D11Buffer *BVHBuffer;
    ID3D11ShaderResourceView *BVHBufferView;
    
    ID3D11Buffer *SettingsBuffer;
    ID3D11Buffer *CameraBuffer;
    ID3D11Buffer *ContextBuffer;
    
    render_settings Settings;
    camera_data Camera;
    context_data Context;
    int BufferIndex;
};
