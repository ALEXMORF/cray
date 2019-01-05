#pragma once
#include <time.h>

struct triangle
{
    v3 A;
    v3 B;
    v3 C;
    v3 N;
    v3 Albedo;
    v3 Emission;
};

struct loaded_model
{
    vertex *Vertices;
    triangle *Triangles;
    //TODO(chen): replace with stretchy buffer
    linear_bvh BVH;
    int BvhEntryCount;
    
    f32 ModelLoadingTime;
    f32 BvhConstructionTime;
};