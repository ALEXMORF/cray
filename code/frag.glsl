#version 440 core

in vec3 FragP;
out vec3 FragColor;

void main()
{
    //TODO(chen): Hack, fix later with the interactive version
    float AspectRatio = 1280.0f / 720.0f;
    
    vec2 UV = 2.0 * FragP.xy - 1.0;
    
    vec3 Ro = vec3(0, 0, -2);
    vec3 At = vec3(0);
    vec3 CamZ = normalize(At - Ro);
    vec3 CamX = normalize(cross(vec3(0, 1, 0), CamZ));
    vec3 CamY = cross(CamZ, CamX);
    vec3 Rd = normalize(AspectRatio * CamX * UV.x + CamY * UV.y + 1.73 * CamZ);
    
    FragColor = Rd;
}