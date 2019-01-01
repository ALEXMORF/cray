internal ID3DBlob *
CompileDXShader(LPCWSTR Path, char *EntryPoint, char *Target, UINT Flags)
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

internal dx_renderer
InitDXRenderer(HWND Window, int Width, int Height)
{
    dx_renderer Renderer = {};
    
    ID3D11Device *TempDevice = 0;
    ID3D11DeviceContext *TempDeviceContext = 0;
    
    D3D_FEATURE_LEVEL FeatureLevels[] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    HRESULT CreatedDevice = D3D11CreateDevice(0, 
                                              D3D_DRIVER_TYPE_HARDWARE,
                                              0, D3D11_CREATE_DEVICE_DEBUG|D3D11_CREATE_DEVICE_BGRA_SUPPORT,
                                              FeatureLevels, ARRAY_COUNT(FeatureLevels),
                                              D3D11_SDK_VERSION, &TempDevice,
                                              0, &TempDeviceContext);
    ASSERT(SUCCEEDED(CreatedDevice));
    
    TempDevice->QueryInterface(IID_PPV_ARGS(&Renderer.Device));
    TempDeviceContext->QueryInterface(IID_PPV_ARGS(&Renderer.DeviceContext));
    
    IDXGIFactory2 *Factory = 0;
    IDXGIDevice1 *DXGIDevice = 0;
    IDXGIAdapter *Adapter = 0;
    Renderer.Device->QueryInterface(IID_PPV_ARGS(&DXGIDevice));
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
    HRESULT CreatedSwapChain = Factory->CreateSwapChainForHwnd(Renderer.Device, 
                                                               Window, &SwapChainDesc,
                                                               0, 0, &Renderer.SwapChain);
    ASSERT(SUCCEEDED(CreatedSwapChain));
    
    Renderer.SwapChain->GetBuffer(0, IID_PPV_ARGS(&Renderer.RenderTarget));
    Renderer.Device->CreateRenderTargetView(Renderer.RenderTarget,
                                            0, &Renderer.RenderTargetView);
    
    UINT DebugCompilerFlags = D3DCOMPILE_DEBUG|D3DCOMPILE_ENABLE_STRICTNESS;
    
    ID3DBlob *FullscreenVSCode = CompileDXShader(L"../code/fullscreen.hlsl", "main", "vs_5_0", DebugCompilerFlags);
    ID3DBlob *SamplePSCode = CompileDXShader(L"../code/sample.hlsl", "main", "ps_5_0", DebugCompilerFlags);
    Renderer.Device->CreateVertexShader(FullscreenVSCode->GetBufferPointer(), FullscreenVSCode->GetBufferSize(), 0, &Renderer.FullscreenVS);
    Renderer.Device->CreatePixelShader(SamplePSCode->GetBufferPointer(), SamplePSCode->GetBufferSize(), 0, &Renderer.SamplePS);
    
    D3D11_RASTERIZER_DESC1 RasterizerStateDesc = {};
    RasterizerStateDesc.FillMode = D3D11_FILL_SOLID;
    RasterizerStateDesc.CullMode = D3D11_CULL_NONE;
    RasterizerStateDesc.FrontCounterClockwise = true;
    HRESULT CreatedRasterizerState = Renderer.Device->CreateRasterizerState1(&RasterizerStateDesc, &Renderer.RasterizerState);
    ASSERT(SUCCEEDED(CreatedRasterizerState));
    
    return Renderer;
}

internal void
UploadModelToRenderer(dx_renderer *Renderer, loaded_model Model)
{
    //Panic("No UploadModelToRenderer yet");
}

internal void
Refresh(dx_renderer *Renderer)
{
    //Panic("No refresh yet");
}

internal void
ResizeResources(dx_renderer *Renderer, int NewWidth, int NewHeight)
{
    //Panic("No resize resource yet");
}

internal void
Render(dx_renderer *Renderer, camera *Camera, f32 T)
{
    D3D11_TEXTURE2D_DESC RenderTargetDesc = {};
    Renderer->RenderTarget->GetDesc(&RenderTargetDesc);
    
    ID3D11DeviceContext *DeviceContext = Renderer->DeviceContext;
    
    DeviceContext->IASetInputLayout(0);
    DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    DeviceContext->VSSetShader(Renderer->FullscreenVS, 0, 0);
    DeviceContext->PSSetShader(Renderer->SamplePS, 0, 0);
    
    D3D11_VIEWPORT Viewport = {};
    Viewport.Width = (f32)RenderTargetDesc.Width;
    Viewport.Height = (f32)RenderTargetDesc.Height;
    Viewport.MinDepth = 0.0f;
    Viewport.MaxDepth = 1.0f;
    DeviceContext->RSSetViewports(1, &Viewport);
    DeviceContext->RSSetState(Renderer->RasterizerState);
    DeviceContext->OMSetRenderTargets(1, &Renderer->RenderTargetView, 0);
    
    DeviceContext->Draw(3, 0);
}

internal void
Present(dx_renderer *Renderer)
{
    DXGI_PRESENT_PARAMETERS PresentParameters = {};
    Renderer->SwapChain->Present1(1, 0, &PresentParameters);
}