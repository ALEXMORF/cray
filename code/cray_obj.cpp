#include <stdio.h>
#include <stdlib.h>

#define sscanf DONT_USE_SSCANF_BAD_BAD

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

inline char *
SkipSpaces(char *Cursor)
{
    char *EndCursor = Cursor;
    
    while (*EndCursor == ' ')
    {
        EndCursor += 1;
    }
    
    return EndCursor;
}

#define EXPECT_STR(Cursor, S) \
if (!StartsWith(Cursor, S)) \
{ \
    return false; \
} \
Cursor += Length(S); \

#define EXPECT_CHAR(Cursor, C) \
if (*Cursor != C) \
{ \
    return false; \
} \
Cursor += 1; \

inline b32
ParseString(char *Cursor, char *Prefix, char *Buffer_Out)
{
    Cursor = SkipSpaces(Cursor);
    
    EXPECT_STR(Cursor, Prefix);
    
    Cursor = SkipSpaces(Cursor);
    
    int BufferIndex = 0;
    while (*Cursor != '\n')
    {
        Buffer_Out[BufferIndex++] = *Cursor++;
    }
    
    return true;
}

inline char *
ReadInteger(char *Str, i32 *Integer_Out)
{
    char *Cursor = Str;
    Cursor = SkipSpaces(Cursor);
    
    int Sign = 1;
    if (*Cursor == '-')
    {
        Sign = -1;
        Cursor += 1;
    }
    
    int Integer = 0;
    while (*Cursor >= '0' && *Cursor <= '9')
    {
        int Digit = *Cursor++ - '0';
        Integer = Integer * 10 + Digit;
    }
    
    *Integer_Out = Sign * Integer;
    return Cursor;
}

inline char *
ReadFloat(char *Str, f32 *Float_Out)
{
    char *Cursor = Str;
    Cursor = SkipSpaces(Cursor);
    
    f32 Sign = 1.0f;
    if (*Cursor == '-')
    {
        Sign = -1.0f;
        Cursor += 1;
    }
    
    int WholeNum = 0;
    f32 DeciNum = 0.0f;
    
    while (*Cursor >= '0' && *Cursor <= '9')
    {
        int Digit = *Cursor++ - '0';
        WholeNum = 10 * WholeNum + Digit;
    }
    
    if (*Cursor == '.')
    {
        Cursor += 1;
        
        f32 Weight = 0.1f;
        while (*Cursor >= '0' && *Cursor <= '9')
        {
            int Digit = *Cursor++ - '0';
            DeciNum += Weight * (f32)Digit;
            Weight *= 0.1;
        }
    }
    
    //NOTE(chen): scientific notation
    f32 E = 1.0f;
    if (*Cursor == 'e' || *Cursor == 'E')
    {
        Cursor += 1;
        
        int Exponent = 0;
        Cursor = ReadInteger(Cursor, &Exponent);
        E = powf(10.0f, (f32)Exponent);
    }
    
    *Float_Out = Sign * ((f32)WholeNum + DeciNum) * E;
    return Cursor;
}

inline b32
ParseFloat(char *Cursor, char *Prefix, f32 *Float_Out)
{
    Cursor = SkipSpaces(Cursor);
    EXPECT_STR(Cursor, Prefix);
    Cursor = SkipSpaces(Cursor);
    
    Cursor = ReadFloat(Cursor, Float_Out);
    
    return true;
}

inline b32
ParseV3(char *Cursor, char *Prefix, v3 *V_Out)
{
    Cursor = SkipSpaces(Cursor);
    EXPECT_STR(Cursor, Prefix);
    Cursor = SkipSpaces(Cursor);
    
    for (int I = 0; I < 3; ++I)
    {
        Cursor = ReadFloat(Cursor, V_Out->Data + I);
    }
    
    return true;
}

inline b32 
ParseFaceWithTexCoord(char *Cursor, int *VertexIndices, int *NormalIndices)
{
    Cursor = SkipSpaces(Cursor);
    EXPECT_CHAR(Cursor, 'f');
    
    for (int PointIndex = 0; PointIndex < 3; ++PointIndex)
    {
        Cursor = SkipSpaces(Cursor);
        
        int VertexIndex, TexIndex, NormalIndex;
        Cursor = ReadInteger(Cursor, &VertexIndex);
        EXPECT_CHAR(Cursor, '/');
        Cursor = ReadInteger(Cursor, &TexIndex);
        EXPECT_CHAR(Cursor, '/');
        Cursor = ReadInteger(Cursor, &NormalIndex);
        
        VertexIndices[PointIndex] = VertexIndex;
        NormalIndices[PointIndex] = NormalIndex;
    }
    
    return true;
}

#undef EXPECT_STR
#undef EXPECT_CHAR

