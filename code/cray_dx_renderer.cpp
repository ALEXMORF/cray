#include <imgui_impl_dx11.cpp>
//#include "cray_hlsl_code.h"

internal ID3DBlob *
CompileDXShaderFromFile(LPCWSTR Path, char *EntryPoint, char *Target, UINT Flags)
{
    ID3DBlob *CompiledCode = 0;
    
    ID3DBlob *ShaderError = 0;
    HRESULT CompiledShader = D3DCompileFromFile(Path, 0,
                                                0, EntryPoint, 
                                                Target, Flags, 
                                                0, &CompiledCode, 
                                                &ShaderError);
    if (FAILED(CompiledShader))
    {
        Panic("%s Error: %s", Target, (char *)ShaderError->GetBufferPointer());
    }
    
    return CompiledCode;
}

internal ID3DBlob *
CompileDXShader(char *Name, char *SourceCode, 
                char *EntryPoint, char *Target, UINT Flags)
{
    ID3DBlob *CompiledCode = 0;
    
    ID3DBlob *ShaderError = 0;
    HRESULT CompiledShader = D3DCompile(SourceCode, 
                                        strlen(SourceCode), 
                                        Name, 0, 0, 
                                        EntryPoint, Target,
                                        Flags, 0, &CompiledCode,
                                        &ShaderError);
    if (FAILED(CompiledShader))
    {
        Panic("%s Error: %s", Target, (char *)ShaderError->GetBufferPointer());
    }
    
    return CompiledCode;
}

internal ID3D11VertexShader *
CreateDXVS(ID3D11Device1 *Device, char *Name, char *SourceCode,
           char *EntryPoint, UINT CompilerFlags)
{
    ID3D11VertexShader *VS = 0;
    
    ID3DBlob *VSCode = CompileDXShader(Name, SourceCode, EntryPoint, 
                                       "vs_5_0", CompilerFlags);
    HRESULT CreatedShader = Device->CreateVertexShader(VSCode->GetBufferPointer(), 
                                                       VSCode->GetBufferSize(), 0, &VS);
    ASSERT(SUCCEEDED(CreatedShader));
    VSCode->Release();
    
    return VS;
}

internal ID3D11PixelShader *
CreateDXPS(ID3D11Device1 *Device, char *Name, char *SourceCode,
           char *EntryPoint, UINT CompilerFlags)
{
    ID3D11PixelShader *PS = 0;
    
    ID3DBlob *PSCode = CompileDXShader(Name, SourceCode, EntryPoint, 
                                       "ps_5_0", CompilerFlags);
    HRESULT CreatedShader = Device->CreatePixelShader(PSCode->GetBufferPointer(), 
                                                      PSCode->GetBufferSize(), 0, &PS);
    ASSERT(SUCCEEDED(CreatedShader));
    PSCode->Release();
    
    return PS;
}

internal ID3D11Buffer *
CreateDynamicConstantBuffer(ID3D11Device1 *Device, void *Data, UINT DataSize)
{
    ID3D11Buffer *Buffer = 0;
    
    D3D11_BUFFER_DESC BufferDesc = {};
    BufferDesc.ByteWidth = DataSize;
    BufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    BufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    
    D3D11_SUBRESOURCE_DATA InitialData = {};
    InitialData.pSysMem = Data;
    
    HRESULT CreatedBuffer = Device->CreateBuffer(&BufferDesc, &InitialData, &Buffer);
    ASSERT(SUCCEEDED(CreatedBuffer));
    
    return Buffer;
}

