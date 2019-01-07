#pragma once

struct memory_block
{
    u8 *Base;
    u64 Used;
    u64 Size;
    
    memory_block *Prev;
    memory_block *Next;
};

struct memory_arena
{
    u64 BlockSize;
    
    memory_block *Head;
    memory_block *Current;
}; 

global_variable memory_arena GlobalTempArena;