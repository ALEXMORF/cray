#version 440 core

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
}