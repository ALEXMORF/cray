#pragma once

struct alloc_entry
{
    void *Pointer;
    
    u64 AllocSize;
    char *File;
    int Line;
    char *Func;
    
    alloc_entry *Next;
};

global_variable u64 GlobalAllocCallCount;
global_variable u64 GlobalMemoryUsage;
global_variable u64 GlobalPeekMemoryUsage;
global_variable alloc_entry GlobalAllocTable[100000];
global_variable b32 GlobalDisableAllocProfiling;

internal void
EnableAllocProfiling()
{
    GlobalDisableAllocProfiling = false;
}

internal void
DisableAllocProfiling()
{
    GlobalDisableAllocProfiling = true;
}

internal u64
Hash(void *Pointer)
{
    return ((u64)Pointer / 16) * 387198793;
}

internal alloc_entry
InitEntry(void *Pointer, u64 AllocSize, char *File, int Line, char *Func)
{
    alloc_entry Result = {};
    
    Result.Pointer = Pointer;
    Result.AllocSize = AllocSize;
    Result.File = File;
    Result.Line = Line;
    Result.Func = Func;
    
    return Result;
}

internal void 
StoreAlloc(void *Pointer, u64 AllocSize, char *File, int Line, char *Func)
{
    if (GlobalDisableAllocProfiling) return;
    if (!Pointer) return;
    
    GlobalAllocCallCount += 1;
    GlobalMemoryUsage += AllocSize;
    if (GlobalMemoryUsage > GlobalPeekMemoryUsage)
    {
        GlobalPeekMemoryUsage = GlobalMemoryUsage;
    }
    
    u64 Index = Hash(Pointer) % ARRAY_COUNT(GlobalAllocTable);
    
    alloc_entry *Entry = GlobalAllocTable + Index;
    if (!Entry->Pointer) // no collision
    {
        *Entry = InitEntry(Pointer, AllocSize, File, Line, Func);
    }
    else // collision
    {
        alloc_entry *LastEntry = Entry;
        while (LastEntry->Next)
        {
            LastEntry = LastEntry->Next;
        }
        
        alloc_entry *NewEntry = (alloc_entry *)calloc(1, sizeof(alloc_entry));
        *NewEntry = InitEntry(Pointer, AllocSize, File, Line, Func);
        
        LastEntry->Next = NewEntry;
    }
}

internal void
RemoveAlloc(void *Pointer)
{
    if (GlobalDisableAllocProfiling) return;
    if (!Pointer) return;
    
    u64 Index = Hash(Pointer) % ARRAY_COUNT(GlobalAllocTable);
    
    alloc_entry *Entry = GlobalAllocTable + Index;
    if (Entry->Pointer == Pointer)
    {
        GlobalMemoryUsage -= Entry->AllocSize;
        
        if (Entry->Next)
        {
            alloc_entry *NextEntry = Entry->Next;
            *Entry = *NextEntry;
            free(NextEntry);
        }
        else
        {
            *Entry = {}; 
        }
    }
    else
    {
        alloc_entry *LastEntry = Entry;
        Entry = Entry->Next;
        while (Entry)
        {
            if (Entry->Pointer == Pointer)
            {
                GlobalMemoryUsage -= Entry->AllocSize;
                LastEntry->Next = Entry->Next;
                free(Entry);
                return;
            }
            
            LastEntry = Entry;
            Entry = Entry->Next;
        }
        ASSERT(Entry); //NOTE(chen): if this hits then fail to find Pointer
    }
}

void *DebugMalloc(size_t Size, char *File, int Line, char *Func)
{
    void *Ptr = malloc(Size);
    StoreAlloc(Ptr, Size, File, Line, Func);
    return Ptr;
}

void *DebugCalloc(size_t Count, size_t Size, char *File, int Line, char *Func)
{
    void *Ptr = calloc(Count, Size);
    StoreAlloc(Ptr, Count * Size, File, Line, Func);
    return Ptr;
}

void DebugFree(void *Pointer)
{
    RemoveAlloc(Pointer);
    free(Pointer);
}

void *DebugRealloc(void *OldPointer, size_t NewSize, char *File, int Line, char *Func)
{
    RemoveAlloc(OldPointer);
    void *NewPointer = realloc(OldPointer, NewSize);
    StoreAlloc(NewPointer, NewSize, File, Line, Func);
    return NewPointer;
}

#if CRAY_MALLOC
#define malloc(Size) DebugMalloc(Size, __FILE__, __LINE__, __func__)
#define calloc(Count, Size) DebugCalloc(Count, Size, __FILE__, __LINE__, __func__)
#define realloc(Pointer, NewSize) DebugRealloc(Pointer, NewSize, __FILE__, __LINE__, __func__)
#define free(Pointer) DebugFree(Pointer)
#endif
