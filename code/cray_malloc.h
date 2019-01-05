#pragma once

global_variable u64 GlobalMallocCallCount;

void *DebugMalloc(size_t Size)
{
    GlobalMallocCallCount += 1;
    return malloc(Size);
}

void DebugFree(void *Pointer)
{
    free(Pointer);
}

void *DebugRealloc(void *Pointer, size_t NewSize)
{
    GlobalMallocCallCount += 1;
    return realloc(Pointer, NewSize);
}

#define malloc(Size) DebugMalloc(Size)
#define realloc(Pointer, NewSize) DebugRealloc(Pointer, NewSize)
#define free(Pointer) DebugFree(Pointer)
