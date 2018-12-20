#pragma once

#include "cray_memory.h"

struct app_memory
{
    void *Data;
    int Size;
    
    b32 IsInitialized;
};

struct cray
{
    GLuint Shader;
    GLuint QuadVAO;
    
    memory_arena MainArena;
};

