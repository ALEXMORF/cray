cbuffer Context: register(b2)
{
    float Time;
    int SampleCountSoFar;
    float AspectRatio;
    uint Pad;
    float2 RandSeed;
    
    float4x4 View;
    float4x4 Projection;
};

struct vertex_in
{
    float3 Position: POS;
    float3 Normal: NORMAL;
    float3 Albedo: ALBEDO;
    float3 Emission: EMISSION;
};

struct vertex_out
{
    float4 D3D_Position: SV_Position;
    float3 Position: POS;
    float3 Normal: NORMAL;
    float3 Albedo: ALBEDO;
    float3 Emission: EMISSION;
};

vertex_out vsmain(vertex_in In)
{
    vertex_out Out;
    
    Out.D3D_Position = mul(mul(float4(In.Position, 1.0), View), Projection);
    Out.Position = In.Position;
    Out.Normal = In.Normal;
    Out.Albedo = In.Albedo;
    Out.Emission = In.Emission;
    
    return Out;
}

struct pixel_out
{
    float3 Position: SV_Target0;
    float3 Normal: SV_Target1;
    float3 Albedo: SV_Target2;
    float3 Emission: SV_Target3;
};

pixel_out psmain(vertex_out In)
{
    pixel_out Out;
    
    Out.Position = In.Position;
    Out.Normal = normalize(In.Normal);
    Out.Albedo = In.Albedo;
    Out.Emission = In.Emission;
    
    return Out;
}