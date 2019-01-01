#pragma once
#include <d3d11.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>

struct dx_renderer
{
    ID3D11Device1 *Device;
    ID3D11DeviceContext1 *DeviceContext;
    IDXGISwapChain1 *SwapChain;
    ID3D11Texture2D *RenderTarget;
    ID3D11RenderTargetView *RenderTargetView;
    
    ID3D11VertexShader *FullscreenVS;
    ID3D11PixelShader *SamplePS;
    ID3D11RasterizerState1 *RasterizerState;
};
