#include <stdio.h>
#include <stdlib.h>

internal char *
ReadFileTemporarily(char *FilePath)
{
    char *Buffer = 0;
    
    FILE *File = fopen(FilePath, "rb");
    if (File)
    {
        fseek(File, 0, SEEK_END);
        int FileSize = ftell(File);
        rewind(File);
        
        Buffer = PushTempArray(FileSize+1, char);
        Buffer[FileSize] = 0;
        fread(Buffer, 1, FileSize, File);
        
        fclose(File);
    }
    
    return Buffer;
}

inline char *
GotoNextLine(char *Ptr)
{
    while (*Ptr != '\n')
    {
        Ptr += 1;
    }
    
    while (*Ptr == '\r' || *Ptr == '\n')
    {
        Ptr += 1;
    }
    
    return Ptr;
}

inline int
Length(char *Str)
{
    int Count = 0;
    
    while (*Str)
    {
        Count += 1;
        Str += 1;
    }
    
    return Count;
}

inline b32
Equal(char *Str1, char *Str2)
{
    while (*Str1 && *Str2)
    {
        if (*Str1++ != *Str2++)
        {
            return false;
        }
    }
    return true;
}

inline b32
StartsWith(char *Str, char *SubStr)
{
    for (int CharIndex = 0; CharIndex < Length(SubStr); ++CharIndex)
    {
        if (Str[CharIndex] != SubStr[CharIndex])
        {
            return false;
        }
    }
    
    return true;
}

internal void
WriteObjCache(char *ObjCachePath, obj_model ObjModel)
{
    /* NOTE(chen): 
Cache file layout:

4 byte - version
4 byte - vert count
rest   - vertices

*/
    
    int CacheSize = 4 + 4 + sizeof(vertex) * ObjModel.VertexCount;
    u8 *Cache = PushTempArray(CacheSize, u8);
    i32 *CacheWriterI32 = (i32 *)Cache;
    
    *CacheWriterI32++ = OBJ_CACHE_VERSION;
    *CacheWriterI32++ = ObjModel.VertexCount;
    
    vertex *CacheWriterVertex = (vertex *)CacheWriterI32;
    for (int VertexIndex = 0; VertexIndex < ObjModel.VertexCount; ++VertexIndex)
    {
        *CacheWriterVertex++ = ObjModel.Vertices[VertexIndex];
    }
    
    FILE *OutputFile = fopen(ObjCachePath, "wb");
    if (OutputFile)
    {
        fwrite(Cache, 1, CacheSize, OutputFile);
        fclose(OutputFile);
        printf("cached OBJ file at %s\n", ObjCachePath);
    }
    else
    {
        printf("failed to write obj cache: %s\n", ObjCachePath);
    }
}

internal obj_model
LoadObjCache(FILE *File, memory_arena *Arena)
{
    obj_model Result = {};
    
    fseek(File, 0, SEEK_END);
    int CacheSize = ftell(File);
    rewind(File);
    
    u8 *Cache = PushTempArray(CacheSize, u8);
    fread(Cache, 1, CacheSize, File);
    fclose(File);
    
    i32 *CacheReaderI32 = (i32 *)Cache;
    
    i32 CacheVersion = *CacheReaderI32++;  
    if (CacheVersion == OBJ_CACHE_VERSION)
    {
        Result.VertexCount = *CacheReaderI32++;
        Result.Vertices = PushArray(Arena, Result.VertexCount, vertex);
        
        vertex *CacheReaderVertex = (vertex *)CacheReaderI32;
        for (int VertexIndex = 0; VertexIndex < Result.VertexCount; ++VertexIndex)
        {
            Result.Vertices[VertexIndex] = *CacheReaderVertex++;
        }
    }
    else
    {
        printf("Current cache version = %d, but cache version encountered = %d, failed loading cache\n", 
               OBJ_CACHE_VERSION, CacheVersion);
    }
    
    return Result;
}

