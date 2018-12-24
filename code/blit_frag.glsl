#version 440 core

uniform sampler2D HdrTex;

in vec3 FragP;
out vec3 FragColor;

void main()
{
    vec3 Radiance = texture(HdrTex, FragP.xy).rgb;
    
    float Exposure = 0.7;
    Radiance = 1.0-exp(-Exposure*Radiance);
    Radiance = sqrt(Radiance);
    
    FragColor = Radiance;
}