struct _triangle
{
    float3 A;
    uint Pad1;
    float3 B;
    uint Pad2;
    float3 C;
    uint Pad3;
    float3 N;
    uint Pad4;
    float3 Albedo;
    uint Pad5;
    float3 Emission;
    uint Pad6;
};

struct bvh_entry
{
    //NOTE(chen): bound
    float3 BoundMin;
    uint Pad1;
    float3 BoundMax;
    uint Pad2;
    
    int Offset;
    int PrimitiveCount;
    int Axis;
    uint Pad3;
};

cbuffer Settings: register(b0)
{
    float Exposure;
    float FOV;
    bool RasterizeFirstBounce;
    int MaxBounceCount;
    bool EnableGroundPlane;
    
    float3 L;
    float3 SunRadiance;
    float3 Zenith;
    float3 Azimuth;
};

cbuffer Camera: register(b1)
{
    float3 CamP;
    float3 CamLookAt;
};

//TODO(chen): do register(tn) and register(bn) share binding slots?
StructuredBuffer<_triangle> Triangles: register(t0);
StructuredBuffer<bvh_entry> BVH: register(t1);

struct pixel
{
    float4 Position: SV_Position;
    float2 P: PIXEL_p;
};

float4 main(pixel Pixel): SV_TARGET
{
    _triangle FirstTriangle = Triangles.Load(0);
    float3 Col = FirstTriangle.Albedo;
    
    return float4(Col, 1.0f);
}