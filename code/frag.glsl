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

#define SPHERE_COUNT 3

sphere Spheres[3];

void InitScene()
{
    Spheres[0].P = vec3(0, 0.5, 0);
    Spheres[0].Radius = 0.5;
    Spheres[0].MatID = 1;
    
    Spheres[1].P = vec3(1.0, 0.5, 0);
    Spheres[1].Radius = 0.5;
    Spheres[1].MatID = 2;
    
    Spheres[2].P = vec3(-1.0, 0.5, 0);
    Spheres[2].Radius = 0.5;
    Spheres[2].MatID = 3;
}

float Hash(in float Seed)
{
    return fract(7831.131*sin(517.131*Seed));
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

float Raytrace(in vec3 Ro, in vec3 Rd, out vec3 N, out int MatID)
{
    float MinT = T_MAX;
    float T = T_MAX;
    MatID = -1;
    
    // spheres
    for (int SphereIndex = 0; SphereIndex < SPHERE_COUNT; ++SphereIndex)
    {
        sphere Sphere = Spheres[SphereIndex];
        T = RayIntersectSphere(Ro - Sphere.P, Rd, Sphere.Radius);
        if (T > T_MIN && T < MinT)
        {
            MinT = T;
            MatID = Sphere.MatID;
            N = normalize(Ro + T * Rd - Sphere.P);
        }
    }
    
    // plane
    T = RayIntersectPlane(Ro, Rd, vec3(0,1,0), 0);
    if (T > T_MIN && T < MinT)
    {
        MinT = T;
        MatID = 0;
        N = vec3(0, 1, 0);
    }
    
    return MinT;
}

vec3 RandomBounce(in vec3 N, float Seed1, float Seed2)
{
    vec3 X, Y;
    
    if (dot(N, vec3(0,1,0)) < 0.99)
    {
        X = normalize(cross(N, vec3(0, 1, 0)));
        Y = cross(N, X);
    }
    else
    {
        X = normalize(cross(N, vec3(1, 0, 0)));
        Y = cross(N, X);
    }
    
    float Radius = sqrt(Hash(Seed1));
    float Theta = 2.0 * Pi * Hash(Seed2);
    
    X *= Radius * cos(Theta);
    Y *= Radius * sin(Theta);
    return X + Y + N * sqrt(1.0 - Radius*Radius);
}

void main()
{
    InitScene();
    
    vec3 AvgRadiance = vec3(0);
    
    vec2 UV = 2.0 * FragP.xy - 1.0;
    vec2 delta = vec2(dFdx(UV.x), dFdy(UV.y));
    
#define SAMPLE_COUNT 16
    for (int SampleIndex = 0; SampleIndex < SAMPLE_COUNT; ++SampleIndex)
    {
        vec2 UV = 2.0 * FragP.xy - 1.0;
        UV.x += delta.x * Hash(13.17*UV.x + 3.7*float(SampleIndex));
        UV.y += delta.y * Hash(31.13*UV.y + 7.1*float(SampleIndex));
        
        vec3 Ro = CamP;
        vec3 At = CamLookAt;
        vec3 CamZ = normalize(At - Ro);
        vec3 CamX = normalize(cross(vec3(0, 1, 0), CamZ));
        vec3 CamY = cross(CamZ, CamX);
        vec3 Rd = normalize(AspectRatio * CamX * UV.x + CamY * UV.y + 1.73 * CamZ);
        
        vec3 Radiance = vec3(0);
        vec3 Attenuation = vec3(1);
        vec3 EnvLight = vec3(1.5);
        
        vec3 CurrRo = Ro;
        vec3 CurrRd = Rd;
        
        for (int BounceIndex = 0; BounceIndex < 8; ++BounceIndex)
        {
            int MatID;
            vec3 NextN;
            float T = Raytrace(CurrRo, CurrRd, NextN, MatID);
            
            if (T > T_MIN && T < T_MAX)
            {
                material Mat = MatLookup(MatID);
                Attenuation *= Mat.Albedo;
                
                CurrRo = CurrRo + (T - T_MIN) * CurrRd;
                
                float Seed1 = dot(CurrRo, vec3(73.4, 71.531, 58.731)) + 8.19*float(SampleIndex) + 7.3*Time;
                float Seed2 = dot(CurrRo, vec3(11.9, 17.131, 83.351)) + 3.71*float(SampleIndex) + 17.1*Time;
                
                CurrRd = mix(RandomBounce(NextN, Seed1, Seed2), 
                             reflect(CurrRd, NextN), Mat.Specular);
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