internal dx_render_target
CreateDXRenderTarget(ID3D11Device1 *Device, int Width, int Height, 
                     DXGI_FORMAT Format)
{
    dx_render_target RenderTarget = {};
    
    D3D11_TEXTURE2D_DESC TextureDesc = {};
    TextureDesc.Width = Width;
    TextureDesc.Height = Height;
    TextureDesc.MipLevels = 1;
    TextureDesc.ArraySize = 1;
    TextureDesc.Format = Format;
    TextureDesc.SampleDesc.Count = 1;
    TextureDesc.SampleDesc.Quality = 0;
    TextureDesc.Usage = D3D11_USAGE_DEFAULT;
    TextureDesc.BindFlags = D3D11_BIND_RENDER_TARGET|D3D11_BIND_SHADER_RESOURCE;
    TextureDesc.CPUAccessFlags = 0;
    TextureDesc.MiscFlags = 0;
    
    HRESULT CreatedTexture = Device->CreateTexture2D(&TextureDesc, 0, 
                                                     &RenderTarget.Tex);
    ASSERT(SUCCEEDED(CreatedTexture));
    
    HRESULT CreatedRTV = Device->CreateRenderTargetView(RenderTarget.Tex, 
                                                        0, &RenderTarget.RTV);
    ASSERT(SUCCEEDED(CreatedRTV));
    
    HRESULT CreatedRV = Device->CreateShaderResourceView(RenderTarget.Tex, 0, 
                                                         &RenderTarget.SRV);
    ASSERT(SUCCEEDED(CreatedRV));
    
    return RenderTarget;
}

internal void
Release(dx_render_target *RenderTarget)
{
    RenderTarget->Tex->Release();
    RenderTarget->RTV->Release();
    RenderTarget->SRV->Release();
    
    *RenderTarget = {};
}

internal void
Refresh(dx_renderer *Renderer)
{
    Renderer->Context.SampleCountSoFar = 0;
}

internal void
CreateWindowSizeCoupledResources(dx_renderer *Renderer)
{
    ID3D11Device1 *Device = Renderer->Device;
    
    HRESULT GotBackBuffer = Renderer->SwapChain->GetBuffer(0, IID_PPV_ARGS(&Renderer->BackBuffer));
    ASSERT(SUCCEEDED(GotBackBuffer));
    HRESULT CreatedBackBufferRTV = Device->CreateRenderTargetView(Renderer->BackBuffer,
                                                                  0, &Renderer->BackBufferView);
    ASSERT(SUCCEEDED(CreatedBackBufferRTV));
    
    D3D11_TEXTURE2D_DESC BackBufferDesc = {};
    Renderer->BackBuffer->GetDesc(&BackBufferDesc);
    int ClientWidth = BackBufferDesc.Width;
    int ClientHeight = BackBufferDesc.Height;
    
    for (int BufferIndex = 0; BufferIndex < 2; ++BufferIndex)
    {
        Renderer->SamplerBuffers[BufferIndex] = CreateDXRenderTarget(
            Device, ClientWidth, ClientHeight, 
            DXGI_FORMAT_R16G16B16A16_FLOAT);
    }
    Renderer->PositionBuffer = CreateDXRenderTarget(Device, 
                                                    ClientWidth, ClientHeight,
                                                    DXGI_FORMAT_R16G16B16A16_FLOAT);
    Renderer->NormalBuffer = CreateDXRenderTarget(Device, 
                                                  ClientWidth, ClientHeight,
                                                  DXGI_FORMAT_R16G16B16A16_FLOAT);
    //TODO(chen): compress these when we have a material system in place
    Renderer->AlbedoBuffer = CreateDXRenderTarget(Device, 
                                                  ClientWidth, ClientHeight,
                                                  DXGI_FORMAT_B8G8R8A8_UNORM);
    Renderer->EmissionBuffer = CreateDXRenderTarget(Device, 
                                                    ClientWidth, ClientHeight,
                                                    DXGI_FORMAT_R16G16B16A16_FLOAT);
    
    // depth stencil buffer
    {
        D3D11_TEXTURE2D_DESC DepthStencilBufferDesc = {};
        DepthStencilBufferDesc.Width = ClientWidth;
        DepthStencilBufferDesc.Height = ClientHeight;
        DepthStencilBufferDesc.MipLevels = 1;
        DepthStencilBufferDesc.ArraySize = 1;
        DepthStencilBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        DepthStencilBufferDesc.SampleDesc.Count = 1;
        DepthStencilBufferDesc.SampleDesc.Quality = 0;
        DepthStencilBufferDesc.Usage = D3D11_USAGE_DEFAULT;
        DepthStencilBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
        
        HRESULT CreatedDepthStencil = Device->CreateTexture2D(&DepthStencilBufferDesc, 0, &Renderer->DepthStencilBuffer);
        ASSERT(SUCCEEDED(CreatedDepthStencil));
        
        D3D11_DEPTH_STENCIL_VIEW_DESC DepthStencilViewDesc = {};
        DepthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        DepthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
        HRESULT CreatedDepthStencilView = Device->CreateDepthStencilView(Renderer->DepthStencilBuffer, &DepthStencilViewDesc, &Renderer->DepthStencilView);
        ASSERT(SUCCEEDED(CreatedDepthStencilView));
    }
}