internal obj_model
LoadObj(char *Path, memory_arena *Arena)
{
    obj_model Result = {};
    
    //NOTE(chen): check for cache
    {
        char ObjCachePath[255];
        snprintf(ObjCachePath, sizeof(ObjCachePath), "%s.cache", Path);
        
        FILE *CacheFile = fopen(ObjCachePath, "rb");
        if (CacheFile)
        {
            Result = LoadObjCache(CacheFile, &GlobalTempArena);
            fclose(CacheFile);
            return Result;
        }
    }
    
    char MtlPath[255];
    snprintf(MtlPath, sizeof(MtlPath), "%s.mtl", Path);
    char ObjPath[255];
    snprintf(ObjPath, sizeof(ObjPath), "%s.obj", Path);
    
    material Mats[100] = {};
    int MatCount = 0;
    
    char *MtlFileContent = ReadFileTemporarily(MtlPath);
    ASSERT(MtlFileContent);
    char *MtlFileWalker = MtlFileContent;
    
    while (*MtlFileWalker)
    {
        if (StartsWith(MtlFileWalker, "newmtl"))
        {
            material NewMat = {};
            sscanf(MtlFileWalker, "newmtl %s", NewMat.Name);
            
            while (!StartsWith(MtlFileWalker, "Kd"))
            {
                MtlFileWalker = GotoNextLine(MtlFileWalker);
            }
            sscanf(MtlFileWalker, "Kd %f %f %f", 
                   &NewMat.Albedo.X, &NewMat.Albedo.Y, &NewMat.Albedo.Z);
            
            Mats[MatCount++] = NewMat;
        }
        
        MtlFileWalker = GotoNextLine(MtlFileWalker);
    }
    
    char *ObjFileContent = ReadFileTemporarily(ObjPath);
    ASSERT(ObjFileContent);
    char *ObjFileWalker = ObjFileContent;
    
    int TempVertexCount = 0;
    int TempNormalCount = 0;
    int FaceCount = 0;
    while (*ObjFileWalker)
    {
        if (StartsWith(ObjFileWalker, "v"))
        {
            TempVertexCount += 1;
        }
        if (StartsWith(ObjFileWalker, "vn"))
        {
            TempNormalCount += 1;
        }
        if (StartsWith(ObjFileWalker, "f"))
        {
            FaceCount += 1;
        }
        
        ObjFileWalker = GotoNextLine(ObjFileWalker);
    }
    
    v3 *TempVertices = PushTempArray(TempVertexCount, v3);
    int TempVertexCursor = 0;
    v3 *TempNormals = PushTempArray(TempNormalCount, v3);
    int TempNormalCursor = 0;
    
    Result.VertexCount = FaceCount * 3;
    Result.Vertices = PushArray(Arena, Result.VertexCount, vertex);
    int VertexCursor = 0;
    
    int CurrentMatIndex = -1;
    ObjFileWalker = ObjFileContent;
    while (*ObjFileWalker)
    {
        if (StartsWith(ObjFileWalker, "v"))
        {
            v3 Vertex = {};
            sscanf(ObjFileWalker, "v %f %f %f", 
                   &Vertex.X, &Vertex.Y, &Vertex.Z);
            TempVertices[TempVertexCursor++] = Vertex;
        }
        if (StartsWith(ObjFileWalker, "vn"))
        {
            v3 Normal = {};
            sscanf(ObjFileWalker, "vn %f %f %f", 
                   &Normal.X, &Normal.Y, &Normal.Z);
            TempNormals[TempNormalCursor++] = Normal;
        }
        if (StartsWith(ObjFileWalker, "f"))
        {
            int Garbage[3] = {};
            int VertexIndices[3] = {};
            int NormalIndices[3] = {};
            
            int ArgumentsParsed = sscanf(ObjFileWalker, 
                                         "f %d/%d/%d %d/%d/%d %d/%d/%d",
                                         VertexIndices, Garbage, NormalIndices,
                                         VertexIndices+1, Garbage+1, NormalIndices+1,
                                         VertexIndices+2, Garbage+2, NormalIndices+2);
            
            if (ArgumentsParsed != 9)
            {
                ArgumentsParsed = sscanf(ObjFileWalker, 
                                         "f %d//%d %d//%d %d//%d",
                                         VertexIndices, NormalIndices,
                                         VertexIndices+1, NormalIndices+1,
                                         VertexIndices+2, NormalIndices+2);
            }
            
            for (int VI = 0; VI < 3; ++VI)
            {
                //NOTE(chen): OBJ is 1-based, making it 0-based
                VertexIndices[VI] -= 1;
                NormalIndices[VI] -= 1;
                
                ASSERT(CurrentMatIndex != -1);
                Result.Vertices[VertexCursor].P = TempVertices[VertexIndices[VI]];
                Result.Vertices[VertexCursor].N = TempNormals[NormalIndices[VI]];
                Result.Vertices[VertexCursor].Albedo = Mats[CurrentMatIndex].Albedo;
                VertexCursor += 1;
            }
        }
        else if (StartsWith(ObjFileWalker, "usemtl"))
        {
            char MtlName[255];
            sscanf(ObjFileWalker, "usemtl %s", MtlName);
            
            int NewMatIndex = -1;
            for (int MatIndex = 0; MatIndex < MatCount; ++MatIndex)
            {
                if (Equal(MtlName, Mats[MatIndex].Name))
                {
                    NewMatIndex = MatIndex;
                    break;
                }
            }
            
            ASSERT(NewMatIndex != -1);
            CurrentMatIndex = NewMatIndex;
        }
        
        ObjFileWalker = GotoNextLine(ObjFileWalker);
    }
    
    ASSERT(TempVertexCursor == TempVertexCount);
    ASSERT(TempNormalCursor == TempNormalCount);
    ASSERT(VertexCursor == Result.VertexCount);
    
    char ObjCachePath[255];
    snprintf(ObjCachePath, sizeof(ObjCachePath), "%s.cache", Path);
    WriteObjCache(ObjCachePath, Result);
    
    return Result;
}
