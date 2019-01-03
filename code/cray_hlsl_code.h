#pragma once

global_variable char *fullscreen = R"(struct vertex_in
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
})";

global_variable char *output = R"(cbuffer Settings: register(b0)
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
    float2 P: PIXEL_p;
};

float4 main(pixel Pixel): SV_TARGET
{
    float2 TexCoord = 0.5 * Pixel.P + 0.5;
    TexCoord.y = 1.0 - TexCoord.y;
    
    float3 Col = HDRInputTex.Sample(NearestSampler, TexCoord).rgb;
    
    Col = 1.0 - exp(-Exposure * Col);
    Col = sqrt(Col);
    
    return float4(Col, 1.0);
})";

global_variable char *sample = R"(#define DEBUG_SHADER 0
#define TIMEOUT_SHADER 0
#define TIMEOUT_LIMIT 20

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
    float4 Bound[2];
    
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
    
    float3 NotNormalizedL;
    float3 SunRadiance;
    float3 Zenith;
    float3 Azimuth;
};

cbuffer Camera: register(b1)
{
    float3 CamP;
    float3 CamLookAt;
};

cbuffer Context: register(b2)
{
    float Time;
    int SampleCountSoFar;
    float AspectRatio;
    uint Pad;
    
    float4x4 View;
    float4x4 Projection;
};

StructuredBuffer<_triangle> Triangles: register(t0);
StructuredBuffer<bvh_entry> BVH: register(t1);
Texture2D PrevSamplesTex: register(t2);

SamplerState NearestSampler
{
    Filter = MIN_MAG_NEAREST;
    AddressU = Clamp;
    AddressV = Clamp;
};

struct pixel
{
    float4 Position: SV_Position;
    float2 P: PIXEL_p;
};

#define T_MIN 0.0001
#define T_MAX 10e31
#define Pi 3.1415926

static float2 GlobalSeed;

float2 Rand2() {
    GlobalSeed += float2(-1,1);
	// implementation based on: lumina.sourceforge.net/Tutorials/Noise.html
    return float2(frac(sin(dot(GlobalSeed.xy ,float2(12.9898,78.233))) * 43758.5453),
                  frac(cos(dot(GlobalSeed.xy ,float2(4.898,7.23))) * 23421.631));
}

struct sphere
{
    float Radius;
    float3 P;
    float3 Albedo;
};

struct contact_info
{
    float T;
    float3 N;
    float3 Albedo;
    float3 Emission;
};

#if 0
contact_info ReadGBuffer()
{
    contact_info Res;
    
    Res.Emission = texture(EmissionTex, FragP.xy).rgb;
    Res.Albedo = texture(AlbedoTex, FragP.xy).rgb;
    Res.N = texture(NormalTex, FragP.xy).xyz;
    float3 HitP = texture(PositionTex, FragP.xy).xyz;
    HitP += (0.001 + T_MIN) * Res.N;
    
    if (Res.N != float3(0))
    {
        Res.T = length(HitP - CamP);
    }
    else
    {
        //NOTE(chen): if N = 0, the ray misses
        Res.T = -1.0; 
    }
    
    return Res;
}
#endif

float RayIntersectSphere(in float3 Ro, in float3 Rd, float Radius)
{
    float A = dot(Rd, Rd);
    float B = 2.0 * dot(Ro, Rd);
    float C = dot(Ro, Ro) - Radius*Radius;
    
    float Denom = 2.0 * A;
    float SqrtTerm = B*B - 4.0*A*C;
    if (Denom != 0.0 && SqrtTerm >= 0.0)
    {
        float Root1 = (-B + sqrt(SqrtTerm)) / Denom;
        float Root2 = (-B - sqrt(SqrtTerm)) / Denom;
        
        if (min(Root1, Root2) < T_MIN)
        {
            return max(Root1, Root2);
        }
        
        return min(Root1, Root2);
    }
    else
    {
        return T_MAX;
    }
}

