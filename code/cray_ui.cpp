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
    
    ImGui::NewFrame();
    
    Input->KeyboardIsCaptured = IO.WantCaptureKeyboard;
    Input->MouseIsCaptured = IO.WantCaptureMouse;
}

internal void
DoUI(cray *CRay, int Width, int Height, f32 dT)
{
    ImGui::Begin("CRay", 0, ImGuiWindowFlags_AlwaysAutoResize);
    
    ImGui::Text("Model Loading time: %.3f seconds", CRay->Model.ModelLoadingTime);
    ImGui::Text("BVH Construction time: %.3f seconds", CRay->Model.BvhConstructionTime);
    ImGui::Text("Triangle Count: %d", CRay->Model.TriangleCount);
    ImGui::Text("Geometry Vertex Count: %d", CRay->Model.GeometryVertexCount);
    ImGui::Text("BVH Node Count: %d", CRay->Model.BvhEntryCount);
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
    
    ImGui::Separator();
    {
        render_settings *Settings = &CRay->Renderer.Settings;
        ImGui::Checkbox("Rasterize First Bounce", (bool *)&Settings->RasterizeFirstBounce);
        ImGui::Checkbox("Enable Ground Plane", (bool *)&Settings->EnableGroundPlane);
        ImGui::InputInt("Max Bounce Count", &Settings->MaxBounceCount);
        ImGui::InputFloat("FOV", &Settings->FOV, 0.01f);
        ImGui::DragFloat3("L", (f32 *)&Settings->L, 0.01f);
        ImGui::DragFloat3("Sun Radiance", (f32 *)&Settings->SunRadiance, 0.01f);
        ImGui::DragFloat3("Zenith", (f32 *)&Settings->Zenith, 0.01f);
        ImGui::DragFloat3("Azimuth", (f32 *)&Settings->Azimuth, 0.01f);
        ImGui::DragFloat("Exposure", &CRay->Renderer.Exposure, 0.01f);
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
                CRay->Model = LoadModel(GlobalPrefabs[ChosenPrefabIndex], &GlobalTempArena);
                UploadModelToGLRenderer(&CRay->Renderer, CRay->Model);
                Refresh(&CRay->Renderer);
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