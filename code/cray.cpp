#include "cray.h"
#include "cray_memory.cpp"
#include "cray_obj.cpp"
#include "cray_gpu_upload.cpp"
#include "cray_scene.cpp"
#include "cray_raster.cpp"

/*TODO(chen):

. Pick axis based on centroid projection instead of dimensions
. SAH partitioning
. Faster BVH traversal? 
. debug view the BVH
. Model level partitioning
. imgui for controlling renderer (sampling rate, max bounce count)
. imgui for profiling (speed for everything)
. Try hardware rasterization for first bounce of light rays
. Kd-tree partition for static scenes
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
        GlobalTempArena = PushMemoryArena(&CRay->MainArena, MB(500));
        
        CRay->Rasterizer = InitGLRasterizer(Width, Height);
        CRay->Scene = InitScene();
        CRay->Uploaded = UploadGeometryToGPU();
        
        Memory->IsInitialized = true;
    }
    Clear(&GlobalTempArena);
    CRay->T += dT;
    
    v3 LastCamP = CRay->Scene.CamP;
    v3 LastCamLookAt = CRay->Scene.CamLookAt;
    Interact(&CRay->Scene, Input, dT);
    
    b32 SceneIsDisturbed = (LastCamP != CRay->Scene.CamP ||
                            LastCamLookAt != CRay->Scene.CamLookAt);
    if (SceneIsDisturbed)
    {
        Refresh(&CRay->Rasterizer);
    }
    
    PrepareForRasterization(&CRay->Rasterizer, Width, Height);
    
    PushUniformI32(&CRay->Rasterizer, "TriangleCount", CRay->Uploaded.TriangleCount);
    PushUniformV3(&CRay->Rasterizer, "CamP", CRay->Scene.CamP);
    PushUniformV3(&CRay->Rasterizer, "CamLookAt", CRay->Scene.CamLookAt);
    PushUniformF32(&CRay->Rasterizer, "Time", CRay->T);
    PushUniformF32(&CRay->Rasterizer, "AspectRatio", (f32)Width / (f32)Height);
    
    Rasterize(&CRay->Rasterizer);
}