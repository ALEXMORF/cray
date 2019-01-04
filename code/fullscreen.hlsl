struct vertex_in
{
    uint ID: SV_VertexID;
};

struct vertex_out
{
    float4 Position: SV_Position;
    float2 P: PIXEL_P;
    float2 TexCoord: TEXCOORD;
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
    
    Out.P = Out.Position.xy;
    float2 TexCoord = 0.5 * Out.Position.xy + 0.5;
    TexCoord.y = 1.0 - TexCoord.y;
    Out.TexCoord = TexCoord;
    
    return Out;
}