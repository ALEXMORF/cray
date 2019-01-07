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
    
    Triangles = BufInit(BufCount(Vertices) / 3, triangle);
    
    int TriangleCursor = 0;
    int VertexCursor = 0;
    while (VertexCursor < BufCount(Vertices))
    {
        triangle *Triangle = Triangles + TriangleCursor;
        
        Triangle->N = Normalize(Vertices[VertexCursor].N);
        Triangle->Albedo = Vertices[VertexCursor].Albedo;
        Triangle->Emission = Vertices[VertexCursor].Emission;
        
        Triangle->A = Vertices[VertexCursor++].P;
        Triangle->B = Vertices[VertexCursor++].P;
        Triangle->C = Vertices[VertexCursor++].P;
        
        TriangleCursor += 1;
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
    bvh_entry *BVH = ConstructBVH(Triangles);
    LoadedModel.BvhConstructionTime = CalcSecondsPassed(BeginClock);
    
    LoadedModel.Vertices = Vertices;
    LoadedModel.Triangles = Triangles;
    LoadedModel.BVH = BVH;
    
    return LoadedModel;
}

internal loaded_model
LoadModel(model_prefab Prefab)
{
    return LoadModel(Prefab.Path, Prefab.XForm);
}

internal void
FreeModel(loaded_model Model)
{
    BufFree(Model.Vertices);
    BufFree(Model.Triangles);
    BufFree(Model.BVH);
}