internal obj_model
LoadObj(char *Path, memory_arena *Arena)
{
    obj_model Result = {};
    
#if 0
    //NOTE(chen): check for cache
    {
        char ObjCachePath[255];
        snprintf(ObjCachePath, sizeof(ObjCachePath), "%s.cache", Path);
        
        FILE *CacheFile = fopen(ObjCachePath, "rb");
        if (CacheFile)
        {
            Result = LoadObjCache(CacheFile, &GlobalTempArena);
            fclose(CacheFile);
            
            if (Result.VertexCount != 0)
            {
                return Result;
            }
        }
    }
#endif
    
    char MtlPath[255];
    snprintf(MtlPath, sizeof(MtlPath), "%s.mtl", Path);
    char ObjPath[255];
    snprintf(ObjPath, sizeof(ObjPath), "%s.obj", Path);
    
    material Mats[200] = {};
    int MatCount = 0;
    
    char *MtlFileContent = ReadFileTemporarily(MtlPath);
    if (MtlFileContent)
    {
        char *MtlFileWalker = MtlFileContent;
        
        while (*MtlFileWalker)
        {
            if (StartsWith(MtlFileWalker, "newmtl"))
            {
                material NewMat = {};
                ParseString(MtlFileWalker, "newmtl", NewMat.Name);
                ASSERT(MatCount < ARRAY_COUNT(Mats));
                Mats[MatCount++] = NewMat;
            }
            else if (StartsWith(MtlFileWalker, "Kd"))
            {
                ASSERT(MatCount > 0);
                
                v3 Albedo3 = {};
                ParseV3(MtlFileWalker, "Kd", &Albedo3);
                Mats[MatCount-1].Albedo.R = Albedo3.R;
                Mats[MatCount-1].Albedo.G = Albedo3.G;
                Mats[MatCount-1].Albedo.B = Albedo3.B;
                Mats[MatCount-1].Albedo.A = 1.0f;
            }
            else if (StartsWith(MtlFileWalker, "d"))
            {
                ASSERT(MatCount > 0);
                ParseFloat(MtlFileWalker, "d", &Mats[MatCount-1].Albedo.A);
            }
            else if (StartsWith(MtlFileWalker, "Ke"))
            {
                ASSERT(MatCount > 0);
                ParseV3(MtlFileWalker, "Ke", &Mats[MatCount-1].Emission);
            }
            
            MtlFileWalker = GotoNextLine(MtlFileWalker);
        }
    }
    
    char *ObjFileContent = ReadFileTemporarily(ObjPath);
    ASSERT(ObjFileContent);
    char *ObjFileWalker = ObjFileContent;
    
    int TempVertexCount = 0;
    int TempNormalCount = 0;
    int FaceCount = 0;
    while (*ObjFileWalker)
    {
        if (StartsWith(ObjFileWalker, "vn"))
        {
            TempNormalCount += 1;
        }
        else if (StartsWith(ObjFileWalker, "v"))
        {
            TempVertexCount += 1;
        }
        else if (StartsWith(ObjFileWalker, "f"))
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
    int AlphaVertexCount = 0;
    
    int CurrentMatIndex = -1;
    ObjFileWalker = ObjFileContent;
    while (*ObjFileWalker)
    {
        if (StartsWith(ObjFileWalker, "vn"))
        {
            v3 Normal = {};
            ParseV3(ObjFileWalker, "vn", &Normal);
            TempNormals[TempNormalCursor++] = Normal;
        }
        else if (StartsWith(ObjFileWalker, "v"))
        {
            v3 Vertex = {};
            ParseV3(ObjFileWalker, "v", &Vertex);
            TempVertices[TempVertexCursor++] = Vertex;
        }
        else if (StartsWith(ObjFileWalker, "f"))
        {
            //NOTE(chen): discards faces with alpha less than 1
            b32 FaceIsTransparent = (CurrentMatIndex != -1 &&
                                     Mats[CurrentMatIndex].Albedo.A < 0.9f);
            FaceIsTransparent = false;
            
            if (!FaceIsTransparent)
            {
                int VertexIndices[3] = {};
                int NormalIndices[3] = {};
                
                b32 ParsedFace = ParseFaceWithTexCoord(ObjFileWalker, VertexIndices, NormalIndices);
                ASSERT(ParsedFace);
                
                for (int VI = 0; VI < 3; ++VI)
                {
                    //NOTE(chen): negative index wraps
                    if (VertexIndices[VI] < 0)
                    {
                        VertexIndices[VI] += TempVertexCount;
                    }
                    else
                    {
                        //NOTE(chen): OBJ is 1-based, making it 0-based
                        VertexIndices[VI] -= 1;
                    }
                    
                    //NOTE(chen): negative index wraps
                    if (NormalIndices[VI] < 0)
                    {
                        NormalIndices[VI] += TempNormalCount;
                    }
                    else
                    {
                        //NOTE(chen): OBJ is 1-based, making it 0-based
                        NormalIndices[VI] -= 1;
                    }
                    
                    ASSERT(VertexIndices[VI] >= 0 && VertexIndices[VI] < TempVertexCount);
                    ASSERT(NormalIndices[VI] >= 0 && NormalIndices[VI] < TempNormalCount);
                    
                    Result.Vertices[VertexCursor].P = TempVertices[VertexIndices[VI]];
                    Result.Vertices[VertexCursor].N = TempNormals[NormalIndices[VI]];
                    
                    if (CurrentMatIndex != -1)
                    {
                        Result.Vertices[VertexCursor].Albedo = V3(Mats[CurrentMatIndex].Albedo);
                        Result.Vertices[VertexCursor].Emission = Mats[CurrentMatIndex].Emission;
                    }
                    else
                    {
                        //NOTE(chen): default material
                        Result.Vertices[VertexCursor].Albedo = V3(0.64f);
                        Result.Vertices[VertexCursor].Emission = V3(0.0f);
                    }
                    
                    VertexCursor += 1;
                }
            }
            else
            {
                AlphaVertexCount += 3;
            }
        }
        else if (StartsWith(ObjFileWalker, "usemtl"))
        {
            char MtlName[255];
            ParseString(ObjFileWalker, "usemtl", MtlName);
            
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
    ASSERT(VertexCursor + AlphaVertexCount == Result.VertexCount);
    Result.VertexCount -= AlphaVertexCount;
    
#if 0
    char ObjCachePath[255];
    snprintf(ObjCachePath, sizeof(ObjCachePath), "%s.cache", Path);
    WriteObjCache(ObjCachePath, Result);
#endif
    
    return Result;
}
