internal camera
InitCamera()
{
    camera Camera = {};
    
    Camera.P = {0.0f, 0.7f, -2.0f};
    Camera.Orientation = Quaternion(XAxis(), 0.1f);
    Camera.Controller.DraggedRotation = Quaternion();
    
    return Camera;
}

internal void
HandleInput(camera *Camera, input *Input, f32 dT)
{
    camera_controller *Controller = &Camera->Controller;
    
    if (!Input->MouseIsCaptured)
    {
        //NOTE(chen): handle mouse dragging
        if (Controller->IsBeingDragged)
        {
            if (!Input->MouseIsDown)
            {
                Controller->IsBeingDragged = false;
                Camera->Orientation = Controller->DraggedRotation * Camera->Orientation;
                Controller->DraggedRotation = Quaternion();
            }
            else
            {
                v2 MousedP = Input->MouseP - Controller->StartMouseP;
                quaternion YRot = Quaternion(YAxis(), MousedP.X);
                v3 LocalXAxis = Rotate(XAxis(), YRot * Camera->Orientation);
                quaternion XRot = Quaternion(LocalXAxis, -MousedP.Y);
                Controller->DraggedRotation = XRot * YRot;
            }
        }
        else
        {
            if (Input->MouseIsDown)
            {
                Controller->IsBeingDragged = true;
                Controller->StartMouseP = Input->MouseP;
            }
        }
    }
    
    v3 dP = {};
    if (Input->Keys['W']) dP.Z += 1.0;
    if (Input->Keys['S']) dP.Z -= 1.0;
    if (Input->Keys['A']) dP.X -= 1.0;
    if (Input->Keys['D']) dP.X += 1.0;
    dP = Rotate(dP, Controller->DraggedRotation * Camera->Orientation);
    dP.Y = 0.0f;
    if (Input->Keys['Z']) dP.Y -= 1.0;
    if (Input->Keys['X']) dP.Y += 1.0;
    
    float CamSpeed = 1.0f;
    Camera->P += CamSpeed * dT * Normalize(dP);
    Camera->LookAt = Camera->P + Rotate(ZAxis(), Controller->DraggedRotation * Camera->Orientation);
}