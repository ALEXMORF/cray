#pragma once

struct scene_controller
{
    b32 CamIsBeingDragged;
    v2 StartMouseP;
    quaternion DraggedRotation;
};

struct scene
{
    scene_controller Controller;
    quaternion CamOrientation;
    v3 CamP;
    v3 CamLookAt;
};