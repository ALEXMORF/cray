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

internal dx_renderer
InitDXRenderer(HWND Window, camera *Camera)
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
    
    UINT CompilerFlags = D3DCOMPILE_ENABLE_STRICTNESS;
    CompilerFlags |= D3DCOMPILE_DEBUG;
    
    ID3DBlob *FullscreenVSCode = CompileDXShader(L"../code/fullscreen.hlsl", "main", "vs_5_0", CompilerFlags);
    ID3DBlob *SamplePSCode = CompileDXShader(L"../code/sample.hlsl", "main", "ps_5_0", CompilerFlags);
    Renderer.Device->CreateVertexShader(FullscreenVSCode->GetBufferPointer(), FullscreenVSCode->GetBufferSize(), 0, &Renderer.FullscreenVS);
    Renderer.Device->CreatePixelShader(SamplePSCode->GetBufferPointer(), SamplePSCode->GetBufferSize(), 0, &Renderer.SamplePS);
    
    D3D11_RASTERIZER_DESC1 RasterizerStateDesc = {};
    RasterizerStateDesc.FillMode = D3D11_FILL_SOLID;
    RasterizerStateDesc.CullMode = D3D11_CULL_NONE;
    RasterizerStateDesc.FrontCounterClockwise = true;
    HRESULT CreatedRasterizerState = Renderer.Device->CreateRasterizerState1(&RasterizerStateDesc, &Renderer.RasterizerState);
    ASSERT(SUCCEEDED(CreatedRasterizerState));
    
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
    
    Renderer.SettingsBuffer = CreateDynamicConstantBuffer(Renderer.Device, &Renderer.Settings, sizeof(Renderer.Settings));
    Renderer.CameraBuffer = CreateDynamicConstantBuffer(Renderer.Device, &Renderer.Camera, sizeof(Renderer.Camera));
    
    //NOTE(chen): set all states
    {   
        ID3D11DeviceContext *DeviceContext = Renderer.DeviceContext;
        
        ID3D11Buffer *ConstantBuffers[] = {
            Renderer.SettingsBuffer,
            Renderer.CameraBuffer,
        };
        DeviceContext->PSSetConstantBuffers(0, ARRAY_COUNT(ConstantBuffers), 
                                            ConstantBuffers);
        D3D11_TEXTURE2D_DESC RenderTargetDesc = {};
        Renderer.RenderTarget->GetDesc(&RenderTargetDesc);
        
        DeviceContext->IASetInputLayout(0);
        DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        DeviceContext->VSSetShader(Renderer.FullscreenVS, 0, 0);
        DeviceContext->PSSetShader(Renderer.SamplePS, 0, 0);
        
        D3D11_VIEWPORT Viewport = {};
        Viewport.Width = (f32)RenderTargetDesc.Width;
        Viewport.Height = (f32)RenderTargetDesc.Height;
        Viewport.MinDepth = 0.0f;
        Viewport.MaxDepth = 1.0f;
        DeviceContext->RSSetViewports(1, &Viewport);
        DeviceContext->RSSetState(Renderer.RasterizerState);
        DeviceContext->OMSetRenderTargets(1, &Renderer.RenderTargetView, 0);
    }
    
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