internal void
SetViewport(dx_renderer *Renderer, int Width, int Height)
{
    D3D11_VIEWPORT Viewport = {};
    Viewport.Width = (f32)Width;
    Viewport.Height = (f32)Height;
    Viewport.MinDepth = 0.0f;
    Viewport.MaxDepth = 1.0f;
    Renderer->DeviceContext->RSSetViewports(1, &Viewport);
}

internal void
SetPersistentStates(dx_renderer *Renderer, int Width, int Height)
{   
    ID3D11DeviceContext1 *DeviceContext = Renderer->DeviceContext;
    
    ID3D11Buffer *ConstantBuffers[] = {
        Renderer->SettingsBuffer,
        Renderer->CameraBuffer,
        Renderer->ContextBuffer,
    };
    DeviceContext->VSSetConstantBuffers(0, ARRAY_COUNT(ConstantBuffers), 
                                        ConstantBuffers);
    DeviceContext->PSSetConstantBuffers(0, ARRAY_COUNT(ConstantBuffers), 
                                        ConstantBuffers);
    DeviceContext->IASetInputLayout(0);
    DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    DeviceContext->VSSetShader(Renderer->FullscreenVS, 0, 0);
    
    DeviceContext->PSSetSamplers(0, 1, &Renderer->NearestSampler);
    
    SetViewport(Renderer, Width, Height);
    DeviceContext->RSSetState(Renderer->RasterizerState);
}

internal dx_renderer
InitDXRenderer(HWND Window, camera *Camera, int Width, int Height)
{
    
    
    dx_renderer Renderer = {};
    Renderer.Width = Width;
    Renderer.Height = Height;
    
    clock_t BeginClock = clock();
    
    ID3D11Device *TempDevice = 0;
    ID3D11DeviceContext *TempDeviceContext = 0;
    
    D3D_FEATURE_LEVEL FeatureLevels[] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    UINT DeviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if CRAY_DEBUG
    DeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
    HRESULT CreatedDevice = D3D11CreateDevice(0, 
                                              D3D_DRIVER_TYPE_HARDWARE,
                                              0, DeviceFlags,
                                              FeatureLevels, ARRAY_COUNT(FeatureLevels),
                                              D3D11_SDK_VERSION, &TempDevice,
                                              0, &TempDeviceContext);
    ASSERT(SUCCEEDED(CreatedDevice));
    
    TempDevice->QueryInterface(IID_PPV_ARGS(&Renderer.Device));
    TempDeviceContext->QueryInterface(IID_PPV_ARGS(&Renderer.DeviceContext));
    
#if CRAY_DEBUG
    HRESULT GotDebug = Renderer.Device->QueryInterface(IID_PPV_ARGS(&Renderer.Debug));
    ASSERT(SUCCEEDED(GotDebug));
    HRESULT GotInfoQueue = Renderer.Debug->QueryInterface(IID_PPV_ARGS(&Renderer.InfoQueue));
    ASSERT(SUCCEEDED(GotInfoQueue));
    
    HRESULT TurnedOn = S_OK;
    TurnedOn = Renderer.InfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_CORRUPTION, true);
    ASSERT(SUCCEEDED(TurnedOn));
    TurnedOn = Renderer.InfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_ERROR, true);
    ASSERT(SUCCEEDED(TurnedOn));
    TurnedOn = Renderer.InfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_WARNING, true);
    ASSERT(SUCCEEDED(TurnedOn));
    TurnedOn = Renderer.InfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_INFO, true);
    ASSERT(SUCCEEDED(TurnedOn));
    TurnedOn = Renderer.InfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_MESSAGE, true);
    ASSERT(SUCCEEDED(TurnedOn));
