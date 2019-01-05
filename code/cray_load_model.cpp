internal vertex *
InstantiateObj(char *Path, mat4 XForm)
{
    vertex *Vertices = LoadObj(Path);
    
    for (int VertIndex = 0; VertIndex < BufCount(Vertices); ++VertIndex)
    {
        Vertices[VertIndex].P = ApplyMat4(Vertices[VertIndex].P, XForm);
        Vertices[VertIndex].N *= Mat3(XForm);
    }
    
    return Vertices;
}

internal triangle *
ConvertVerticesToTriangles(vertex *Vertices)
{
    triangle *Triangles = 0;
    
    int VertexCursor = 0;
    while (VertexCursor < BufCount(Vertices))
    {
        triangle NewTriangle = {};
        
        NewTriangle.N = Normalize(Vertices[VertexCursor].N);
        NewTriangle.Albedo = Vertices[VertexCursor].Albedo;
        NewTriangle.Emission = Vertices[VertexCursor].Emission;
        
        NewTriangle.A = Vertices[VertexCursor++].P;
        NewTriangle.B = Vertices[VertexCursor++].P;
        NewTriangle.C = Vertices[VertexCursor++].P;
        
        BufPush(Triangles, NewTriangle);
    }
    
    return Triangles;
}

internal loaded_model
LoadModel(char *ObjPath, mat4 XForm)
{
    loaded_model LoadedModel = {};
    
    clock_t BeginClock = clock();
    
    vertex *Vertices = InstantiateObj(ObjPath, XForm);
    triangle *Triangles = ConvertVerticesToTriangles(Vertices);
    
    LoadedModel.ModelLoadingTime = CalcSecondsPassed(BeginClock);
    
    BeginClock = clock();
    //NOTE(chen): BVH modifies the triangle array, therefore 
    //            triangles' SSBO binding must happen after 
    //            BVH's construction
    linear_bvh BVH = ConstructLinearBVH(Triangles, &GlobalTempArena);
    LoadedModel.BvhConstructionTime = CalcSecondsPassed(BeginClock);
    
    LoadedModel.Vertices = Vertices;
    LoadedModel.Triangles = Triangles;
    LoadedModel.BVH = BVH;
    LoadedModel.BvhEntryCount = BVH.Count;
    
    return LoadedModel;
}

internal loaded_model
LoadModel(model_prefab Prefab)
{
    return LoadModel(Prefab.Path, Prefab.XForm);
}
