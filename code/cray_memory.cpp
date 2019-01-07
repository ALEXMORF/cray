internal memory_arena
InitMemoryArena(size_t Size)
{
    memory_arena Arena = {};
    
    Arena.Base = (u8 *)malloc(Size);
    Arena.Size = Size;
    
    return Arena;
}

internal void
Clear(memory_arena *Arena)
{
    Arena->Used = 0;
}

internal void
SaveOffset(memory_arena *Arena)
{
    Arena->SavedOffset = Arena->Used;
}

internal void
RewindToSavedOffset(memory_arena *Arena)
{
    Arena->Used = Arena->SavedOffset;
}

internal void
SaveTempArenaOffset()
{
    SaveOffset(&GlobalTempArena);
}

internal void
RewindTempArenaToSavedOffset()
{
    RewindToSavedOffset(&GlobalTempArena);
}

#define PushStruct(Arena, Type) (Type *)PushBytes(Arena, sizeof(Type))
#define PushArray(Arena, Count, Type) (Type *)PushBytes(Arena, Count*sizeof(Type))
#define PushTempStruct(Type) (Type *)PushBytes(&GlobalTempArena, sizeof(Type))
#define PushTempArray(Count, Type) (Type *)PushBytes(&GlobalTempArena, Count*sizeof(Type))
internal u8 *
PushBytes(memory_arena *Arena, size_t ByteCount)
{
    while ((Arena->Size - Arena->Used) < ByteCount)
    {
        Panic("can't grow memory rn!");
        size_t NewSize = Arena->Size * 2 + 1;
        Arena->Base = (u8 *)realloc(Arena->Base, NewSize * sizeof(u8));
        Arena->Size = NewSize;
    }
    
    u8 *MemPoint = Arena->Base + Arena->Used;
    Arena->Used += ByteCount;
    ASSERT(Arena->Used <= Arena->Size);
    
    return MemPoint;
}

