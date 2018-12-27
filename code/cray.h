#pragma once

#include "cray_memory.h"
#include "cray_obj.h"
#include "cray_gpu_upload.h"
#include "cray_scene.h"
#include "cray_raster.h"

struct app_memory
{
    void *Data;
    u64 Size;
    
    b32 IsInitialized;
};

struct input
{
    b32 Keys[256];
    
    b32 MouseIsDown;
    v2 MousePInPixels;
    v2 MouseP;
    
    b32 KeyboardIsCaptured;
    b32 MouseIsCaptured;
};

struct cray
{
    memory_arena MainArena;
    gl_rasterizer Rasterizer;
    uploaded_data Uploaded;
    scene Scene;
    
    b32 ShowUI;
    float T;
};

