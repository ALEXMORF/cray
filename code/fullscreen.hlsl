struct vertex_in
{
    uint ID: SV_VertexID;
};

struct vertex_out
{
    float4 Position: SV_Position;
    float2 PixelP: PIXEL_P;
};

vertex_out main(vertex_in In)
{
    vertex_out Out;
    
    if (In.ID == 0)
    {
        Out.Position = float4(-1.0f, -1.0f, 0.0f, 1.0f);
    }
    else if (In.ID == 1)
    {
        Out.Position = float4(3.0f, -1.0f, 0.0f, 1.0f);
    }
    else if (In.ID == 2)
    {
        Out.Position = float4(-1.0f, 3.0f, 0.0f, 1.0f);
    }
    
    Out.PixelP = float2(Out.Position.x, Out.Position.y);
    
    return Out;
}