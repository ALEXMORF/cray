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
ConvertModelsToVertices(obj_model *Models, int ModelCount, 
                        memory_arena *Arena)
{
    vertices Result = {};
    
    for (int ModelIndex = 0; ModelIndex < ModelCount; ++ModelIndex)
    {
        Result.Count += Models[ModelIndex].VertexCount;
    }
    Result.Data = PushArray(Arena, Result.Count, vertex);
    
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
ConvertVerticesToTriangles(vertices Vertices, 
                           memory_arena *Arena)
{
    triangles Result = {};
    
    Result.Count = Vertices.Count / 3;
    Result.Data = PushArray(Arena, Result.Count, triangle);
    
    int VertexCursor = 0;
    for (int TriIndex = 0; TriIndex < Result.Count; ++TriIndex)
    {
        triangle *Triangle = Result.Data + TriIndex;
        
        Triangle->N = Normalize(Vertices.Data[VertexCursor].N);
        Triangle->Albedo = Vertices.Data[VertexCursor].Albedo;
        Triangle->Emission = Vertices.Data[VertexCursor].Emission;
        
        Triangle->A = Vertices.Data[VertexCursor++].P;
        Triangle->B = Vertices.Data[VertexCursor++].P;
        Triangle->C = Vertices.Data[VertexCursor++].P;
    }
    
    return Result;
}

internal loaded_model
LoadModel(char *ObjPath, mat4 XForm, memory_arena *Arena)
{
    loaded_model LoadedModel = {};
    
    clock_t BeginClock = clock();
    
    int ModelCount = 0;
    obj_model Models[200] = {};
    Models[ModelCount++] = InstantiateObjTemporarily(ObjPath, XForm);
    
    vertices Vertices = ConvertModelsToVertices(Models, ARRAY_COUNT(Models), Arena);
    triangles Triangles = ConvertVerticesToTriangles(Vertices, Arena);
    
    LoadedModel.ModelLoadingTime = CalcSecondsPassed(BeginClock);
    
    BeginClock = clock();
    //NOTE(chen): BVH modifies the triangle array, therefore 
    //            triangles' SSBO binding must happen after 
    //            BVH's construction
    linear_bvh BVH = ConstructLinearBVH(Triangles.Data, 
                                        Triangles.Count, 
                                        Arena);
    LoadedModel.BvhConstructionTime = CalcSecondsPassed(BeginClock);
    
    LoadedModel.Vertices = Vertices;
    LoadedModel.Triangles = Triangles;
    LoadedModel.BVH = BVH;
    LoadedModel.GeometryVertexCount = Vertices.Count;
    LoadedModel.TriangleCount = Triangles.Count;
    LoadedModel.BvhEntryCount = BVH.Count;
    
    return LoadedModel;
}

internal loaded_model
LoadModel(model_prefab Prefab, memory_arena *Arena)
{
    return LoadModel(Prefab.Path, Prefab.XForm, Arena);
}
