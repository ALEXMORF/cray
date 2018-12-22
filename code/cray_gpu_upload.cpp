internal uploaded_data
UploadGeometryToGPU()
{
    uploaded_data Uploaded = {};
    
#if 0
    obj_model MonkeyModel = LoadObj("../data/monkey", &CRay->MainArena);
#else
    obj_model MonkeyModel = LoadObj("../data/lowpoly_monkey", &GlobalTempArena);
#endif
    
    //NOTE(chen): move it a bit
    for (int VertIndex = 0; VertIndex < MonkeyModel.VertexCount; ++VertIndex)
    {
        MonkeyModel.Vertices[VertIndex].P *= 0.5f;
        MonkeyModel.Vertices[VertIndex].P.Y += 0.6f;
        MonkeyModel.Vertices[VertIndex].P.Z *= -1.0f;
    }
    
    vertex *Vertices = MonkeyModel.Vertices;
    int VertexCursor = 0;
    int TriangleCount = MonkeyModel.VertexCount / 3;
    packed_triangle *Triangles = PushTempArray(TriangleCount, packed_triangle);
    for (int TriIndex = 0; TriIndex < TriangleCount; ++TriIndex)
    {
        Triangles[TriIndex].N = Vertices[VertexCursor].N;
        Triangles[TriIndex].A = Vertices[VertexCursor++].P;
        Triangles[TriIndex].B = Vertices[VertexCursor++].P;
        Triangles[TriIndex].C = Vertices[VertexCursor++].P;
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