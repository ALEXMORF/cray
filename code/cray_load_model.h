#pragma once
#include <time.h>

#pragma pack(push, 1)
struct packed_triangle
{
    v3 A;
    f32 Pad1;
    v3 B;
    f32 Pad2;
    v3 C;
    f32 Pad3;
    v3 N;
    f32 Pad4;
    v3 Albedo;
    f32 Pad5;
    v3 Emission;
    f32 Pad6;
};
#pragma pack(pop)

struct vertices
{
    vertex *Data;
    int Count;
};

struct triangles
{
    packed_triangle *Data;
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