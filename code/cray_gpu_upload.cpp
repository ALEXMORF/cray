internal uploaded_data
UploadGeometryToGPU()
{
    uploaded_data Uploaded = {};
    
    obj_model MonkeyModel = LoadObj("../data/lowpoly_monkey", &GlobalTempArena);
    for (int VertIndex = 0; VertIndex < MonkeyModel.VertexCount; ++VertIndex)
    {
        MonkeyModel.Vertices[VertIndex].P *= 0.5f;
        MonkeyModel.Vertices[VertIndex].P.Y += 0.6f;
        MonkeyModel.Vertices[VertIndex].P.Z *= -1.0f;
    }
    
    obj_model RoomModel = LoadObj("../data/light_room", &GlobalTempArena);
    for (int VertIndex = 0; VertIndex < RoomModel.VertexCount; ++VertIndex)
    {
        RoomModel.Vertices[VertIndex].P.Z += 5.0f;
    }
    
    int VertexCount = MonkeyModel.VertexCount;
    vertex *Vertices = PushTempArray(VertexCount, vertex);
    {
        int VertexCursor = 0;
        for (int VertIndex = 0; VertIndex < MonkeyModel.VertexCount; ++VertIndex)
        {
            Vertices[VertexCursor++] = MonkeyModel.Vertices[VertIndex];
        }
    }
    
    int TriangleCount = VertexCount / 3;
    packed_triangle *Triangles = PushTempArray(TriangleCount, packed_triangle);
    {
        int VertexCursor = 0;
        for (int TriIndex = 0; TriIndex < TriangleCount; ++TriIndex)
        {
            Triangles[TriIndex].N = Normalize(Vertices[VertexCursor].N);
            Triangles[TriIndex].A = Vertices[VertexCursor++].P;
            Triangles[TriIndex].B = Vertices[VertexCursor++].P;
            Triangles[TriIndex].C = Vertices[VertexCursor++].P;
        }
    }
    
    //NOTE(chen): upload triangles onto SSBO
    GLuint SSBO = 0;
    glGenBuffers(1, &SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSBO);
    glBufferData(GL_SHADER_STORAGE_BUFFER, 
                 TriangleCount * sizeof(packed_triangle), 
                 Triangles, GL_STATIC_DRAW);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); 
    
    Uploaded.TriangleCount = TriangleCount;
    
    return Uploaded;
}