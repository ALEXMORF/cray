internal void
UINewFrame(input *Input, int Width, int Height, f32 dT)
{
    ImGuiIO &IO = ImGui::GetIO();
    
    IO.DisplaySize.x = (f32)Width;
    IO.DisplaySize.y = (f32)Height;
    
    IO.DeltaTime = dT;
    IO.MousePos.x = (signed short)Input->MousePInPixels.X;
    IO.MousePos.y = (signed short)Input->MousePInPixels.Y;
    IO.MouseDown[0] = Input->MouseIsDown;
    //IO.MouseDown[1] = Bool(Input->Mouse.RightDown);
    //IO.KeyCtrl = Bool(Input->ControlKeyDown);
    
    for (int KeyCode = 0; KeyCode < ARRAY_COUNT(Input->Keys); ++KeyCode)
    {
        if (Input->Keys[KeyCode])
        {
            IO.KeysDown[KeyCode] = 1;
        }
        else
        {
            IO.KeysDown[KeyCode] = 0;
        }
    }
    
    ImGui_ImplDX11_NewFrame();
    ImGui::NewFrame();
    
    Input->KeyboardIsCaptured = IO.WantCaptureKeyboard;
    Input->MouseIsCaptured = IO.WantCaptureMouse;
}

struct value_with_unit
{
    f32 Count;
    char *Unit;
};

internal value_with_unit
CalcProperMemoryUnit(u64 Count)
{
    char *Units[] = {"B", "KB", "MB", "GB", "TB"};
    
    value_with_unit Value = {};
    
    Value.Count = (f32)Count;
    Value.Unit = Units[0];
    
    for (int UnitIndex = 1; UnitIndex < ARRAY_COUNT(Units); ++UnitIndex)
    {
        if (Value.Count / 1024.0f < 1.0f)
        {
            break;
        }
        
        Value.Count /= 1024.0f;
        Value.Unit = Units[UnitIndex];
    }
    
    return Value;
}

internal void
DoUI(cray *CRay, int Width, int Height, f32 dT)
{
    ImGui::Begin("CRay", 0, ImGuiWindowFlags_AlwaysAutoResize);
    
    ImGui::Text("DX Renderer Init time: %.3f seconds", CRay->Renderer.InitElapsedTime);
    ImGui::Text("Model Loading time: %.3f seconds", CRay->Model.ModelLoadingTime);
    ImGui::Text("BVH Construction time: %.3f seconds", CRay->Model.BvhConstructionTime);
    ImGui::Text("Triangle Count: %d", BufCount(CRay->Model.Triangles));
    ImGui::Text("Geometry Vertex Count: %d", BufCount(CRay->Model.Vertices));
    ImGui::Text("BVH Node Count: %d", BufCount(CRay->Model.BVH));
    ImGui::Text("Render time: %.3f miliseconds", 1000.0f*dT);
    {
        int PixelCount = Width * Height;
        int RayPerPixel = 2 * CRay->Renderer.Settings.MaxBounceCount;
        if (CRay->Renderer.Settings.RasterizeFirstBounce)
        {
            RayPerPixel -= 1;
        }
        f32 RaysPerSecond = (RayPerPixel * PixelCount) / dT;
        
        ImGui::Text("Rate of RT: %.3f Mrays/second", RaysPerSecond / 1000000.0f);
    }
    {
        value_with_unit PeekMemUsage = CalcProperMemoryUnit(GlobalTempArena.PeekUsed);
        value_with_unit MainArenaMemUsage = CalcProperMemoryUnit(CRay->MainArena.Used);
        ImGui::Text("Peek TempMemory Usage: %.2f%s", PeekMemUsage.Count, PeekMemUsage.Unit);
        ImGui::Text("Main Arena Usage: %.2f%s", MainArenaMemUsage.Count, MainArenaMemUsage.Unit);
    }
    ImGui::Text("malloc() call count: %d", GlobalMallocCallCount);
    
    ImGui::Separator();
    {
        render_settings *Settings = &CRay->Renderer.Settings;
        ImGui::Checkbox("Rasterize First Bounce", (bool *)&Settings->RasterizeFirstBounce);
        ImGui::Checkbox("Enable Ground Plane", (bool *)&Settings->EnableGroundPlane);
        ImGui::InputInt("Max Bounce Count", &Settings->MaxBounceCount);
        ImGui::InputFloat("FOV", &Settings->FOV, 0.01f);
        ImGui::DragFloat3("L", (f32 *)&Settings->L, 0.01f);
        
        int ColorEditFlags = ImGuiColorEditFlags_HDR;
        
        ImGui::ColorEdit3("Sun Radiance", (f32 *)&Settings->SunRadiance, ColorEditFlags);
        ImGui::ColorEdit3("Zenith", (f32 *)&Settings->Zenith, ColorEditFlags);
        ImGui::ColorEdit3("Azimuth", (f32 *)&Settings->Azimuth, ColorEditFlags);
        ImGui::DragFloat("Exposure", &CRay->Renderer.Settings.Exposure, 0.01f);
    }
    if (ImGui::Button("Load Model"))
    {
        ImGui::OpenPopup("Load Model");
    }
    ImGui::SetNextWindowSize(ImVec2(300, 100), ImGuiSetCond_Once);
    if (ImGui::BeginPopupModal("Load Model"))
    {
        local_persist int ChosenPrefabIndex = 0;
        
        char *PrefabNames[ARRAY_COUNT(GlobalPrefabs)] = {};
        for (int PrefabIndex = 0; PrefabIndex < ARRAY_COUNT(GlobalPrefabs); ++PrefabIndex)
        {
            PrefabNames[PrefabIndex] = GlobalPrefabs[PrefabIndex].Path;
        }
        
        ImGui::Combo("Choose Model", &ChosenPrefabIndex, (const char **)PrefabNames, ARRAY_COUNT(PrefabNames));
        
        if (ImGui::Button("OK"))
        {
            if (ChosenPrefabIndex >= 0 && ChosenPrefabIndex < ARRAY_COUNT(GlobalPrefabs))
            {
                FreeModel(CRay->Model);
                CRay->Model = LoadModel(GlobalPrefabs[ChosenPrefabIndex]);
                UploadModelToRenderer(&CRay->Renderer, CRay->Model);
            }
            ImGui::CloseCurrentPopup();
        }
        
        ImGui::SameLine();
        
        if (ImGui::Button("Cancel"))
        {
            ImGui::CloseCurrentPopup();
        }
        ImGui::EndPopup();
    }
    
    if (ImGui::Button("Hide UI"))
    {
        CRay->ShowUI = false;
    }
    
    ImGui::End();
}