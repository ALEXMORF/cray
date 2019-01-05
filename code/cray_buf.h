#pragma once
#include <stdlib.h>

struct buf_hdr
{
    u64 Cap;
    u64 Count;
};

#define BufHdr(Array) ((buf_hdr *)Array - 1)
#define BufCount(Array) BufHdr(Array)->Count
#define BufLast(Array) (Array)[BufCount(Array)-1]
#define BufFree(Array) free(BufHdr(Array))
#define BufPush(Array, Elmt) ((Array) = (decltype(Array))__BufExtend(Array, sizeof(Elmt)), (Array)[BufCount(Array)-1] = Elmt)
#define BufInit(Count, Type) (Type *)__BufInit(Count, sizeof(Type))

internal void *
__BufInit(u64 Count, size_t ElmtSize)
{
    void *HdrBuf = malloc(sizeof(buf_hdr) + Count * ElmtSize);
    buf_hdr *Hdr = (buf_hdr *)HdrBuf;
    Hdr->Count = Count;
    Hdr->Cap = Count;
    
    void *Buf = Hdr + 1;
    return Buf;
}

internal void *
__BufExtend(void *Buf, size_t ElmtSize)
{
    void *Result = 0;
    
    if (Buf == 0)
    {
        buf_hdr Hdr = {};
        Hdr.Cap = 2;
        Hdr.Count = 1;
        
        buf_hdr *BufWithHdr = (buf_hdr *)malloc(sizeof(Hdr) + Hdr.Cap * ElmtSize);
        *BufWithHdr = Hdr;
        Result = BufWithHdr + 1;
    }
    else
    {
        buf_hdr *Hdr = BufHdr(Buf);
        Hdr->Count += 1;
        
        if (Hdr->Count > Hdr->Cap)
        {
            u64 NewCap = (u64)((f32)Hdr->Cap * 1.5f) + 1;
            Hdr->Cap = NewCap;
            buf_hdr *BufWithHdr = (buf_hdr *)realloc(Hdr, sizeof(buf_hdr) + NewCap * ElmtSize);
            Result = BufWithHdr + 1;
        }
        else
        {
            Result = Buf;
        }
    }
    
    return Result;
}