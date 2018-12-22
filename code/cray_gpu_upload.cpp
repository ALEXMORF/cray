internal obj_model
InstantiateObjTemporarily(char *Path, mat4 XForm)
{
    obj_model Model = LoadObj(Path, &GlobalTempArena);
    
    for (int VertIndex = 0; VertIndex < Model.VertexCount; ++VertIndex)
    {
        Model.Vertices[VertIndex].P = ApplyMat4(Model.Vertices[VertIndex].P, XForm);
        Model.Vertices[VertIndex].N *= Mat3(XForm);
    }
    
    return Model;
}

internal uploaded_data
UploadGeometryToGPU()
{
    uploaded_data Uploaded = {};
    
    mat4 MonkeyXForm = Mat4Scale(0.5f) * Mat4RotateAroundY(Pi32) * Mat4Translate(0.0f, 0.5f, 0.0f);
    mat4 RoomXForm = Mat4RotateAroundY(Pi32) * Mat4Translate(0.0f, 0.0f, 4.0f);
    
    int ModelCount = 0;
    obj_model Models[200] = {};
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/lowpoly_monkey", MonkeyXForm);
    Models[ModelCount++] = InstantiateObjTemporarily("../data/light_room", RoomXForm);
    
    //NOTE(chen): push into vertices
    int VertexCount = 0;
    for (int ModelIndex = 0; ModelIndex < ModelCount; ++ModelIndex)
    {
        VertexCount += Models[ModelIndex].VertexCount;
    }
    vertex *Vertices = PushTempArray(VertexCount, vertex);
    {
        int VertexCursor = 0;
        
        for (int ModelIndex = 0; ModelIndex < ModelCount; ++ModelIndex)
        {
            obj_model *Model = Models + ModelIndex;
            for (int VertIndex = 0; VertIndex < Model->VertexCount; ++VertIndex)
            {
                Vertices[VertexCursor++] = Model->Vertices[VertIndex];
            }
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