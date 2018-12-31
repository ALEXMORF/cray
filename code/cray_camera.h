#pragma once

struct camera_controller
{
    b32 IsBeingDragged;
    v2 StartMouseP;
    quaternion DraggedRotation;
};

struct camera
{
    camera_controller Controller;
    quaternion Orientation;
    v3 P;
    v3 LookAt;
};