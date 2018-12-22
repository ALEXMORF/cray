#pragma once

#include "cray_memory.h"
#include "cray_obj.h"
#include "cray_gpu_upload.h"
#include "cray_scene.h"
#include "cray_raster.h"

struct app_memory
{
    void *Data;
    int Size;
    
    b32 IsInitialized;
};

struct input
{
    b32 Keys[256];
    
    b32 MouseIsDown;
    v2 MouseP;
};

struct cray
{
    memory_arena MainArena;
    gl_rasterizer Rasterizer;
    uploaded_data Uploaded;
    scene Scene;
    
    float T;
};