#endif
    
    ID3D11Device1 *Device = Renderer.Device;
    ID3D11DeviceContext1 *DeviceContext = Renderer.DeviceContext;
    
    IDXGIFactory2 *Factory = 0;
    IDXGIDevice1 *DXGIDevice = 0;
    IDXGIAdapter *Adapter = 0;
    Device->QueryInterface(IID_PPV_ARGS(&DXGIDevice));
    DXGIDevice->GetAdapter(&Adapter);
    Adapter->GetParent(IID_PPV_ARGS(&Factory));
    
    DXGI_SWAP_CHAIN_DESC1 SwapChainDesc = {};
    SwapChainDesc.Width = 0; // use window width
    SwapChainDesc.Height = 0; // use window height
    SwapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
    SwapChainDesc.Stereo = false;
    SwapChainDesc.SampleDesc.Count = 1;
    SwapChainDesc.SampleDesc.Quality = 0;
    SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    SwapChainDesc.BufferCount = 2;
    SwapChainDesc.Scaling = DXGI_SCALING_STRETCH;
    SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    SwapChainDesc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
    SwapChainDesc.Flags = 0;
    HRESULT CreatedSwapChain = Factory->CreateSwapChainForHwnd(Device, 
                                                               Window, &SwapChainDesc,
                                                               0, 0, &Renderer.SwapChain);
    ASSERT(SUCCEEDED(CreatedSwapChain));
    
    CreateWindowSizeCoupledResources(&Renderer);
    
    D3D11_DEPTH_STENCIL_DESC DepthStencilDesc = {};
    DepthStencilDesc.DepthEnable = true;
    DepthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
    DepthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
    DepthStencilDesc.StencilEnable = false;
    HRESULT CreatedDepthStencilState = Device->CreateDepthStencilState(&DepthStencilDesc, &Renderer.DepthStencilState);
    ASSERT(SUCCEEDED(CreatedDepthStencilState));
    
#if CRAY_DEBUG
    UINT CompilerFlags = D3DCOMPILE_DEBUG;
#else
    UINT CompilerFlags = D3DCOMPILE_OPTIMIZATION_LEVEL3;
