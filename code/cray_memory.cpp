internal memory_arena
InitMemoryArena(void *Memory, size_t Size)
{
    memory_arena Arena = {};
    
    Arena.Base = (u8 *)Memory;
    Arena.Size = Size;
    
    return Arena;
}

internal void
Clear(memory_arena *Arena)
{
    Arena->Used = 0;
}

#define PushStruct(Arena, Type) (Type *)PushBytes(Arena, sizeof(Type))
#define PushArray(Arena, Count, Type) (Type *)PushBytes(Arena, Count*sizeof(Type))
#define PushTempStruct(Type) (Type *)PushBytes(&GlobalTempArena, sizeof(Type))
#define PushTempArray(Count, Type) (Type *)PushBytes(&GlobalTempArena, Count*sizeof(Type))
internal u8 *
PushBytes(memory_arena *Arena, size_t ByteCount)
{
    size_t SizeLeft = Arena->Size - Arena->Used;
    ASSERT(SizeLeft >= ByteCount);
    
    u8 *MemPoint = Arena->Base + Arena->Used;
    Arena->Used += ByteCount;
    
    return MemPoint;
}

internal memory_arena
PushMemoryArena(memory_arena *ParentArena, size_t Size)
{
    memory_arena Arena = {};
    
    Arena.Base = PushArray(ParentArena, Size, u8);
    Arena.Size = Size;
    
    return Arena;
}

