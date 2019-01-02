#pragma once

enum axis
{
    AXIS_X = 0,
    AXIS_Y,
    AXIS_Z,
    AXIS_COUNT,
};

struct bound
{
    v3 Min;
    v3 Max;
    
    b32 IsValid;
};

struct primitive
{
    int TriIndex;
    bound Bound;
    v3 Centroid;
};

struct bucket
{
    bound Bound;
    int PrimCount;
};

struct bvh_node
{
    bound Bound;
    bvh_node *Left;
    bvh_node *Right;
    axis PartitionAxis;
    int PrimitiveOffset;
    int PrimitiveCount; //NOTE(chen): set to -1 for intermediate node
};

struct bvh_entry
{
    v3 BoundMin;
    v3 BoundMax;
    
    union
    {
        i32 PrimitiveOffset;
        i32 SecondChildOffset;
    };
    i32 PrimitiveCount;
    i32 Axis;
};

struct linear_bvh
{
    bvh_entry *Data;
    int Count;
};
