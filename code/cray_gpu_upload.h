#pragma once

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
};
#pragma pack(pop)

#include "cray_bvh.h"

struct uploaded_data
{
    int TriangleCount;
};