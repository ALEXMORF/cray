#version 440 core

layout(location = 0) in vec3 Position;

out vec3 FragP;

void main()
{
    FragP = Position;
    gl_Position = vec4(2.0 * Position - 1.0, 1.0);
}