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

struct bvh_node
{
    bound Bound;
    bvh_node *Left;
    bvh_node *Right;
    int PrimitiveOffset;
    int PrimitiveCount; //NOTE(chen): set to -1 for intermediate node
};

#pragma pack(push, 1)
struct bvh_entry
{
    //NOTE(chen): bound
    v3 Min;
    u32 Pad1;
    v3 Max;
    
    union
    {
        i32 PrimitiveOffset;
        i32 SecondChildOffset;
    };
    i32 PrimitiveCount;
    
    u32 Pad2[3];
};
#pragma pack(pop)

struct linear_bvh
{
    bvh_entry *Data;
    int Count;
};

global_variable axis GlobalPartitionAxis;