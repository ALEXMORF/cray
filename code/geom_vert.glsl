#version 440 core

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
}