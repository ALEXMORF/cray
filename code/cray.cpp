#include <imgui.h>
#include <imgui.cpp>
#include <imgui_draw.cpp>
#include "gl_imgui.cpp"

#include "cray.h"

#include "cray_memory.cpp"
#include "cray_obj.cpp"
#include "cray_gpu_upload.cpp"
#include "cray_scene.cpp"
#include "cray_raster.cpp"

/*TODO(chen):

. Kd-tree 
. Dynamically manage models
. Spatial split BVH: https://www.nvidia.com/docs/IO/77714/sbvh.pdf
. Use shadow map as direct light sampling instead of raytracing 
. UI toggle shadow map mode vs pure raytracing
. don't use shadow map first first ray hits to preserve nice direct shadows
. Stackless traversal
. Model level partitioning
. anti-alias rasterized scenes
. environment map
. imgui for loading/unloading scenes
. dynamically manipulate objects
. simple denoise
. Proper Sky model: http://blog.hvidtfeldts.net/index.php/2015/01/path-tracing-3d-fractals/
. Filmic tonemapping
. more advanced BRDF
. Multisample progressive rendering
. Allow textures
. Allow foliage
. Test on big scenes
. Allow dynamic geometry updates

*/

internal void APIENTRY 
OpenglCallback(GLenum Source, GLenum Type,
               GLuint ID, GLenum Severity,
               GLsizei Length,
               const GLchar* Message,
               const void* UserData)
{
    switch (Type)
    {
        case GL_DEBUG_TYPE_ERROR:
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        case GL_DEBUG_TYPE_PORTABILITY:
        case GL_DEBUG_TYPE_PERFORMANCE:
        {
            ASSERT(!"OpenGL Error");
        } break;
    }
    
    if (Severity == GL_DEBUG_SEVERITY_MEDIUM || 
        Severity == GL_DEBUG_SEVERITY_HIGH)
    {
        ASSERT(!"High Severity issue");
    }
}

internal void
ImGuiNewFrame(input *Input, int Width, int Height, f32 dT)
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
ImGuiToggleBool(b32 *Boolean, char *Name)
{
    if (ImGui::Button(Name))
    {
        *Boolean = !*Boolean;
    }
    ImGui::SameLine();
    ImGui::Text("%s", *Boolean? "true": "false");
}

internal void
RunCRay(app_memory *Memory, input *Input, f32 dT, int Width, int Height)
{
    ASSERT(sizeof(cray) <= Memory->Size);
    cray *CRay = (cray *)Memory->Data;
    
    if (!Memory->IsInitialized)
    {
        u8 *RestOfMemory = (u8 *)Memory->Data + sizeof(cray);
        int RestOfMemorySize = Memory->Size - sizeof(cray);
        CRay->MainArena = InitMemoryArena(RestOfMemory, RestOfMemorySize);
        GlobalTempArena = PushMemoryArena(&CRay->MainArena, GB(1));
        
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenglCallback, 0);
        
        CRay->Rasterizer = InitRasterizer(Width, Height);
        CRay->Scene = InitScene();
        CRay->Uploaded = UploadGeometryToGPU();
        
        CRay->ShowUI = true;
        InitImgui();
        
        Memory->IsInitialized = true;
    }
    Clear(&GlobalTempArena);
    CRay->T += dT;
    
    ImGuiNewFrame(Input, Width, Height, dT);
    
    if (Input->Keys['Q'])
    {
        CRay->ShowUI = true;
    }
    
    if (CRay->ShowUI)
    {
        ImGui::Begin("Profiles", 0, ImGuiWindowFlags_AlwaysAutoResize);
        ImGui::Text("Model Loading time: %.3f seconds", CRay->Uploaded.ModelLoadingTime);
        ImGui::Text("BVH Construction time: %.3f seconds", CRay->Uploaded.BvhConstructionTime);
        ImGui::Text("Triangle Count: %d", CRay->Uploaded.TriangleCount);
        ImGui::Text("Geometry Vertex Count: %d", CRay->Uploaded.GeometryVertexCount);
        ImGui::Text("BVH Node Count: %d", CRay->Uploaded.BvhEntryCount);
        ImGui::End();
        
        render_settings OldSettings = CRay->Rasterizer.Settings;
        {
            render_settings *Settings = &CRay->Rasterizer.Settings;
            ImGui::Begin("Settings", 0, ImGuiWindowFlags_AlwaysAutoResize);
            ImGuiToggleBool(&Settings->RasterizeFirstBounce, "Rasterize First Bounce");
            ImGuiToggleBool(&Settings->EnableGroundPlane, "Enable Ground Plane");
            ImGui::InputInt("Max Bounce Count", &Settings->MaxBounceCount);
            ImGui::InputFloat("FOV", &Settings->FOV, 0.1f);
            ImGui::DragFloat3("L", (f32 *)&Settings->L, 0.1f);
            ImGui::DragFloat3("Sun Radiance", (f32 *)&Settings->SunRadiance, 0.1f);
            ImGui::DragFloat3("Zenith", (f32 *)&Settings->Zenith, 0.1f);
            ImGui::DragFloat3("Azimuth", (f32 *)&Settings->Azimuth, 0.1f);
            ImGui::Separator();
            ImGui::DragFloat("Exposure", &CRay->Rasterizer.Exposure, 0.01f);
            if (ImGui::Button("Hide UI"))
            {
                CRay->ShowUI = false;
            }
            
            ImGui::End();
        }
        if (OldSettings != CRay->Rasterizer.Settings)
        {
            Refresh(&CRay->Rasterizer);
        }
    }
    
    v3 LastCamP = CRay->Scene.CamP;
    v3 LastCamLookAt = CRay->Scene.CamLookAt;
    Interact(&CRay->Scene, Input, dT);
    if (LastCamP != CRay->Scene.CamP ||
        LastCamLookAt != CRay->Scene.CamLookAt)
    {
        Refresh(&CRay->Rasterizer);
    }
    
    PrepareForRasterization(&CRay->Rasterizer, Width, Height);
    Rasterize(&CRay->Rasterizer, &CRay->Scene, &CRay->Uploaded, CRay->T);
    
    ImGui::Render();
}