#version 440 core

uniform vec3 CamP;
uniform vec3 CamLookAt;
uniform float Time;
uniform float AspectRatio;

in vec3 FragP;
out vec3 FragColor;

#define T_MIN 0.0001
#define T_MAX 10e31
#define Pi 3.1415926

vec2 GlobalSeed = FragP.xy*(Time+1.0);

vec2 Rand2() {
    GlobalSeed+=vec2(-1,1);
	// implementation based on: lumina.sourceforge.net/Tutorials/Noise.html
    return vec2(fract(sin(dot(GlobalSeed.xy ,vec2(12.9898,78.233))) * 43758.5453),
                fract(cos(dot(GlobalSeed.xy ,vec2(4.898,7.23))) * 23421.631));
};

float Hash(in float Seed)
{
    return fract(7831.131*sin(517.131*Seed));
}

struct material
{
    vec3 Albedo;
    float Specular;
};

struct sphere
{
    float Radius;
    vec3 P;
    int MatID;
};

struct contact_info
{
    float T;
    vec3 N;
    int MatID;
};

#define SPHERE_COUNT 3

sphere Spheres[3];

void InitScene()
{
    Spheres[0].P = vec3(0, 0.5, 0);
    Spheres[0].Radius = 0.5;
    Spheres[0].MatID = 1;
    
    Spheres[1].P = vec3(1.0, 0.5, 0);
    Spheres[1].Radius = 0.5;
    Spheres[1].MatID = 3;
    
    Spheres[2].P = vec3(-1.0, 0.5, 0);
    Spheres[2].Radius = 0.5;
    Spheres[2].MatID = 2;
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

material MatLookup(in int MatID)
{
    if (MatID == 0)
    {
        return material(vec3(0.8), 0.0);
    }
    else if (MatID == 1)
    {
        return material(vec3(0.8, 0.8, 0.8), 0.0);
    }
    else if (MatID == 2)
    {
        return material(vec3(0.2, 0.8, 0.2), 0.0);
    }
    else if (MatID == 3)
    {
        return material(vec3(0.8, 0.2, 0.2), 0.0);
    }
    else
    {
        //NOTE(chen): non-existent material. Returns a ugly color for debug
        return material(vec3(1, 0, 1), 0.0);
    }
}

contact_info Raytrace(in vec3 Ro, in vec3 Rd)
{
    contact_info Res;
    Res.T = T_MAX;
    Res.MatID = -1;
    
    // spheres
    for (int SphereIndex = 0; SphereIndex < SPHERE_COUNT; ++SphereIndex)
    {
        sphere Sphere = Spheres[SphereIndex];
        float T = RayIntersectSphere(Ro - Sphere.P, Rd, Sphere.Radius);
        if (T > T_MIN && T < Res.T)
        {
            Res.T = T;
            Res.MatID = Sphere.MatID;
            Res.N = normalize(Ro + T * Rd - Sphere.P);
        }
    }
    
    // plane
    float T = RayIntersectPlane(Ro, Rd, vec3(0,1,0), 0);
    if (T > T_MIN && T < Res.T)
    {
        Res.T = T;
        Res.MatID = 0;
        Res.N = vec3(0, 1, 0);
    }
    
    return Res;
}

vec3 Ortho(in vec3 X)
{
    vec3 Res;
    
    if (dot(X, vec3(0,1,0)) < 0.99)
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

void main()
{
    InitScene();
    
    vec3 AvgRadiance = vec3(0);
    
    vec2 UV = 2.0 * FragP.xy - 1.0;
    vec2 Delta = vec2(dFdx(UV.x), dFdy(UV.y));
    
#define SAMPLE_COUNT 8
    for (int SampleIndex = 0; SampleIndex < SAMPLE_COUNT; ++SampleIndex)
    {
        vec2 UV = 2.0 * FragP.xy - 1.0;
        UV += Delta * Rand2();
        
        vec3 Ro = CamP;
        vec3 At = CamLookAt;
        vec3 CamZ = normalize(At - Ro);
        vec3 CamX = normalize(cross(vec3(0, 1, 0), CamZ));
        vec3 CamY = cross(CamZ, CamX);
        vec3 Rd = normalize(AspectRatio * CamX * UV.x + CamY * UV.y + 1.73 * CamZ);
        
        vec3 Radiance = vec3(0);
        vec3 Attenuation = vec3(1);
        vec3 EnvLight = vec3(0.3, 0.4, 0.5);
        vec3 L = normalize(vec3(-0.5f, 0.7f, -0.5f));
        vec3 SunRadiance = vec3(1.0);
        
        vec3 CurrRo = Ro;
        vec3 CurrRd = Rd;
        
        for (int BounceIndex = 0; BounceIndex < 8; ++BounceIndex)
        {
            contact_info Hit = Raytrace(CurrRo, CurrRd);
            
            if (Hit.T > T_MIN && Hit.T < T_MAX)
            {
                material Mat = MatLookup(Hit.MatID);
                Attenuation *= Mat.Albedo;
                CurrRo = CurrRo + (Hit.T - T_MIN) * CurrRd;
                
                vec3 LSample = SampleCone(L, 6e-5);
                float SunLightRatio = dot(LSample, Hit.N);
                if (SunLightRatio > 0.0 && Raytrace(CurrRo, LSample).T == T_MAX)
                {
                    Radiance += Attenuation*SunLightRatio*SunRadiance;
                }
                
                CurrRd = mix(SampleHemisphere(Hit.N), reflect(CurrRd, Hit.N), Mat.Specular);
            }
            else
            {
                Radiance += Attenuation * EnvLight;
                break;
            }
        }
        
        AvgRadiance += 1.0/float(SAMPLE_COUNT) * Radiance;
    }
    
    AvgRadiance = 1.0-exp(-AvgRadiance);
    AvgRadiance = sqrt(AvgRadiance);
    FragColor = AvgRadiance;
}