#endif
    
    char *gpass = ReadFile("../code/gpass.hlsl");
    char *fullscreen = ReadFile("../code/fullscreen.hlsl");
    char *sample = ReadFile("../code/sample.hlsl");
    char *output = ReadFile("../code/output.hlsl");
    
    // create GPass shaders and its input layout
    {
        ID3DBlob *GPassVSCode = CompileDXShader("gpass.hlsl", gpass, 
                                                "vsmain", "vs_5_0", CompilerFlags);
        Device->CreateVertexShader(GPassVSCode->GetBufferPointer(), 
                                   GPassVSCode->GetBufferSize(), 0, &Renderer.GPassVS);
        
        D3D11_INPUT_ELEMENT_DESC InputLayoutDesc[] =
        {
            {"POS", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, 
                D3D11_INPUT_PER_VERTEX_DATA, 0 },
            {"NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 
                D3D11_APPEND_ALIGNED_ELEMENT, 
                D3D11_INPUT_PER_VERTEX_DATA, 0 },
            {"ALBEDO", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 
                D3D11_APPEND_ALIGNED_ELEMENT, 
                D3D11_INPUT_PER_VERTEX_DATA, 0 },
            {"EMISSION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 
                D3D11_APPEND_ALIGNED_ELEMENT, 
                D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };
        HRESULT CreatedInputLayout = Device->CreateInputLayout(
            InputLayoutDesc, 
            ARRAY_COUNT(InputLayoutDesc),
            GPassVSCode->GetBufferPointer(),
            GPassVSCode->GetBufferSize(),
            &Renderer.GPassInputLayout);
        ASSERT(SUCCEEDED(CreatedInputLayout));
        
        GPassVSCode->Release();
        
        Renderer.GPassPS = CreateDXPS(Device, "gpass.hlsl", gpass, "psmain", CompilerFlags);
    }
    
    Renderer.FullscreenVS = CreateDXVS(Device, "fullscreen.hlsl", fullscreen, "main", CompilerFlags);
    Renderer.SamplePS = CreateDXPS(Device, "sample.hlsl", sample, "main", CompilerFlags);
    Renderer.OutputPS = CreateDXPS(Device, "output.hlsl", output, "main", CompilerFlags);
    
    D3D11_SAMPLER_DESC NearestSamplerDesc = {};
    NearestSamplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
    NearestSamplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
    NearestSamplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
    NearestSamplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    NearestSamplerDesc.MipLODBias = 0;
    NearestSamplerDesc.MaxAnisotropy = 1;
    NearestSamplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    NearestSamplerDesc.MinLOD = 0.0f;
    NearestSamplerDesc.MaxLOD = 0.0f;
    HRESULT CreatedNearestSampler = Device->CreateSamplerState(&NearestSamplerDesc, &Renderer.NearestSampler);
    ASSERT(SUCCEEDED(CreatedNearestSampler));
    
    D3D11_RASTERIZER_DESC1 RasterizerStateDesc = {};
    RasterizerStateDesc.FillMode = D3D11_FILL_SOLID;
    RasterizerStateDesc.CullMode = D3D11_CULL_NONE;
    RasterizerStateDesc.FrontCounterClockwise = true;
    HRESULT CreatedRasterizerState = Device->CreateRasterizerState1(&RasterizerStateDesc, &Renderer.RasterizerState);
    ASSERT(SUCCEEDED(CreatedRasterizerState));
    
    D3D11_TEXTURE2D_DESC BackBufferDesc = {};
    Renderer.BackBuffer->GetDesc(&BackBufferDesc);
    int ClientWidth = BackBufferDesc.Width;
    int ClientHeight = BackBufferDesc.Height;
    
    Renderer.Settings.Exposure = 0.5f;
    Renderer.Settings.FOV = DegreeToRadian(45.0f);
    Renderer.Settings.RasterizeFirstBounce = false;
    Renderer.Settings.EnableGroundPlane = true;
    Renderer.Settings.MaxBounceCount = 2;
    Renderer.Settings.L = {0.5f, 0.4f, -0.5f};
    Renderer.Settings.SunRadiance = V3(4.0f);
    Renderer.Settings.Zenith = {0.0f, 0.44f, 2.66f};
    Renderer.Settings.Azimuth = {1.0f, 1.4f, 1.6f};
    Renderer.Camera.P = Camera->P;
    Renderer.Camera.LookAt = Camera->LookAt;
    Renderer.Context.AspectRatio = (f32)ClientWidth / (f32)ClientHeight;
    
    Renderer.SettingsBuffer = CreateDynamicConstantBuffer(Device, &Renderer.Settings, sizeof(Renderer.Settings));
    Renderer.CameraBuffer = CreateDynamicConstantBuffer(Device, &Renderer.Camera, sizeof(Renderer.Camera));
    Renderer.ContextBuffer = CreateDynamicConstantBuffer(Device, &Renderer.Context, sizeof(Renderer.Context));
    
    SetPersistentStates(&Renderer, ClientWidth, ClientHeight);
    
    ImGui::CreateContext();
    ImGui::GetIO().RenderDrawListsFn = ImGui_ImplDX11_RenderDrawData;
    ImGui_ImplDX11_Init(Device, DeviceContext);
    
    Renderer.BufferIndex = 0;
    Renderer.LastBufferIndex = 1;
    
    Renderer.InitElapsedTime = CalcSecondsPassed(BeginClock);
    
    return Renderer;
}

inline packed_triangle
Pack(triangle Triangle)
{
    packed_triangle PackedTriangle = {};
    
    PackedTriangle.A = Triangle.A;
    PackedTriangle.B = Triangle.B;
    PackedTriangle.C = Triangle.C;
    PackedTriangle.N = Triangle.N;
    PackedTriangle.Albedo = Triangle.Albedo;
    PackedTriangle.Emission = Triangle.Emission;
    
    return PackedTriangle;
}

inline packed_bvh_entry
Pack(bvh_entry BVHEntry)
{
    packed_bvh_entry PackedBVHEntry = {};
    
    PackedBVHEntry.BoundMin = BVHEntry.BoundMin;
    PackedBVHEntry.BoundMax = BVHEntry.BoundMax;
    PackedBVHEntry.PrimitiveOffset = BVHEntry.PrimitiveOffset;
    PackedBVHEntry.PrimitiveCount = BVHEntry.PrimitiveCount;
    PackedBVHEntry.Axis = BVHEntry.Axis;
    
    return PackedBVHEntry;
}

