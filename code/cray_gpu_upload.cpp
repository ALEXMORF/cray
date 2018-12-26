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

internal void
BindSSBO(int BindingIndex, void *Data, int Size)
{
    //NOTE(chen): upload triangles onto SSBO
    GLuint SSBO = 0;
    glGenBuffers(1, &SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, SSBO);
    glBufferData(GL_SHADER_STORAGE_BUFFER, Size, Data, GL_STATIC_DRAW);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, BindingIndex, SSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); 
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
    
    return VAO;
}

#include "cray_bvh.cpp"

internal uploaded_data
UploadGeometryToGPU()
{
    uploaded_data Uploaded = {};
    
    mat4 MonkeyXForm = Mat4Scale(0.5f) * Mat4RotateAroundY(Pi32) * Mat4Translate(0.0f, 0.6f, 0.0f);
    mat4 RoomXForm = Mat4RotateAroundY(Pi32) * Mat4Translate(0.0f, 0.0f, 4.0f);
    mat4 TigerXForm = Mat4RotateAroundY(1.15f*Pi32) * Mat4Translate(0.0f, 0.3f, 0.0f);
    mat4 MooseXForm = Mat4RotateAroundY(0.2f*Pi32) * Mat4Translate(1.0f, -0.02f, 0.0f);
    mat4 BigMouthXForm = Mat4RotateAroundY(0.7f*Pi32) * Mat4Translate(-1.0f, 0.0f, 0.0f);
    mat4 SphinxXForm = Mat4Scale(0.7f) * Mat4RotateAroundY(0.9f*Pi32) * Mat4Translate(0.0f, 0.0f, 1.0f);
    mat4 BunnyXForm = Mat4RotateAroundY(1.1f*Pi32) * Mat4Translate(0.0f, -0.1f, 0.0f);
    mat4 SerapisXForm = Mat4RotateAroundY(1.3f*Pi32) * Mat4Translate(0.0f, 0.0f, 0.0f);
    mat4 DragonXForm = Mat4Scale(2.0f);
    mat4 HeadXForm = Mat4Scale(2.0f) * Mat4RotateAroundY(1.0f*Pi32);
    
    int ModelCount = 0;
    obj_model Models[200] = {};
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/buddha", Mat4Identity());
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/head", HeadXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/dragon", DragonXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/bunny", BunnyXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/serapis", SerapisXForm);
    Models[ModelCount++] = InstantiateObjTemporarily("../data/monkey", MonkeyXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/sphinx", SphinxXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/light_room", RoomXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/tiger", TigerXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/moose", MooseXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/bigmouth", BigMouthXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/big_scene", Mat4Identity());
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/sponza", Mat4Identity());
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/conference", Mat4Identity());
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/sibenik", Mat4Identity());
    
    vertices Vertices = ConvertModelsToVertices(Models, ARRAY_COUNT(Models));
    triangles Triangles = ConvertVerticesToTriangles(Vertices);
    
    //NOTE(chen): BVH modifies the triangle array, therefore 
    //            triangles' SSBO binding must happen after 
    //            BVH's construction
    linear_bvh BVH = ConstructLinearBVH(Triangles.Data, 
                                        Triangles.Count, 
                                        &GlobalTempArena);
    BindSSBO(0, Triangles.Data, Triangles.Count*sizeof(packed_triangle));
    BindSSBO(1, BVH.Data, BVH.Count*sizeof(bvh_entry));
    
    Uploaded.GeometryVAO = UploadToVAO(Vertices);
    Uploaded.GeometryVertexCount = Vertices.Count;
    Uploaded.TriangleCount = Triangles.Count;
    Uploaded.BvhEntryCount = BVH.Count;
    
    return Uploaded;
}