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

internal vertices 
ConvertModelsToVertices(obj_model *Models, int ModelCount)
{
    vertices Result = {};
    
    for (int ModelIndex = 0; ModelIndex < ModelCount; ++ModelIndex)
    {
        Result.Count += Models[ModelIndex].VertexCount;
    }
    Result.Data = PushTempArray(Result.Count, vertex);
    
    int VertexCursor = 0;
    for (int ModelIndex = 0; ModelIndex < ModelCount; ++ModelIndex)
    {
        obj_model *Model = Models + ModelIndex;
        for (int VertIndex = 0; VertIndex < Model->VertexCount; ++VertIndex)
        {
            Result.Data[VertexCursor++] = Model->Vertices[VertIndex];
        }
    }
    
    return Result;
}

internal triangles
ConvertVerticesToTriangles(vertices Vertices)
{
    triangles Result = {};
    
    Result.Count = Vertices.Count / 3;
    Result.Data = PushTempArray(Result.Count, packed_triangle);
    
    int VertexCursor = 0;
    for (int TriIndex = 0; TriIndex < Result.Count; ++TriIndex)
    {
        packed_triangle *Triangle = Result.Data + TriIndex;
        
        Triangle->N = Normalize(Vertices.Data[VertexCursor].N);
        Triangle->Albedo = Vertices.Data[VertexCursor].Albedo;
        Triangle->Emission = Vertices.Data[VertexCursor].Emission;
        
        Triangle->A = Vertices.Data[VertexCursor++].P;
        Triangle->B = Vertices.Data[VertexCursor++].P;
        Triangle->C = Vertices.Data[VertexCursor++].P;
    }
    
    return Result;
}

internal GLuint
BindSSBO(int BindingIndex, void *Data, int Size)
{
    //NOTE(chen): upload triangles onto SSBO
    GLuint SSBO = 0;
    glGenBuffers(1, &SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSBO);
    glBufferData(GL_SHADER_STORAGE_BUFFER, Size, Data, GL_STATIC_DRAW);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, BindingIndex, SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); 
    
    return SSBO;
}

internal GLuint 
UploadToVAO(vertices Vertices)
{
    GLuint VAO = 0;
    
    GLuint VBO = 0;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, Vertices.Count*sizeof(vertex), 
                 Vertices.Data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 
                          sizeof(vertex), (void *)offsetof(vertex, P));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 
                          sizeof(vertex), (void *)offsetof(vertex, N));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 
                          sizeof(vertex), (void *)offsetof(vertex, Albedo));
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 
                          sizeof(vertex), (void *)offsetof(vertex, Emission));
    
    glBindVertexArray(0);
    
    glDeleteBuffers(1, &VBO);
    
    return VAO;
}

inline f32
CalcSecondsPassed(clock_t BeginClock)
{
    return (f32)(clock() - BeginClock) / (f32)CLOCKS_PER_SEC;
}

internal uploaded_data
UploadGeometryToGPU(char *ObjPath, mat4 XForm)
{
    uploaded_data Uploaded = {};
    
    clock_t BeginClock = clock();
    
    int ModelCount = 0;
    obj_model Models[200] = {};
    Models[ModelCount++] = InstantiateObjTemporarily(ObjPath, XForm);
    
    vertices Vertices = ConvertModelsToVertices(Models, ARRAY_COUNT(Models));
    triangles Triangles = ConvertVerticesToTriangles(Vertices);
    
    Uploaded.ModelLoadingTime = CalcSecondsPassed(BeginClock);
    
    BeginClock = clock();
    //NOTE(chen): BVH modifies the triangle array, therefore 
    //            triangles' SSBO binding must happen after 
    //            BVH's construction
    linear_bvh BVH = ConstructLinearBVH(Triangles.Data, 
                                        Triangles.Count, 
                                        &GlobalTempArena);
    Uploaded.BvhConstructionTime = CalcSecondsPassed(BeginClock);
    
    Uploaded.GeometryVAO = UploadToVAO(Vertices);
    Uploaded.TrianglesSSBO = BindSSBO(0, Triangles.Data, Triangles.Count*sizeof(packed_triangle));
    Uploaded.BvhSSBO = BindSSBO(1, BVH.Data, BVH.Count*sizeof(bvh_entry));
    Uploaded.GeometryVertexCount = Vertices.Count;
    Uploaded.TriangleCount = Triangles.Count;
    Uploaded.BvhEntryCount = BVH.Count;
    
    return Uploaded;
}

internal uploaded_data
UploadGeometryToGPU(model_prefab Prefab)
{
    return UploadGeometryToGPU(Prefab.Path, Prefab.XForm);
}

internal void
FreeUploadedData(uploaded_data Data)
{
    glDeleteVertexArrays(1, &Data.GeometryVAO);
    glDeleteBuffers(1, &Data.TrianglesSSBO);
    glDeleteBuffers(1, &Data.BvhSSBO);
}