internal ID3D11Buffer *
CreateStructuredBuffer(ID3D11Device1 *Device, void *Data, 
                       int ElementCount, int Stride,
                       ID3D11ShaderResourceView **BufferView_Out)
{
    ID3D11Buffer *Buffer = 0;
    
    //NOTE(chen): must be 16-byte aligned
    ASSERT(Stride % 16 == 0);
    
    D3D11_BUFFER_DESC BufferDesc = {};
    BufferDesc.ByteWidth = ElementCount * Stride;
    BufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
    BufferDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    BufferDesc.CPUAccessFlags = 0;
    BufferDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
    BufferDesc.StructureByteStride = Stride;
    
    D3D11_SUBRESOURCE_DATA BufferData = {};
    BufferData.pSysMem = Data;
    
    HRESULT CreatedBuffer = Device->CreateBuffer(&BufferDesc, &BufferData, &Buffer);
    ASSERT(SUCCEEDED(CreatedBuffer));
    
    D3D11_SHADER_RESOURCE_VIEW_DESC BufferViewDesc = {};
    BufferViewDesc.Format = DXGI_FORMAT_UNKNOWN;
    BufferViewDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
    BufferViewDesc.Buffer.NumElements = ElementCount;
    HRESULT CreatedBufferView = Device->CreateShaderResourceView(Buffer, &BufferViewDesc, BufferView_Out);
    ASSERT(SUCCEEDED(CreatedBufferView));
    
    return Buffer;
}

internal void
UploadModelToRenderer(dx_renderer *Renderer, loaded_model Model)
{
    if (Renderer->TriangleBuffer || Renderer->BVHBuffer ||
        Renderer->VertexBuffer)
    {
        Renderer->TriangleBufferView->Release();
        Renderer->TriangleBuffer->Release();
        Renderer->BVHBufferView->Release();
        Renderer->BVHBuffer->Release();
        Renderer->VertexBuffer->Release();
        
        Refresh(Renderer);
    }
    
    ID3D11Device1 *Device = Renderer->Device;
    ID3D11DeviceContext1 *DeviceContext = Renderer->DeviceContext;
    
    // upload packed triangles
    {
        packed_triangle *PackedTriangles = BufInit(BufCount(Model.Triangles), packed_triangle);
        for (int TriIndex = 0; TriIndex < BufCount(PackedTriangles); ++TriIndex)
        {
            PackedTriangles[TriIndex] = Pack(Model.Triangles[TriIndex]);
        }
        
        Renderer->TriangleBuffer = CreateStructuredBuffer(Device, PackedTriangles, 
                                                          (int)BufCount(PackedTriangles),
                                                          sizeof(packed_triangle),
                                                          &Renderer->TriangleBufferView);
        
        BufFree(PackedTriangles);
    }
    
    // upload packed BVH
    {
        packed_bvh_entry *PackedBVH = BufInit(BufCount(Model.BVH), packed_bvh_entry);
        for (int EntryIndex = 0; EntryIndex < BufCount(PackedBVH); ++EntryIndex)
        {
            PackedBVH[EntryIndex] = Pack(Model.BVH[EntryIndex]);
        }
        
        Renderer->BVHBuffer = CreateStructuredBuffer(Device, PackedBVH, 
                                                     (int)BufCount(PackedBVH),
                                                     sizeof(packed_bvh_entry),
                                                     &Renderer->BVHBufferView);
        
        BufFree(PackedBVH);
    }
    
    ID3D11ShaderResourceView *ResourceViews[] = {
        Renderer->TriangleBufferView,
        Renderer->BVHBufferView,
    };
    DeviceContext->PSSetShaderResources(0, ARRAY_COUNT(ResourceViews), ResourceViews);
    
    D3D11_BUFFER_DESC VertexBufferDesc = {};
    VertexBufferDesc.ByteWidth = sizeof(vertex) * (int)BufCount(Model.Vertices);
    VertexBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
    VertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    D3D11_SUBRESOURCE_DATA VertexBufferData = {};
    VertexBufferData.pSysMem = Model.Vertices;
    HRESULT CreatedVertexBuffer = Device->CreateBuffer(&VertexBufferDesc, &VertexBufferData, &Renderer->VertexBuffer);
    ASSERT(SUCCEEDED(CreatedVertexBuffer));
    Renderer->VertexCount = (int)BufCount(Model.Vertices);
}

