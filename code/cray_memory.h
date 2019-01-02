#pragma once

struct memory_arena
{
    u8 *Base;
    u64 Used;
    u64 Size;
    
    u64 SavedOffset;
}; 

global_variable memory_arena GlobalTempArena;