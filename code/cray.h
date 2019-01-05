#pragma once

#include "cray_prefabs.h"

#include "cray_malloc.h"
#include "cray_buf.h"
#include "cray_memory.h"
#include "cray_obj.h"
#include "cray_bvh.h"
#include "cray_load_model.h"
#include "cray_camera.h"
#include "cray_dx_renderer.h"

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
    dx_renderer Renderer;
    loaded_model Model;
    camera Camera;
    
    b32 ShowUI;
    float T;
};
