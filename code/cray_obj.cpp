#include <stdio.h>
#include <stdlib.h>

#define sscanf DONT_USE_SSCANF_BAD_BAD

internal char *
ReadFile(char *FilePath)
{
    char *Buffer = 0;
    
    FILE *File = fopen(FilePath, "rb");
    if (File)
    {
        fseek(File, 0, SEEK_END);
        int FileSize = ftell(File);
        rewind(File);
        
        Buffer = (char *)malloc(FileSize+1);
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
            Weight *= 0.1f;
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

internal vertex *
LoadObj(char *Path)
{
    vertex *Vertices = {};
    
    char MtlPath[255];
    snprintf(MtlPath, sizeof(MtlPath), "%s.mtl", Path);
    char ObjPath[255];
    snprintf(ObjPath, sizeof(ObjPath), "%s.obj", Path);
    
    material *Mats = 0;
    
    char *MtlFileContent = ReadFile(MtlPath);
    if (MtlFileContent)
    {
        char *MtlFileWalker = MtlFileContent;
        
        while (*MtlFileWalker)
        {
            if (StartsWith(MtlFileWalker, "newmtl"))
            {
                material NewMat = {};
                ParseString(MtlFileWalker, "newmtl", NewMat.Name);
                BufPush(Mats, NewMat);
            }
            else if (StartsWith(MtlFileWalker, "Kd"))
            {
                ASSERT(BufCount(Mats) > 0);
                
                v3 Albedo3 = {};
                ParseV3(MtlFileWalker, "Kd", &Albedo3);
                BufLast(Mats).Albedo.R = Albedo3.R;
                BufLast(Mats).Albedo.G = Albedo3.G;
                BufLast(Mats).Albedo.B = Albedo3.B;
                BufLast(Mats).Albedo.A = 1.0f;
            }
            else if (StartsWith(MtlFileWalker, "d"))
            {
                ASSERT(BufCount(Mats) > 0);
                ParseFloat(MtlFileWalker, "d", &BufLast(Mats).Albedo.A);
            }
            else if (StartsWith(MtlFileWalker, "Ke"))
            {
                ASSERT(BufCount(Mats) > 0);
                ParseV3(MtlFileWalker, "Ke", &BufLast(Mats).Emission);
            }
            
            MtlFileWalker = GotoNextLine(MtlFileWalker);
        }
    }
    free(MtlFileContent);
    
    char *ObjFileContent = ReadFile(ObjPath);
    if (!ObjFileContent)
    {
        Panic("couldn't load OBJ file with the given path %s", ObjPath);
    }
    char *ObjFileWalker = ObjFileContent;
    
    v3 *TempVertices = 0;
    v3 *TempNormals = 0;
    
    Vertices = 0;
    int AlphaVertexCount = 0;
    
    int CurrentMatIndex = -1;
    ObjFileWalker = ObjFileContent;
    while (*ObjFileWalker)
    {
        if (StartsWith(ObjFileWalker, "vn"))
        {
            v3 Normal = {};
            ParseV3(ObjFileWalker, "vn", &Normal);
            BufPush(TempNormals, Normal);
        }
        else if (StartsWith(ObjFileWalker, "v"))
        {
            v3 Vertex = {};
            ParseV3(ObjFileWalker, "v", &Vertex);
            BufPush(TempVertices, Vertex);
        }
        else if (StartsWith(ObjFileWalker, "f"))
        {
            //NOTE(chen): discards faces with alpha less than 1
            b32 FaceIsTransparent = (CurrentMatIndex != -1 &&
                                     Mats[CurrentMatIndex].Albedo.A < 0.9f);
            
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
                        VertexIndices[VI] += (int)BufCount(TempVertices);
                    }
                    else
                    {
                        //NOTE(chen): OBJ is 1-based, making it 0-based
                        VertexIndices[VI] -= 1;
                    }
                    
                    //NOTE(chen): negative index wraps
                    if (NormalIndices[VI] < 0)
                    {
                        NormalIndices[VI] += (int)BufCount(TempNormals);
                    }
                    else
                    {
                        //NOTE(chen): OBJ is 1-based, making it 0-based
                        NormalIndices[VI] -= 1;
                    }
                    
                    ASSERT(VertexIndices[VI] >= 0 && VertexIndices[VI] < BufCount(TempVertices));
                    ASSERT(NormalIndices[VI] >= 0 && NormalIndices[VI] < BufCount(TempNormals));
                    
                    vertex NewVertex = {};
                    
                    NewVertex.P = TempVertices[VertexIndices[VI]];
                    NewVertex.N = TempNormals[NormalIndices[VI]];
                    
                    if (CurrentMatIndex != -1)
                    {
                        NewVertex.Albedo = V3(Mats[CurrentMatIndex].Albedo);
                        NewVertex.Emission = Mats[CurrentMatIndex].Emission;
                    }
                    else
                    {
                        //NOTE(chen): default material
                        NewVertex.Albedo = V3(0.64f);
                        NewVertex.Emission = V3(0.0f);
                    }
                    
                    BufPush(Vertices, NewVertex);
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
            for (int MatIndex = 0; MatIndex < BufCount(Mats); ++MatIndex)
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
    free(ObjFileContent);
    
    return Vertices;
}
