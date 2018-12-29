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
#include "cray_ui.cpp"

/*TODO(chen):

. Pull out BVH code and only interface it with primitives
. Lower memory footprint
. Bake shader code into executable
. dump error log instead of silent crash
. rename raster to render
. implement Kd-tree
. implement SBVH
. Stackless traversal
. Pull CRay out as a separate renderer
. drag and drop models: https://stackoverflow.com/questions/12345435/drag-and-drop-support-for-win32-gui 
. Serious material system 
. A more compressed 3D mesh storage 
. Use shadow map as direct light sampling instead of raytracing 
. UI toggle shadow map mode vs pure raytracing
. don't use shadow map first first ray hits to preserve nice direct shadows
. implement spatial split BVH
. Spatial split BVH: https://www.nvidia.com/docs/IO/77714/sbvh.pdf
. Model level partitioning
. anti-alias rasterized scenes
. environment map
. imgui for loading/unloading scenes
. dynamically manipulate objects
. simple denoise
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
        {
            ASSERT(!"OpenGL Error");
        } break;
        
        case GL_DEBUG_TYPE_PERFORMANCE:
        {
            //TODO(chen): record performance problems
        } break;
    }
    
#if 0
    if (Severity == GL_DEBUG_SEVERITY_MEDIUM || 
        Severity == GL_DEBUG_SEVERITY_HIGH)
    {
        ASSERT(!"High Severity issue");
    }
#endif
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
        GlobalTempArena = PushMemoryArena(&CRay->MainArena, GB(2));
        
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(OpenglCallback, 0);
        
        CRay->Rasterizer = InitRasterizer(Width, Height);
        CRay->Uploaded = UploadGeometryToGPU(GlobalPrefabs[0]);
        CRay->Scene = InitScene();
        
        CRay->ShowUI = true;
        InitImgui();
        
        Memory->IsInitialized = true;
    }
    Clear(&GlobalTempArena);
    CRay->T += dT;
    
    UINewFrame(Input, Width, Height, dT);
    
    if (Input->Keys['Q'])
    {
        CRay->ShowUI = true;
    }
    
    render_settings OldSettings = CRay->Rasterizer.Settings;
    if (CRay->ShowUI)
    {
        DoUI(CRay, Width, Height, dT);
    }
    if (OldSettings != CRay->Rasterizer.Settings)
    {
        Refresh(&CRay->Rasterizer);
    }
    
    v3 LastCamP = CRay->Scene.CamP;
    v3 LastCamLookAt = CRay->Scene.CamLookAt;
    HandleInput(&CRay->Scene, Input, dT);
    if (LastCamP != CRay->Scene.CamP ||
        LastCamLookAt != CRay->Scene.CamLookAt)
    {
        Refresh(&CRay->Rasterizer);
    }
    
    PrepareForRasterization(&CRay->Rasterizer, Width, Height);
    Rasterize(&CRay->Rasterizer, &CRay->Scene, &CRay->Uploaded, CRay->T);
    
    ImGui::Render();
}