float RayIntersectPlane(in float3 Ro, in float3 Rd, in float3 N, in float C)
{
    float Num = C - dot(Ro, N);
    float Denom = dot(Rd, N);
    
    if (Denom != 0.0)
    {
        return Num / Denom;
    }
    else
    {
        return T_MAX;
    }
}

float RayIntersectTriangle(in float3 Ro, in float3 Rd, 
                           in float3 A, in float3 B, in float3 C)
{
    float3 AC = C - A;
    float3 BC = C - B;
    float3 RoC = C - Ro;
    
    float3 N = cross(AC, BC);
    float3 Q = cross(Rd, RoC);
    
    float InvDet = 1.0 / dot(Rd, N);
    float T = InvDet * dot(RoC, N);
    float U = InvDet * dot(BC, Q);
    float V = InvDet * dot(AC, -Q);
    
    if (U < 0.0 || U > 1.0 || V < 0.0 || (U+V) > 1.0) return -1.0;
    return T;
}

//TODO(chen): need to handle div by zero?
float RayIntersectBound(in float3 Ro, in float3 Rd, in float4 Bound[2])
{
    float3 InvRd = 1.0 / Rd;
    
    float MinT, MaxT, MinTY, MaxTY, MinTZ, MaxTZ;
    
    if (InvRd.x >= 0.0)
    {
        MinT = (Bound[0].x - Ro.x) * InvRd.x;
        MaxT = (Bound[1].x - Ro.x) * InvRd.x;
    }
    else
    {
        MinT = (Bound[1].x - Ro.x) * InvRd.x;
        MaxT = (Bound[0].x - Ro.x) * InvRd.x;
    }
    
    if (InvRd.y >= 0.0)
    {
        MinTY = (Bound[0].y - Ro.y) * InvRd.y;
        MaxTY = (Bound[1].y - Ro.y) * InvRd.y;
    }
    else
    {
        MinTY = (Bound[1].y - Ro.y) * InvRd.y;
        MaxTY = (Bound[0].y - Ro.y) * InvRd.y;
    }
    
    if (MinTY > MaxT || MaxTY < MinT) return T_MAX;
    
    MinT = max(MinT, MinTY);
    MaxT = min(MaxT, MaxTY);
    
    if (InvRd.z >= 0.0)
    {
        MinTZ = (Bound[0].z - Ro.z) * InvRd.z;
        MaxTZ = (Bound[1].z - Ro.z) * InvRd.z;
    }
    else
    {
        MinTZ = (Bound[1].z - Ro.z) * InvRd.z;
        MaxTZ = (Bound[0].z - Ro.z) * InvRd.z;
    }
    
    if (MinTZ > MaxT || MaxTZ < MinT) return T_MAX;
    
    return max(MinT, MinTZ);
}

contact_info RaytraceGroundPlane(in float3 Ro, in float3 Rd)
{
    contact_info Hit;
    
    Hit.T = RayIntersectPlane(Ro, Rd, float3(0,1,0), 0);
    Hit.Albedo = float3(0.5, 0.5, 0.5);
    Hit.N = float3(0, 1, 0);
    Hit.Emission = float3(0, 0, 0);
    
    return Hit;
}

