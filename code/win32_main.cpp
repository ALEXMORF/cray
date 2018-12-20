#include "ch_common.h"
#include "ch_gl.h"
#include "ch_math.h"
#include "cray.cpp"

#undef APIENTRY
#include <windows.h>
#include <ShellScalingAPI.h>
#include "win32_kernel.h"

global_variable b32 GlobalAppIsRunning;

LRESULT CALLBACK
Win32WindowCallback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT Result = 0;
    
    switch (Message)
    {
        case WM_QUIT:
        case WM_CLOSE:
        {
            GlobalAppIsRunning = false;
        } break;
        
        default:
        {
            Result = DefWindowProc(Window, Message, WParam, LParam);
        } break;
    }
    
    return Result;
}

int CALLBACK
WinMain(HINSTANCE CurrentInstance,
        HINSTANCE PrevInstance,
        LPSTR CommandLine,
        int ShowCode)
{
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    
    HWND Window = Win32CreateWindow(CurrentInstance, 1280, 720, 
                                    "CRay", "CRay WndClass", 
                                    Win32WindowCallback);
    HDC WindowDC = GetDC(Window);
    Win32InitializeOpengl(WindowDC, 4, 4);
    LoadGLFunctions(Win32GetOpenglFunction);
    
    input Input = {};
    
    app_memory AppMemory = {};
    AppMemory.Size = MB(4);
    AppMemory.Data = Win32AllocateMemory(AppMemory.Size);
    
    GlobalAppIsRunning = true;
    while (GlobalAppIsRunning)
    {
        MSG Message = {};
        while (PeekMessage(&Message, 0, 0, 0, PM_REMOVE))
        {
            switch (Message.message)
            {
                case WM_KEYDOWN:
                case WM_KEYUP:
                case WM_SYSKEYDOWN:
                case WM_SYSKEYUP:
                { 
                    WPARAM KeyCode = Message.wParam;
                    
                    b32 KeyIsDown = (Message.lParam & (1 << 31)) == 0;
                    b32 KeyWasDown = (Message.lParam & (1 << 30)) != 0;
                    b32 AltIsDown = (Message.lParam & (1 << 29)) != 0;
                    
                    if (KeyWasDown != KeyIsDown)
                    {
                        Input.Keys[KeyCode] = KeyIsDown;
                        
                        if (AltIsDown && KeyCode == VK_F4)
                        {
                            GlobalAppIsRunning = false;
                        }
                    }
                } break;
                
                default:
                {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                } break;
            }
        }
        
        RunCRay(&AppMemory, &Input);
        
        SwapBuffers(WindowDC);
        Sleep(2);
    }
    
    return 0;
}