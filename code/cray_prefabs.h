#pragma once

struct model_prefab
{
    char Path[255];
    mat4 XForm;
};

global_variable model_prefab GlobalPrefabs[] = {
    {"../data/monkey", Mat4Scale(0.5f) * Mat4RotateAroundY(Pi32) * Mat4Translate(0.0f, 0.6f, 0.0f)},
    {"../data/light_room", Mat4RotateAroundY(Pi32) * Mat4Translate(0.0f, 0.0f, 4.0f)},
    {"../data/tiger", Mat4RotateAroundY(1.15f*Pi32) * Mat4Translate(0.0f, 0.3f, 0.0f)},
    {"../data/moose", Mat4RotateAroundY(0.2f*Pi32) * Mat4Translate(1.0f, -0.02f, 0.0f)},
    {"../data/bigmouth", Mat4RotateAroundY(0.7f*Pi32) * Mat4Translate(-1.0f, 0.0f, 0.0f)},
    {"../data/sphinx", Mat4Scale(0.7f) * Mat4RotateAroundY(0.9f*Pi32) * Mat4Translate(0.0f, 0.0f, 1.0f)},
    {"../data/bunny", Mat4Scale(0.5f) * Mat4RotateAroundY(1.1f*Pi32) * Mat4Translate(0.0f, -0.025f, 0.0f)},
    {"../data/serapis", Mat4RotateAroundY(1.3f*Pi32) * Mat4Translate(0.0f, 0.0f, 0.0f)},
    {"../data/dragon", Mat4Translate(0.0f, 0.25f, 0.0f)},
    {"../data/head", Mat4Scale(2.0f) * Mat4RotateAroundY(1.0f*Pi32)},
    {"../data/buddha", Mat4Identity()},
    {"../data/sponza", Mat4Identity()},
    {"../data/conference", Mat4Identity()},
    {"../data/sibenik", Mat4Identity()},
    {"../data/fireplace_room", Mat4Identity()},
};
