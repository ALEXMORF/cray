#pragma once

#include "cray_memory.h"

struct app_memory
{
    void *Data;
    int Size;
    
    b32 IsInitialized;
};

struct input
{
    b32 Keys[256];
};

struct cray
{
    v3 CamP;
    
    memory_arena MainArena;
    GLuint Shader;
    GLuint QuadVAO;
};

