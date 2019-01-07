#include "cray.h"

#include <imgui.cpp>
#include <imgui_draw.cpp>
#include <imgui_widgets.cpp>

#include "cray_memory.cpp"
#include "cray_file.cpp"
#include "cray_obj.cpp"
#include "cray_bvh.cpp"
#include "cray_load_model.cpp"
#include "cray_camera.cpp"
#include "cray_dx_renderer.cpp"
#include "cray_ui.cpp"

/*TODO(chen):

        . Better BVH subdivision termination rule
. faster BVH traversal (stackless)
. implement SBVH
. solve the "string too long" problem, can't bake shader into exe
-    currently leaking memory to read shader code, fix that
. import more test models: http://graphics.stanford.edu/data/3Dscanrep/
. fix biased convergence
. compressed BVH storage on GPU
. faster ray vs triangle tests (woop test)
 . Lower memory footprint
-    compressed 3D mesh storage
-    a serious material system
-    add ply loader
-    support pbrt scenes
-    support PBR material from pbrt scenes
-    textures
. actual physically based rendering
. Proper backwards-compatible DPI scaling
. Handle text DPI-scaling correctly
. Allow multiple models
. Manipulator widget
. Model level partitioning
- Multi-threaded UI so it doesn't get blocked by the path tracer?
. Pull CRay out as a separate renderer
. drag and drop models: https://stackoverflow.com/questions/12345435/drag-and-drop-support-for-win32-gui 
. A more compressed 3D mesh storage 
. Use shadow map as direct light sampling instead of raytracing 
. UI toggle shadow map mode vs pure raytracing
. don't use shadow map first first ray hits to preserve nice direct shadows
. Spatial split BVH: https://www.nvidia.com/docs/IO/77714/sbvh.pdf
. anti-alias rasterized scenes
. environment map
. imgui for loading/unloading scenes
. dynamically manipulate objects
. simple denoise
. Filmic tonemapping
. more advanced BRDF
. Multisample progressive rendering
. Allow foliage
. Test on big scenes
. Allow dynamic geometry updates

*/

internal void
RunCRay(cray *CRay, input *Input, f32 dT, HWND Window, 
        int Width, int Height, panic *PlatformPanic)
{
    if (!CRay->IsInitialized)
    {
        __PanicStr = PlatformPanic;
        
        GlobalTempArena = InitMemoryArena(MB(2));
        CRay->Camera = InitCamera();
        CRay->Renderer = InitDXRenderer(Window, &CRay->Camera, Width, Height);
        CRay->Model = LoadModel(GlobalPrefabs[0]);
        UploadModelToRenderer(&CRay->Renderer, CRay->Model);
        CRay->ShowUI = true;
        
        CRay->IsInitialized = true;
    }
    Clear(&GlobalTempArena);
    CRay->T += dT;
    
    UINewFrame(Input, Width, Height, dT);
    
    if (Input->Keys['Q'])
    {
        CRay->ShowUI = true;
    }
    
    render_settings OldSettings = CRay->Renderer.Settings;
    if (CRay->ShowUI)
    {
        DoUI(CRay, Width, Height, dT);
    }
    if (NeedsRefresh(OldSettings, CRay->Renderer.Settings))
    {
        Refresh(&CRay->Renderer);
    }
    
    HandleInput(&CRay->Camera, Input, dT);
    if (CRay->Camera.P != CRay->Renderer.Camera.P ||
        CRay->Camera.LookAt != CRay->Renderer.Camera.LookAt)
    {
        RefreshCamera(&CRay->Renderer, &CRay->Camera);
    }
    
    if (Width != CRay->Renderer.Width || Height != CRay->Renderer.Height)
    {
        ResizeResources(&CRay->Renderer, Width, Height);
    }
    
    Render(&CRay->Renderer, &CRay->Camera, CRay->T);
    ImGui::Render();
    Present(&CRay->Renderer);
}