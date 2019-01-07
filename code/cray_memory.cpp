internal memory_block *
InitMemoryBlock(size_t BlockSize)
{
    memory_block *Block = (memory_block *)calloc(1, sizeof(memory_block));
    
    Block->Size = BlockSize;
    Block->Base = (u8 *)malloc(Block->Size);
    
    return Block;
}

internal memory_arena
InitMemoryArena(size_t BlockSize)
{
    memory_arena Arena = {};
    
    Arena.BlockSize = BlockSize;
    Arena.Head = InitMemoryBlock(BlockSize);
    Arena.Current = Arena.Head;
    
    return Arena;
}

internal void
Clear(memory_arena *Arena)
{
    memory_block *Curr = Arena->Head->Next;
    
    while (Curr)
    {
        memory_block *Next = Curr->Next;
        free(Curr->Base);
        free(Curr);
        Curr = Next;
    }
    
    Arena->Current = Arena->Head;
    Arena->Head->Used = 0;
    Arena->Head->Next = 0;
}

internal u8 *
PushBytes(memory_block *Block, size_t ByteCount)
{
    ASSERT(Block->Size - Block->Used >= ByteCount);
    u8 *Mem = Block->Base + Block->Used;
    Block->Used += ByteCount;
    return Mem;
}

#define PushStruct(Arena, Type) (Type *)PushBytes(Arena, sizeof(Type))
#define PushArray(Arena, Count, Type) (Type *)PushBytes(Arena, Count*sizeof(Type))
#define PushTempStruct(Type) (Type *)PushBytes(&GlobalTempArena, sizeof(Type))
#define PushTempArray(Count, Type) (Type *)PushBytes(&GlobalTempArena, Count*sizeof(Type))
internal u8 *
PushBytes(memory_arena *Arena, size_t ByteCount)
{
    ASSERT(ByteCount <= Arena->BlockSize);
    
    if (Arena->Current->Size - Arena->Current->Used >= ByteCount)
    {
        return PushBytes(Arena->Current, ByteCount);
    }
    else
    {
        memory_block *NewBlock = InitMemoryBlock(Arena->BlockSize);
        NewBlock->Prev = Arena->Current;
        Arena->Current->Next = NewBlock;
        Arena->Current = NewBlock;
        
        return PushBytes(NewBlock, ByteCount);
    }
}
