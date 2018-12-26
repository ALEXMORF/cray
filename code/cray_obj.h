#pragma once

#define OBJ_CACHE_VERSION 11

struct material
{
    char Name[255];
    v4 Albedo;
    v3 Emission;
};

struct vertex
{
    v3 P;
    v3 N;
    v3 Albedo;
    v3 Emission;
};

struct obj_model
{
    vertex *Vertices;
    int VertexCount;
};