contact_info Raytrace(in float3 Ro, in float3 Rd)
{
    contact_info Res;
    Res.T = T_MAX;
    Res.Emission = float3(0, 0, 0);
    
    // plane
    if (EnableGroundPlane)
    {
        contact_info Hit = RaytraceGroundPlane(Ro, Rd);
        if (Hit.T > T_MIN && Hit.T < Res.T)
        {
            Res.T = Hit.T;
            Res.Albedo = Hit.Albedo;
            Res.N = Hit.N;
        }
    }
    
    int ToVisitOffset = 0;
    int NodesToVisit[32];
    int CurrIndex = 0;
    
#if TIMEOUT_SHADER
    int TriTestCount = 0;
#endif
    
    while (true)
    {
#if DEBUG_SHADER
        if (CurrIndex >= BvhEntryCount)
        {
            discard;
        }
#endif
        
#if TIMEOUT_SHADER
        if (TriTestCount < 0 || TriTestCount > TIMEOUT_LIMIT)
        {
            return Res;
        }
#endif
        
        float BoundT = RayIntersectBound(Ro, Rd, BVH.Load(CurrIndex).Bound);
        if (BoundT < Res.T && BoundT != T_MAX)
        {
            if (BVH.Load(CurrIndex).PrimitiveCount == -1)
            {
                if (Rd[BVH.Load(CurrIndex).Axis] >= 0.0)
                {
                    NodesToVisit[ToVisitOffset++] = BVH.Load(CurrIndex).Offset;
                    CurrIndex = CurrIndex + 1;
                }
                else
                {
                    NodesToVisit[ToVisitOffset++] = CurrIndex + 1;
                    CurrIndex = BVH.Load(CurrIndex).Offset;
                }
                
#if DEBUG_SHADER
                if (ToVisitOffset <= 0 || ToVisitOffset >= 32)
                {
                    discard;
                }
#endif
            }
            else
            {
                int StartOffset = BVH.Load(CurrIndex).Offset;
                int EndOffset = (StartOffset + 
                                 BVH.Load(CurrIndex).PrimitiveCount);
                
#if TIMEOUT_SHADER
                TriTestCount += BVH.Load(CurrIndex).PrimitiveCount;
#endif
                
                for (int TriIndex = StartOffset; 
                     TriIndex < EndOffset; 
                     ++TriIndex)
                {
#if DEBUG_SHADER
                    if (TriIndex < 0 || TriIndex > TriangleCount)
                    {
                        discard;
                    }
#endif
                    
                    float T = RayIntersectTriangle(Ro, Rd, 
                                                   Triangles.Load(TriIndex).A,
                                                   Triangles.Load(TriIndex).B,
                                                   Triangles.Load(TriIndex).C);
                    if (T > T_MIN && T < Res.T)
                    {
                        Res.T = T;
                        Res.Albedo = Triangles.Load(TriIndex).Albedo;
                        Res.Emission = Triangles.Load(TriIndex).Emission;
                        Res.N = Triangles.Load(TriIndex).N;
                    }
                }
                
#if DEBUG_SHADER
                if (ToVisitOffset < 0 || ToVisitOffset > 32)
                {
                    discard;
                }
#endif
                if (ToVisitOffset == 0) break;
                CurrIndex = NodesToVisit[--ToVisitOffset];
            }
        }
        else
        {
#if DEBUG_SHADER
            if (ToVisitOffset < 0 || ToVisitOffset > 32)
            {
                discard;
            }
#endif
            if (ToVisitOffset == 0) break;
            CurrIndex = NodesToVisit[--ToVisitOffset];
        }
    }
    
    return Res;
}

float3 Ortho(in float3 X)
{
    float3 Res;
    
    if (abs(dot(X, float3(0,1,0))) < 0.99)
    {
        Res = normalize(cross(X, float3(0, 1, 0)));
    }
    else
    {
        Res = normalize(cross(X, float3(1, 0, 0)));
    }
    
    return Res;
}

float3 SampleHemisphere(in float3 N)
{
    float3 X = Ortho(N);
    float3 Y = cross(N, X);
    
    float2 R = Rand2();
    float Radius = sqrt(R.x);
    float Theta = 2.0 * Pi * R.y;
    
    X *= Radius * cos(Theta);
    Y *= Radius * sin(Theta);
    return X + Y + N * sqrt(1.0 - Radius*Radius);
}

