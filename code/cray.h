#pragma once

#include "cray_memory.h"
#include "cray_obj.h"

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
    b32 CamIsBeingDragged;
    v2 StartMouseP;
    quaternion DraggedRotation;
    
    quaternion CamOrientation;
    v3 CamP;
    v3 CamLookAt;
    float T;
    
    memory_arena MainArena;
    GLuint Shader;
    GLuint QuadVAO;
    
    GLuint SSBO;
    int VertexCount;
};

