#version 440 core

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
}