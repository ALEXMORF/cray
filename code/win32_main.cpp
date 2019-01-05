#include "ch_common.h"
#include "ch_math.h"
#include "cray.cpp"

#undef APIENTRY
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <ShellScalingAPI.h>
#include "win32_kernel.h"

global_variable b32 GlobalAppIsRunning;
global_variable int GlobalWindowWidth;
global_variable int GlobalWindowHeight;
global_variable input GlobalInput;

inline v2
Win32GetMousePInPixels(LPARAM LParam)
{
    v2 MouseP = {};
    
    MouseP.X = (f32)GET_X_LPARAM(LParam);
    MouseP.Y = (f32)GET_Y_LPARAM(LParam);
    
    return MouseP;
}

inline v2
Win32GetNormalizedMouseP(HWND Window, LPARAM LParam)
{
    v2 MouseP = {};
    
    win32_window_dimension WindowDim = Win32GetWindowDimension(Window);
    MouseP.X = (f32)GET_X_LPARAM(LParam) / (f32)WindowDim.Width; 
    MouseP.Y = 1.0f - (f32)GET_Y_LPARAM(LParam) / (f32)WindowDim.Height; 
    MouseP = 2.0f * MouseP - V2(1.0f);
    
    return MouseP;
}

internal void
Win32Panic(char *Message)
{
    MessageBoxA(0, Message, "Panic", MB_OK|MB_ICONERROR);
    exit(1);
}


internal void
Win32TrackMouse(HWND Window)
{
    TRACKMOUSEEVENT MouseEvent = {};
    MouseEvent.cbSize = sizeof(MouseEvent);
    MouseEvent.dwFlags = TME_LEAVE;
    MouseEvent.hwndTrack = Window;
    MouseEvent.dwHoverTime = HOVER_DEFAULT;
    TrackMouseEvent(&MouseEvent);
}

LRESULT CALLBACK
Win32WindowCallback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
    LRESULT Result = S_OK;
    
    switch (Message)
    {
        case WM_QUIT:
        case WM_CLOSE:
        {
            GlobalAppIsRunning = false;
        } break;
        
        case WM_LBUTTONDOWN:
        {
            GlobalInput.MouseIsDown = true;
            GlobalInput.MousePInPixels = Win32GetMousePInPixels(LParam);
            GlobalInput.MouseP = Win32GetNormalizedMouseP(Window, LParam);
        } break;
        
        case WM_LBUTTONUP:
        {
            GlobalInput.MouseIsDown = false;
            GlobalInput.MousePInPixels = Win32GetMousePInPixels(LParam);
            GlobalInput.MouseP = Win32GetNormalizedMouseP(Window, LParam);
        } break;
        
        case WM_MOUSEMOVE:
        {
            GlobalInput.MousePInPixels = Win32GetMousePInPixels(LParam);
            GlobalInput.MouseP = Win32GetNormalizedMouseP(Window, LParam);
        } break;
        
        case WM_MOUSELEAVE:
        {
            GlobalInput.MouseIsDown = false;
        } break;
        
        case WM_SIZE:
        {
            GlobalWindowWidth = LOWORD(LParam);
            GlobalWindowHeight = HIWORD(LParam);
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
    
    GlobalWindowWidth = 1280;
    GlobalWindowHeight = 720;
    HWND Window = Win32CreateWindow(CurrentInstance, 
                                    GlobalWindowWidth, GlobalWindowHeight, 
                                    "CRay", "CRay WndClass", 
                                    Win32WindowCallback);
    
    app_memory AppMemory = {};
    AppMemory.Size = GB(2);
    AppMemory.Data = Win32AllocateMemory(AppMemory.Size);
    
    if (!AppMemory.Data)
    {
        Win32Panic("Failed to allocate required amount of memory");
    }
    
    u64 LastCounter = Win32GetPerformanceCounter();
    GlobalAppIsRunning = true;
    while (GlobalAppIsRunning)
    {
        //TODO(chen): doing this per frame ... is that safe?
        Win32TrackMouse(Window);
        
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
                        GlobalInput.Keys[KeyCode] = KeyIsDown;
                        
#if 0
                        if (KeyIsDown && AltIsDown && KeyCode == VK_RETURN)
                        {
                            Win32ToggleFullscreen(Window);
                        }
#endif
                        
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
        
        f32 ElapsedTimeInMS = Win32GetTimeElapsedInMS(LastCounter, Win32GetPerformanceCounter());
        f32 dT = ElapsedTimeInMS / 1000.0f;
        LastCounter = Win32GetPerformanceCounter();
        RunCRay(&AppMemory, &GlobalInput, dT, 
                Window, GlobalWindowWidth, GlobalWindowHeight, 
                Win32Panic);
        
        Sleep(2);
        
        f32 EstimatedFPS = 1.0f / dT;
        char TitleBuf[255];
        snprintf(TitleBuf, sizeof(TitleBuf), "CRay - %.2f ms elapsed, %.2f FPS", ElapsedTimeInMS, EstimatedFPS);
        SetWindowTextA(Window, TitleBuf);
    }
    
    return 0;
}