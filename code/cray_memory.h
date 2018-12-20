#pragma once

struct memory_arena
{
    u8 *Base;
    int Used;
    int Size;
}; 

global_variable memory_arena GlobalTempArena;