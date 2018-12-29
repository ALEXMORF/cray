#pragma once

global_variable char *blit_frag = R"(#version 440 core

uniform float Exposure;
uniform sampler2D HdrTex;

in vec3 FragP;
out vec3 FragColor;

void main()
{
    vec3 Radiance = texture(HdrTex, FragP.xy).rgb;
    
    Radiance = 1.0-exp(-Exposure*Radiance);
    Radiance = sqrt(Radiance);
    
    FragColor = Radiance;
})";

global_variable char *fullscreen_vert = R"(#version 440 core

layout(location = 0) in vec3 Position;

out vec3 FragP;

void main()
{
    FragP = Position;
    gl_Position = vec4(2.0 * Position - 1.0, 1.0);
})";

global_variable char *gbuffer_frag = R"(#version 440 core

in vec3 FragP;
in vec3 FragN;
in vec3 FragAlbedo;
in vec3 FragEmission;

layout(location = 0) out vec3 OutPosition;
layout(location = 1) out vec3 OutNormal;
layout(location = 2) out vec3 OutAlbedo;
layout(location = 3) out vec3 OutEmission;

void main()
{
    OutPosition = FragP;
    OutNormal = normalize(FragN);
    OutAlbedo = FragAlbedo;
    OutEmission = FragEmission;
})";

global_variable char *geom_vert = R"(#version 440 core

uniform mat4 View;
uniform mat4 Projection;

layout(location = 0) in vec3 Position;
layout(location = 1) in vec3 Normal;
layout(location = 2) in vec3 Albedo;
layout(location = 3) in vec3 Emission;

out vec3 FragP;
out vec3 FragN;
out vec3 FragAlbedo;
out vec3 FragEmission;

void main()
{
    FragP = Position;
    FragN = Normal;
    FragAlbedo = Albedo;
    FragEmission = Emission;
    gl_Position = vec4(Position, 1.0) * View * Projection;
})";

global_variable char *sample_frag = R"(#version 440 core

#define DEBUG_SHADER 0
#define TIMEOUT_SHADER 0
#define TIMEOUT_LIMIT 20

uniform sampler2D PositionTex;
uniform sampler2D NormalTex;
uniform sampler2D AlbedoTex;
uniform sampler2D EmissionTex;

uniform sampler2D PrevSamplesTex;
uniform int SampleCountSoFar;

uniform bool RasterizeFirstBounce;
uniform int MaxBounceCount;
uniform bool EnableGroundPlane;

uniform float FOV;
uniform vec3 CamP;
uniform vec3 CamLookAt;
uniform vec3 L;
uniform vec3 SunRadiance;
uniform vec3 Zenith;
uniform vec3 Azimuth;
uniform float Time;
uniform float AspectRatio;

uniform int TriangleCount;
uniform int BvhEntryCount;

struct triangle
{
    vec3 A;
    vec3 B;
    vec3 C;
    vec3 N;
    vec3 Albedo;
    vec3 Emission;
};

layout(std430, binding = 0) buffer TriBuffer
{
    triangle Triangles[];
};

struct bvh_entry
{
    vec3 Bound[2];
    
    int Offset; //NOTE(chen): Offset of either second child or primitive
    int PrimitiveCount;
    int Axis;
};

layout(std430, binding = 1) buffer BvhBuffer
{
    bvh_entry BvhEntries[];
};

in vec3 FragP;
out vec3 FragColor;

#define T_MIN 0.0001
#define T_MAX 10e31
#define Pi 3.1415926

vec2 GlobalSeed = FragP.xy*(Time+1.0);

vec2 Rand2() {
    GlobalSeed += vec2(-1,1);
	// implementation based on: lumina.sourceforge.net/Tutorials/Noise.html
    return vec2(fract(sin(dot(GlobalSeed.xy ,vec2(12.9898,78.233))) * 43758.5453),
                fract(cos(dot(GlobalSeed.xy ,vec2(4.898,7.23))) * 23421.631));
};

struct sphere
{
    float Radius;
    vec3 P;
    vec3 Albedo;
};

struct contact_info
{
    float T;
    vec3 N;
    vec3 Albedo;
    vec3 Emission;
};