internal void
UpdateBuffer(ID3D11DeviceContext1 *DeviceContext, ID3D11Buffer *Buffer, void *Data, size_t DataSize)
{
    D3D11_MAPPED_SUBRESOURCE MappedResource = {};
    HRESULT ResourceIsMapped = DeviceContext->Map(Buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &MappedResource);
    ASSERT(SUCCEEDED(ResourceIsMapped));
    memcpy(MappedResource.pData, Data, DataSize);
    DeviceContext->Unmap(Buffer, 0);
}

//NOTE(chen): this is for determining if samples need to be refreshed
internal b32
NeedsRefresh(render_settings Old, render_settings New)
{
    b32 Result = false;
    
    Result = Result || Old.FOV != New.FOV;
    Result = Result || Old.RasterizeFirstBounce != New.RasterizeFirstBounce;
    Result = Result || Old.MaxBounceCount != New.MaxBounceCount;
    Result = Result || Old.EnableGroundPlane != New.EnableGroundPlane;
    Result = Result || Old.L != New.L;
    Result = Result || Old.SunRadiance != New.SunRadiance;
    Result = Result || Old.Zenith != New.Zenith;
    Result = Result || Old.Azimuth != New.Azimuth;
    
    return Result;
}

bool operator==(render_settings A, render_settings B)
{
    return memcpy(&A, &B, sizeof(A)) == 0;
}
bool operator!=(render_settings A, render_settings B)
{
    return !(A == B);
}

internal void
RefreshCamera(dx_renderer *Renderer, camera *Camera)
{
    Renderer->Camera.P = Camera->P;
    Renderer->Camera.LookAt = Camera->LookAt;
    UpdateBuffer(Renderer->DeviceContext, Renderer->CameraBuffer, 
                 &Renderer->Camera, sizeof(Renderer->Camera));
    Refresh(Renderer);
}

internal void
ResizeResources(dx_renderer *Renderer, int NewWidth, int NewHeight)
{
    ASSERT(NewWidth != Renderer->Width || NewHeight != Renderer->Height);
    
    Renderer->Width = NewWidth;
    Renderer->Height = NewHeight;
    
    // release screen-size coupled resources
    Renderer->BackBuffer->Release();
    Renderer->BackBufferView->Release();
    for (int I = 0; I < ARRAY_COUNT(Renderer->SamplerBuffers); ++I)
    {
        Release(&Renderer->SamplerBuffers[I]);
    }
    Release(&Renderer->PositionBuffer);
    Release(&Renderer->NormalBuffer);
    Release(&Renderer->AlbedoBuffer);
    Release(&Renderer->EmissionBuffer);
    Renderer->DepthStencilBuffer->Release();
    Renderer->DepthStencilView->Release();
    
    HRESULT ResizedBackBuffers = Renderer->SwapChain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);
    if (FAILED(ResizedBackBuffers))
    {
        HRESULT DeviceRemovedReason = Renderer->Device->GetDeviceRemovedReason();
        ASSERT(!"Failed to resize back buffers");
    }
    
    CreateWindowSizeCoupledResources(Renderer);
    
    SetViewport(Renderer, NewWidth, NewHeight);
    Renderer->Context.AspectRatio = (f32)NewWidth / (f32)NewHeight;
    Refresh(Renderer);
}

