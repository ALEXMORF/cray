#pragma once

#define OBJ_CACHE_VERSION 1

struct material
{
    char Name[255];
    v3 Albedo;
};

struct vertex
{
    v3 P;
    f32 Padding1;
    v3 N;
    f32 Padding2;
    v3 Albedo;
    f32 Padding3;
};

struct obj_model
{
    vertex *Vertices;
    int VertexCount;
};
