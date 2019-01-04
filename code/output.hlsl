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

Texture2D HDRInputTex: register(t2);

SamplerState NearestSampler
{
    Filter = MIN_MAG_NEAREST;
    AddressU = Clamp;
    AddressV = Clamp;
};

struct pixel
{
    float4 Position: SV_Position;
    float2 P: PIXEL_P;
    float2 TexCoord: TEXCOORD;
};

float4 main(pixel Pixel): SV_TARGET
{
    float3 Col = HDRInputTex.Sample(NearestSampler, Pixel.TexCoord).rgb;
    
    Col = 1.0 - exp(-Exposure * Col);
    Col = sqrt(Col);
    
    return float4(Col, 1.0);
}