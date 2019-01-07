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