internal void
UploadModelToRenderer(dx_renderer *Renderer, loaded_model Model)
{
    ID3D11Device1 *Device = Renderer->Device;
    ID3D11DeviceContext1 *DeviceContext = Renderer->DeviceContext;
    
    SaveTempArenaOffset();
    {
        int PackedTriangleCount = Model.Triangles.Count; 
        packed_triangle *PackedTriangles = PushTempArray(PackedTriangleCount,
                                                         packed_triangle);
        for (int TriIndex = 0; TriIndex < PackedTriangleCount; ++TriIndex)
        {
            PackedTriangles[TriIndex] = Pack(Model.Triangles.Data[TriIndex]);
        }
        
        //NOTE(chen): must be 16-byte aligned
        ASSERT(sizeof(packed_triangle) % 16 == 0);
        
        D3D11_BUFFER_DESC TriangleBufferDesc = {};
        TriangleBufferDesc.ByteWidth = sizeof(packed_triangle) * PackedTriangleCount;
        TriangleBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
        TriangleBufferDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
        TriangleBufferDesc.CPUAccessFlags = 0;
        TriangleBufferDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
        TriangleBufferDesc.StructureByteStride = sizeof(packed_triangle);
        
        D3D11_SUBRESOURCE_DATA TriangleBufferData = {};
        TriangleBufferData.pSysMem = PackedTriangles;
        
        HRESULT CreatedTriangleBuffer = Device->CreateBuffer(&TriangleBufferDesc, &TriangleBufferData, &Renderer->TriangleBuffer);
        ASSERT(SUCCEEDED(CreatedTriangleBuffer));
        
        D3D11_SHADER_RESOURCE_VIEW_DESC TriangleBufferViewDesc = {};
        TriangleBufferViewDesc.Format = DXGI_FORMAT_UNKNOWN;
        TriangleBufferViewDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
        TriangleBufferViewDesc.Buffer.NumElements = PackedTriangleCount;
        HRESULT CreatedTriangleBufferView = Device->CreateShaderResourceView(
            Renderer->TriangleBuffer,
            &TriangleBufferViewDesc,
            &Renderer->TriangleBufferView);
        ASSERT(SUCCEEDED(CreatedTriangleBufferView));
    }
    RewindTempArenaToSavedOffset();
    
    SaveTempArenaOffset();
    {
        int PackedBVHCount = Model.BVH.Count; 
        packed_bvh_entry *PackedBVH = PushTempArray(PackedBVHCount,
                                                    packed_bvh_entry);
        for (int EntryIndex = 0; EntryIndex < PackedBVHCount; ++EntryIndex)
        {
            PackedBVH[EntryIndex] = Pack(Model.BVH.Data[EntryIndex]);
        }
        
        //NOTE(chen): must be 16-byte aligned
        ASSERT(sizeof(packed_bvh_entry) % 16 == 0);
        
        D3D11_BUFFER_DESC BVHBufferDesc = {};
        BVHBufferDesc.ByteWidth = sizeof(packed_bvh_entry) * PackedBVHCount;
        BVHBufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
        BVHBufferDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
        BVHBufferDesc.CPUAccessFlags = 0;
        BVHBufferDesc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
        BVHBufferDesc.StructureByteStride = sizeof(packed_bvh_entry);
        
        D3D11_SUBRESOURCE_DATA BVHBufferData = {};
        BVHBufferData.pSysMem = PackedBVH;
        
        HRESULT CreatedBVHBuffer = Device->CreateBuffer(&BVHBufferDesc, &BVHBufferData, &Renderer->BVHBuffer);
        ASSERT(SUCCEEDED(CreatedBVHBuffer));
        
        D3D11_SHADER_RESOURCE_VIEW_DESC BVHBufferViewDesc = {};
        BVHBufferViewDesc.Format = DXGI_FORMAT_UNKNOWN;
        BVHBufferViewDesc.ViewDimension = D3D11_SRV_DIMENSION_BUFFER;
        BVHBufferViewDesc.Buffer.NumElements = PackedBVHCount;
        HRESULT CreatedBVHBufferView = Device->CreateShaderResourceView(
            Renderer->BVHBuffer,
            &BVHBufferViewDesc,
            &Renderer->BVHBufferView);
        ASSERT(SUCCEEDED(CreatedBVHBufferView));
    }
    RewindTempArenaToSavedOffset();
    
    ID3D11ShaderResourceView *ResourceViews[] = {
        Renderer->TriangleBufferView,
        Renderer->BVHBufferView,
    };
    DeviceContext->PSSetShaderResources(0, ARRAY_COUNT(ResourceViews), ResourceViews);
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
    if (!Renderer->TriangleBufferView || !Renderer->BVHBufferView)
    {
        Panic("No triangle buffer or BVH buffer created");
    }
    
    ID3D11DeviceContext *DeviceContext = Renderer->DeviceContext;
    DeviceContext->Draw(3, 0);
}

internal void
Present(dx_renderer *Renderer)
{
    DXGI_PRESENT_PARAMETERS PresentParameters = {};
    Renderer->SwapChain->Present1(1, 0, &PresentParameters);
}