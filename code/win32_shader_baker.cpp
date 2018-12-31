#include <windows.h>
#include <stdio.h>
#include <string.h>

char *ReadEntireFile(char *Path)
{
    char *Result = 0;
    
    FILE *File = fopen(Path, "rb");
    if (File)
    {
        fseek(File, 0, SEEK_END);
        int FileSize = ftell(File);
        rewind(File);
        
        Result = (char *)calloc(FileSize+1, 1);
        fread(Result, 1, FileSize, File);
        
        fclose(File);
    }
    
    return Result;
}

int main()
{
    char *BakedFilename = "../code/cray_gl_shader_code.h";
    
    printf("baking shader code into %s\n", BakedFilename);
    
    FILE *BakedFile = fopen(BakedFilename, "wb");
    char *Header = "#pragma once\n\n";
    fwrite(Header, 1, strlen(Header), BakedFile);
    
    WIN32_FIND_DATA entry;
    HANDLE find = FindFirstFile("../code/*.*", &entry);
    if (find != INVALID_HANDLE_VALUE)
    {
        do 
        {
            if (entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) 
            {
                //NOTE(chen): directory
            } 
            else 
            {
                if (strcmp("glsl", entry.cFileName + strlen(entry.cFileName) - 4) == 0)
                {
                    char FullPath[255];
                    snprintf(FullPath, sizeof(FullPath), "../code/%s", entry.cFileName);
                    char *SourceCode = ReadEntireFile(FullPath);
                    
                    char *Filename = strdup(entry.cFileName);
                    Filename[strlen(Filename) - 5] = 0;
                    
                    char *Prefix = "global_variable char *";
                    char *Assignment = " = ";
                    char *HereStringBegin = "R\"(";
                    char *HereStringEnd = ")\";\n\n";
                    
                    fwrite(Prefix, 1, strlen(Prefix), BakedFile);
                    fwrite(Filename, 1, strlen(Filename), BakedFile);
                    fwrite(Assignment, 1, strlen(Assignment), BakedFile);
                    fwrite(HereStringBegin, 1, strlen(HereStringBegin), BakedFile);
                    fwrite(SourceCode, 1, strlen(SourceCode), BakedFile);
                    fwrite(HereStringEnd, 1, strlen(HereStringEnd), BakedFile);
                }
            }
        } while (FindNextFile(find, &entry));
        
        FindClose(find);
    }
    
    fclose(BakedFile);
    return 0;
}