contact_info ReadGBuffer()
{
    contact_info Res;
    
    Res.Emission = texture(EmissionTex, FragP.xy).rgb;
    Res.Albedo = texture(AlbedoTex, FragP.xy).rgb;
    Res.N = texture(NormalTex, FragP.xy).xyz;
    vec3 HitP = texture(PositionTex, FragP.xy).xyz;
    HitP += (0.001 + T_MIN) * Res.N;
    
    if (Res.N != vec3(0))
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

float RayIntersectSphere(in vec3 Ro, in vec3 Rd, float Radius)
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

float RayIntersectPlane(in vec3 Ro, in vec3 Rd, in vec3 N, in float C)
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

float RayIntersectTriangle(in vec3 Ro, in vec3 Rd, 
                           in vec3 A, in vec3 B, in vec3 C)
{
    vec3 AC = C - A;
    vec3 BC = C - B;
    vec3 RoC = C - Ro;
    
    vec3 N = cross(AC, BC);
    vec3 Q = cross(Rd, RoC);
    
    float InvDet = 1.0 / dot(Rd, N);
    float T = InvDet * dot(RoC, N);
    float U = InvDet * dot(BC, Q);
    float V = InvDet * dot(AC, -Q);
    
    if (U < 0.0 || U > 1.0 || V < 0.0 || (U+V) > 1.0) return -1.0;
    return T;
}

//TODO(chen): need to handle div by zero?
float RayIntersectBound(in vec3 Ro, in vec3 Rd, in vec3 Bound[2])
{
    vec3 InvRd = 1.0 / Rd;
    
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

contact_info RaytraceGroundPlane(in vec3 Ro, in vec3 Rd)
{
    contact_info Hit;
    
    Hit.T = RayIntersectPlane(Ro, Rd, vec3(0,1,0), 0);
    Hit.Albedo = vec3(0.5);
    Hit.N = vec3(0, 1, 0);
    Hit.Emission = vec3(0);
    
    return Hit;
}

contact_info Raytrace(in vec3 Ro, in vec3 Rd)
{
    contact_info Res;
    Res.T = T_MAX;
    Res.Emission = vec3(0);
    
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
        
        float BoundT = RayIntersectBound(Ro, Rd, BvhEntries[CurrIndex].Bound);
        if (BoundT < Res.T && BoundT != T_MAX)
        {
            if (BvhEntries[CurrIndex].PrimitiveCount == -1)
            {
                if (Rd[BvhEntries[CurrIndex].Axis] >= 0.0)
                {
                    NodesToVisit[ToVisitOffset++] = BvhEntries[CurrIndex].Offset;
                    CurrIndex = CurrIndex + 1;
                }
                else
                {
                    NodesToVisit[ToVisitOffset++] = CurrIndex + 1;
                    CurrIndex = BvhEntries[CurrIndex].Offset;
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
                int StartOffset = BvhEntries[CurrIndex].Offset;
                int EndOffset = (StartOffset + 
                                 BvhEntries[CurrIndex].PrimitiveCount);
                
#if TIMEOUT_SHADER
                TriTestCount += BvhEntries[CurrIndex].PrimitiveCount;
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
                                                   Triangles[TriIndex].A,
                                                   Triangles[TriIndex].B,
                                                   Triangles[TriIndex].C);
                    if (T > T_MIN && T < Res.T)
                    {
                        Res.T = T;
                        Res.Albedo = Triangles[TriIndex].Albedo;
                        Res.Emission = Triangles[TriIndex].Emission;
                        Res.N = Triangles[TriIndex].N;
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

vec3 SampleBvh(in vec3 Ro, in vec3 Rd)
{
    vec3 Acc = vec3(0.00);
    
    for (int EntryIndex = 0; EntryIndex < BvhEntryCount; ++EntryIndex)
    {
        float BoundT = RayIntersectBound(Ro, Rd, BvhEntries[EntryIndex].Bound);
        if (BoundT != T_MAX)
        {
            Acc.r += 0.01;
        }
    }
    
    return Acc;
}

vec3 Ortho(in vec3 X)
{
    vec3 Res;
    
    if (abs(dot(X, vec3(0,1,0))) < 0.99)
    {
        Res = normalize(cross(X, vec3(0, 1, 0)));
    }
    else
    {
        Res = normalize(cross(X, vec3(1, 0, 0)));
    }
    
    return Res;
}

vec3 SampleHemisphere(in vec3 N)
{
    vec3 X = Ortho(N);
    vec3 Y = cross(N, X);
    
    vec2 R = Rand2();
    float Radius = sqrt(R.x);
    float Theta = 2.0 * Pi * R.y;
    
    X *= Radius * cos(Theta);
    Y *= Radius * sin(Theta);
    return X + Y + N * sqrt(1.0 - Radius*Radius);
}

vec3 SampleCone(in vec3 N, in float Extent)
{
    vec3 X = Ortho(N);
    vec3 Y = cross(N, X);
    
    vec2 R = Rand2();
    float Theta = R.x * 2.0 * Pi;
    float Radius = sqrt(R.y * Extent);
    
    X *= Radius * cos(Theta);
    Y *= Radius * sin(Theta);
    return X + Y + N * sqrt(1.0 - Radius*Radius);
}

vec3 SampleEnvLight(in vec3 Rd)
{
    return mix(Azimuth, Zenith, clamp(Rd.y, 0.0, 1.0));
}

vec3 SampleDirectLight(in vec3 Ro, in vec3 N, in vec3 L)
{
    vec3 Radiance = vec3(0);
    
    vec3 LSample = SampleCone(L, 6e-5);
    float SunLightRatio = dot(LSample, N);
    if (SunLightRatio > 0.0 && Raytrace(Ro, LSample).T == T_MAX)
    {
        Radiance = SunLightRatio*SunRadiance;
    }
    
    return Radiance;
}

void main()
{
    vec3 AvgRadiance = vec3(0);
    
    vec2 UV = 2.0 * FragP.xy - 1.0;
    if (!RasterizeFirstBounce)
    {
        vec2 Delta = vec2(dFdx(UV.x), dFdy(UV.y));
        UV += Delta * (Rand2() - 0.5);
    }
    
    vec3 Ro = CamP;
    vec3 At = CamLookAt;
    vec3 CamZ = normalize(At - Ro);
    vec3 CamX = normalize(cross(vec3(0, 1, 0), CamZ));
    vec3 CamY = cross(CamZ, CamX);
    float CamZDist = 1.0 / tan(0.5 * FOV);
    vec3 Rd = normalize(AspectRatio * CamX * UV.x + CamY * UV.y + CamZDist * CamZ);
    
    vec3 Radiance = vec3(0);
    vec3 Attenuation = vec3(1);
    
    vec3 CurrRo = Ro;
    vec3 CurrRd = Rd;
    
    for (int BounceIndex = 0; BounceIndex < MaxBounceCount; ++BounceIndex)
    {
        contact_info Hit;
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
    
    int SampleCount = SampleCountSoFar + 1;
    float CurrSampleWeight = 1.0 / float(SampleCount);
    vec3 PrevSamplesAvg = texture(PrevSamplesTex, FragP.xy).rgb;
    vec3 SamplesAvg = ((1.0 - CurrSampleWeight) * PrevSamplesAvg + 
                       CurrSampleWeight * Radiance);
    FragColor = SamplesAvg;
})";

