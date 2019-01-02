#include <imgui.h>
#include <imgui.cpp>
#include <imgui_draw.cpp>

#include "cray.h"

#include "cray_memory.cpp"
#include "cray_obj.cpp"
#include "cray_bvh.cpp"
#include "cray_load_model.cpp"
//#include "cray_gl_renderer.cpp"
#include "cray_camera.cpp"
#include "cray_dx_renderer.cpp"
#include "cray_ui.cpp"

/*TODO(chen):

. switch to dx11 for the renderer
-   add volatile sampler data of renderer, needs per-frame updating UpdateSubresource()
-   remove hard coded constants
-   read about HLSL optimization
-   try cache Loads, see if it goes faster
 -   a switch to toggle compiler optimization
-   a switch to toggle device's debug layer
. Use stretchy buffer instead of pre-allocating, model size is unknown whereas game asset is known. 
-   Implement stretchy buffer
-   replace vertices and triangles structs as they are unnecessary
-   use stretchy buffer for all allocations done in LoadModel()
. Optimize shadow rays: don't return nearest t, instead only a boolean result is needed.
. Better BVH subdivision termination rule
. faster BVH traversal (stackless)
. implement SBVH
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
RunCRay(app_memory *Memory, input *Input, f32 dT, 
        HWND Window, int Width, int Height, panic *PlatformPanic)
{
    ASSERT(sizeof(cray) <= Memory->Size);
    cray *CRay = (cray *)Memory->Data;
    
    if (!Memory->IsInitialized)
    {
        __PanicStr = PlatformPanic;
        
        u8 *RestOfMemory = (u8 *)Memory->Data + sizeof(cray);
        u64 RestOfMemorySize = Memory->Size - sizeof(cray);
        CRay->MainArena = InitMemoryArena(RestOfMemory, RestOfMemorySize);
        GlobalTempArena = PushMemoryArena(&CRay->MainArena, GB(1));
        
        CRay->Camera = InitCamera();
        CRay->Renderer = InitDXRenderer(Window, &CRay->Camera);
        CRay->Model = LoadModel(GlobalPrefabs[0], &GlobalTempArena);
        UploadModelToRenderer(&CRay->Renderer, CRay->Model);
        
        CRay->ShowUI = false;
        
        Memory->IsInitialized = true;
    }
    Clear(&GlobalTempArena);
    CRay->T += dT;
    
    //UINewFrame(Input, Width, Height, dT);
    
    if (Input->Keys['Q'])
    {
        CRay->ShowUI = true;
    }
    
#if 0
    render_settings OldSettings = CRay->Renderer.Settings;
    if (CRay->ShowUI)
    {
        DoUI(CRay, Width, Height, dT);
    }
    if (OldSettings != CRay->Renderer.Settings)
    {
        Refresh(&CRay->Renderer);
    }
#endif
    
    v3 LastCamP = CRay->Camera.P;
    v3 LastCamLookAt = CRay->Camera.LookAt;
    HandleInput(&CRay->Camera, Input, dT);
    if (LastCamP != CRay->Camera.P ||
        LastCamLookAt != CRay->Camera.LookAt)
    {
        Refresh(&CRay->Renderer);
    }
    
    ResizeResources(&CRay->Renderer, Width, Height);
    Render(&CRay->Renderer, &CRay->Camera, CRay->T);
    
    //ImGui::Render();
    Present(&CRay->Renderer);
}