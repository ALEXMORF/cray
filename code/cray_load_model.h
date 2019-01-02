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

struct vertices
{
    vertex *Data;
    int Count;
};

struct triangles
{
    triangle *Data;
    int Count;
};

struct loaded_model
{
    //TODO(chen): replace with stretchy buffer
    vertices Vertices;
    triangles Triangles;
    linear_bvh BVH;
    
    int GeometryVertexCount;
    int TriangleCount;
    int BvhEntryCount;
    
    f32 ModelLoadingTime;
    f32 BvhConstructionTime;
};