internal void
Render(dx_renderer *Renderer, camera *Camera, f32 T)
{
    ID3D11DeviceContext1 *DeviceContext = Renderer->DeviceContext;
    
    context_data *Context = &Renderer->Context;
    Context->Time = T;
    Context->View = Transpose(Mat4LookAt(Camera->P, Camera->LookAt));
    Context->Projection = Transpose(Mat4PerspectiveDX(Renderer->Settings.FOV, Context->AspectRatio, 0.1f, 1000.0f));
    
    UpdateBuffer(DeviceContext, Renderer->ContextBuffer, 
                 &Renderer->Context, sizeof(Renderer->Context));
    if (Renderer->OldSettings != Renderer->Settings)
    {
        UpdateBuffer(Renderer->DeviceContext, Renderer->SettingsBuffer, 
                     &Renderer->Settings, sizeof(Renderer->Settings));
        Renderer->OldSettings = Renderer->Settings;
    }
    
    if (Renderer->Settings.RasterizeFirstBounce)
    {
        UINT VBStride = sizeof(vertex);
        UINT VBOffset = 0;
        DeviceContext->IASetVertexBuffers(0, 1, &Renderer->VertexBuffer, &VBStride, &VBOffset);
        DeviceContext->IASetInputLayout(Renderer->GPassInputLayout);
        DeviceContext->VSSetShader(Renderer->GPassVS, 0, 0);
        DeviceContext->PSSetShader(Renderer->GPassPS, 0, 0);
        
        f32 ClearRGBA[4] = {0.0f};
        DeviceContext->ClearRenderTargetView(Renderer->PositionBuffer.RTV, ClearRGBA);
        DeviceContext->ClearRenderTargetView(Renderer->NormalBuffer.RTV, ClearRGBA);
        DeviceContext->ClearRenderTargetView(Renderer->AlbedoBuffer.RTV, ClearRGBA);
        DeviceContext->ClearRenderTargetView(Renderer->EmissionBuffer.RTV, ClearRGBA);
        DeviceContext->ClearDepthStencilView(Renderer->DepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
        
        //NOTE(chen): unbind gbuffer's SRV so they can be used as output
        ID3D11ShaderResourceView *NullSRVs[] = {0, 0, 0, 0};
        DeviceContext->PSSetShaderResources(3, ARRAY_COUNT(NullSRVs), NullSRVs);
        
        ID3D11RenderTargetView *RenderTargetViews[] = {
            Renderer->PositionBuffer.RTV,
            Renderer->NormalBuffer.RTV,
            Renderer->AlbedoBuffer.RTV,
            Renderer->EmissionBuffer.RTV,
        };
        DeviceContext->OMSetDepthStencilState(Renderer->DepthStencilState, 0);
        DeviceContext->OMSetRenderTargets(ARRAY_COUNT(RenderTargetViews), RenderTargetViews, Renderer->DepthStencilView);
        ASSERT(Renderer->VertexCount != 0);
        DeviceContext->Draw(Renderer->VertexCount, 0);
        
        //NOTE(chen): unbind gbuffer's RTV so they can be used as shader resources
        DeviceContext->OMSetRenderTargets(0, 0, 0);
        
        ID3D11ShaderResourceView *GBufferViews[] = {
            Renderer->PositionBuffer.SRV,
            Renderer->NormalBuffer.SRV,
            Renderer->AlbedoBuffer.SRV,
            Renderer->EmissionBuffer.SRV,
        };
        DeviceContext->PSSetShaderResources(3, ARRAY_COUNT(GBufferViews), GBufferViews);
    }
    
    int BufferIndex = Renderer->BufferIndex;
    int LastBufferIndex = Renderer->LastBufferIndex;
    
    DeviceContext->IASetInputLayout(0);
    DeviceContext->VSSetShader(Renderer->FullscreenVS, 0, 0);
    
#if 0
    ID3D11ShaderResourceView *ResourceViews[] = {
        Renderer->TriangleBufferView,
        Renderer->BVHBufferView,
    };
    DeviceContext->PSSetShaderResources(0, ARRAY_COUNT(ResourceViews), ResourceViews);
#endif
    
    DeviceContext->PSSetShaderResources(2, 1, &Renderer->SamplerBuffers[LastBufferIndex].SRV);
    DeviceContext->PSSetShader(Renderer->SamplePS, 0, 0);
    DeviceContext->OMSetRenderTargets(1, &Renderer->SamplerBuffers[BufferIndex].RTV, 0);
    DeviceContext->Draw(3, 0);
    
    DeviceContext->PSSetShader(Renderer->OutputPS, 0, 0);
    DeviceContext->OMSetRenderTargets(1, &Renderer->BackBufferView, 0);
    DeviceContext->PSSetShaderResources(2, 1, &Renderer->SamplerBuffers[BufferIndex].SRV);
    DeviceContext->Draw(3, 0);
    
    Renderer->Context.SampleCountSoFar += 1;
    Renderer->LastBufferIndex = BufferIndex;
    Renderer->BufferIndex = (BufferIndex + 1) % 2;
}

internal void
Present(dx_renderer *Renderer)
{
    DXGI_PRESENT_PARAMETERS PresentParameters = {};
    HRESULT PresentedBackBuffer = Renderer->SwapChain->Present1(0, 0, &PresentParameters);
    if (FAILED(PresentedBackBuffer))
    {
        HRESULT DeviceRemovedReason = Renderer->Device->GetDeviceRemovedReason();
        ASSERT(!"Failed to present back buffer");
    }
}