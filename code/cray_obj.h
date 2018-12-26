#pragma once

#define OBJ_CACHE_VERSION 7

struct material
{
    char Name[255];
    v3 Albedo;
};

struct vertex
{
    v3 P;
    v3 N;
    v3 Albedo;
};

struct obj_model
{
    vertex *Vertices;
    int VertexCount;
};
