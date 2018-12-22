#pragma once

#pragma pack(push, 1)
struct packed_triangle
{
    v3 A;
    f32 Padding1;
    v3 B;
    f32 Padding2;
    v3 C;
    f32 Padding3;
    v3 N;
    f32 Padding4;
};
#pragma pack(pop)

struct uploaded_data
{
    int TriangleCount;
};