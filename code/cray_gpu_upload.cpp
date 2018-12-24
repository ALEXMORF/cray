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
    
    int ModelCount = 0;
    obj_model Models[200] = {};
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/bunny", BunnyXForm);
    Models[ModelCount++] = InstantiateObjTemporarily("../data/monkey", MonkeyXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/sphinx", SphinxXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/light_room", RoomXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/tiger", TigerXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/moose", MooseXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/bigmouth", BigMouthXForm);
    //Models[ModelCount++] = InstantiateObjTemporarily("../data/big_scene", Mat4Identity());
    
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
            Triangles[TriIndex].Albedo = Vertices[VertexCursor].Albedo;
            
            Triangles[TriIndex].A = Vertices[VertexCursor++].P;
            Triangles[TriIndex].B = Vertices[VertexCursor++].P;
            Triangles[TriIndex].C = Vertices[VertexCursor++].P;
        }
    }
    
    linear_bvh BVH = ConstructLinearBVH(Triangles, TriangleCount, 
                                        &GlobalTempArena);
    
    //NOTE(chen): upload triangles onto SSBO
    GLuint TriangleSSBO = 0;
    glGenBuffers(1, &TriangleSSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, TriangleSSBO);
    glBufferData(GL_SHADER_STORAGE_BUFFER, 
                 TriangleCount * sizeof(packed_triangle), 
                 Triangles, GL_STATIC_DRAW);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, TriangleSSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); 
    
    //NOTE(chen): upload BVH onto SSBO
    GLuint BvhSSBO = 0;
    glGenBuffers(1, &BvhSSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, BvhSSBO);
    glBufferData(GL_SHADER_STORAGE_BUFFER, 
                 BVH.Count * sizeof(bvh_entry), 
                 BVH.Data, GL_STATIC_DRAW);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, BvhSSBO);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0); 
    
    Uploaded.TriangleCount = TriangleCount;
    
    return Uploaded;
}