float3 SampleCone(in float3 N, in float Extent)
{
    float3 X = Ortho(N);
    float3 Y = cross(N, X);
    
    float2 R = Rand2();
    float Theta = R.x * 2.0 * Pi;
    float Radius = sqrt(R.y * Extent);
    
    X *= Radius * cos(Theta);
    Y *= Radius * sin(Theta);
    return X + Y + N * sqrt(1.0 - Radius*Radius);
}

float3 SampleEnvLight(in float3 Rd)
{
    return lerp(Azimuth, Zenith, clamp(Rd.y, 0.0, 1.0));
}

float3 SampleDirectLight(in float3 Ro, in float3 N, in float3 L)
{
    float3 Radiance = float3(0, 0, 0);
    
    float3 LSample = SampleCone(L, 6e-5);
    float SunLightRatio = dot(LSample, N);
    if (SunLightRatio > 0.0)
    {
        if (Raytrace(Ro, LSample).T == T_MAX)
        {
            Radiance = SunLightRatio*SunRadiance;
        }
    }
    return Radiance;
}

float4 main(pixel Pixel): SV_TARGET
{
    GlobalSeed = Pixel.P*(Time+1.0);
    
    float3 AvgRadiance = float3(0, 0, 0);
    
    float2 UV = Pixel.P;
    if (!RasterizeFirstBounce)
    {
        float2 Delta = float2(ddx(UV.x), ddy(UV.y));
        UV += Delta * (Rand2() - 0.5);
    }
    
    float3 Ro = CamP;
    float3 At = CamLookAt;
    float3 CamZ = normalize(At - Ro);
    float3 CamX = normalize(cross(float3(0, 1, 0), CamZ));
    float3 CamY = cross(CamZ, CamX);
    float CamZDist = 1.0 / tan(0.5 * FOV);
    float3 Rd = normalize(AspectRatio * CamX * UV.x + CamY * UV.y + CamZDist * CamZ);
    
    float3 L = normalize(NotNormalizedL);
    float3 Radiance = float3(0, 0, 0);
    float3 Attenuation = float3(1, 1, 1);
    
    float3 CurrRo = Ro;
    float3 CurrRd = Rd;
    
    for (int BounceIndex = 0; BounceIndex < MaxBounceCount; ++BounceIndex)
    {
        contact_info Hit = Raytrace(CurrRo, CurrRd);;
#if 0
        if (BounceIndex == 0 && RasterizeFirstBounce)
        {
            Hit = ReadGBuffer();
            if (EnableGroundPlane)
            {
                contact_info GroundHit = RaytraceGroundPlane(CurrRo, CurrRd);
                if (GroundHit.T > T_MIN && (Hit.T < T_MIN || GroundHit.T < Hit.T))
                {
                    Hit = GroundHit;
                }
            }
        }
        else
        {
            Hit = Raytrace(CurrRo, CurrRd);
        }
#endif
        
        if (Hit.T > T_MIN && Hit.T < T_MAX)
        {
            Radiance += Attenuation*Hit.Emission;
            Attenuation *= Hit.Albedo;
            CurrRo = CurrRo + (Hit.T - T_MIN) * CurrRd;
            
            Radiance += Attenuation * SampleDirectLight(CurrRo, Hit.N, L);
            CurrRd = SampleHemisphere(Hit.N);
        }
        else
        {
            Radiance += Attenuation * SampleEnvLight(CurrRd);
            break;
        }
    }
    
    float2 TexCoord = 0.5 * Pixel.P + 0.5;
    TexCoord.y = 1.0 - TexCoord.y;
    
    int SampleCount = SampleCountSoFar + 1;
    float CurrSampleWeight = 1.0 / float(SampleCount);
    float3 PrevSamplesAvg = PrevSamplesTex.Sample(NearestSampler, TexCoord).rgb;
    float3 SamplesAvg = ((1.0 - CurrSampleWeight) * PrevSamplesAvg + 
                         CurrSampleWeight * Radiance);
    
    return float4(SamplesAvg, 1.0f);
})";

