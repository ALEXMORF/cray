internal scene
InitScene()
{
    scene Scene = {};
    
    Scene.CamP = {0.0f, 0.7f, -2.0f};
    Scene.CamOrientation = Quaternion(XAxis(), 0.1f);
    Scene.Controller.DraggedRotation = Quaternion();
    
    return Scene;
}

internal void
HandleInput(scene *Scene, input *Input, f32 dT)
{
    scene_controller *Controller = &Scene->Controller;
    
    if (!Input->MouseIsCaptured)
    {
        //NOTE(chen): handle mouse dragging
        if (Controller->CamIsBeingDragged)
        {
            if (!Input->MouseIsDown)
            {
                Controller->CamIsBeingDragged = false;
                Scene->CamOrientation = Controller->DraggedRotation * Scene->CamOrientation;
                Controller->DraggedRotation = Quaternion();
            }
            else
            {
                v2 MousedP = Input->MouseP - Controller->StartMouseP;
                quaternion YRot = Quaternion(YAxis(), MousedP.X);
                v3 LocalXAxis = Rotate(XAxis(), YRot * Scene->CamOrientation);
                quaternion XRot = Quaternion(LocalXAxis, -MousedP.Y);
                Controller->DraggedRotation = XRot * YRot;
            }
        }
        else
        {
            if (Input->MouseIsDown)
            {
                Controller->CamIsBeingDragged = true;
                Controller->StartMouseP = Input->MouseP;
            }
        }
    }
    
    v3 dP = {};
    if (Input->Keys['W']) dP.Z += 1.0;
    if (Input->Keys['S']) dP.Z -= 1.0;
    if (Input->Keys['A']) dP.X -= 1.0;
    if (Input->Keys['D']) dP.X += 1.0;
    dP = Rotate(dP, Controller->DraggedRotation * Scene->CamOrientation);
    dP.Y = 0.0f;
    if (Input->Keys['Z']) dP.Y -= 1.0;
    if (Input->Keys['X']) dP.Y += 1.0;
    
    float CamSpeed = 1.0f;
    Scene->CamP += CamSpeed * dT * Normalize(dP);
    Scene->CamLookAt = Scene->CamP + Rotate(ZAxis(), Controller->DraggedRotation * Scene->CamOrientation);
}