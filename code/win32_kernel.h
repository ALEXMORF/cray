u64
Win32GetPerformanceFrequency()
{
    LARGE_INTEGER Result = {};
    QueryPerformanceFrequency(&Result);
    return Result.QuadPart;
}

u64
Win32GetPerformanceCounter()
{
    LARGE_INTEGER Result = {};
    QueryPerformanceCounter(&Result);
    return Result.QuadPart;
}

inline f32
Win32GetTimeElapsedInMS(u64 BeginCounter, u64 EndCounter)
{
    f32 Result = (f32)(EndCounter - BeginCounter) / (f32)Win32GetPerformanceFrequency();
    Result *= 1000.0f;
    return Result;
}

struct win32_window_dimension
{
    int Width, Height;
};

inline win32_window_dimension
Win32GetWindowDimension(HWND Window)
{
    win32_window_dimension Result = {};
    
    RECT ClientRect;
    GetClientRect(Window, &ClientRect);
    Result.Width = ClientRect.right - ClientRect.left;
    Result.Height = ClientRect.bottom - ClientRect.top;
    
    return Result;
}

//NOTE(chen): RECT Is in screen-coordinate
inline RECT
Win32GetClientRect(HWND Window)
{
    RECT Result = {};
    GetWindowRect(Window, &Result);
    
    POINT ClientUpperLeft = {Result.left, Result.top};
    POINT ClientLowerRight = {Result.right, Result.bottom};
    ScreenToClient(Window, &ClientUpperLeft);
    ScreenToClient(Window, &ClientLowerRight);
    
    i32 SideBorderSize = -ClientUpperLeft.x;
    i32 TopBorderSize = -ClientUpperLeft.y;
    
    Result.left += SideBorderSize;
    Result.top += TopBorderSize;
    Result.right += SideBorderSize;
    Result.bottom += SideBorderSize;
    
    return Result;
}

void *
Win32AllocateMemory(size_t MemorySize)
{
    return VirtualAlloc(0, MemorySize, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
}

char *
Win32ReadFileToMemory(char *Filename, u64 *MemorySize)
{
    char *Result = 0;
    
    HANDLE FileHandle = CreateFile(Filename, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
    if (FileHandle != INVALID_HANDLE_VALUE)
    {
        LARGE_INTEGER FileSize = {};
        GetFileSizeEx(FileHandle, &FileSize);
        
        *MemorySize = (size_t)FileSize.QuadPart;
        Result = (char *)VirtualAlloc(0, (size_t)FileSize.QuadPart, MEM_COMMIT|MEM_RESERVE, PAGE_READWRITE);
        
        DWORD NumberOfBytesRead;
        if (ReadFile(FileHandle, Result, (DWORD)FileSize.QuadPart, &NumberOfBytesRead, 0))
        {
            //NOTE(chen): succeeds
        }
        else
        {
            //NOTE(chen): failed to read file, reset memory to ground zero
            *MemorySize = 0;
            VirtualFree(Result, 0, MEM_RELEASE);
        }
        
        CloseHandle(FileHandle);
    }
    
    return Result;
}

void
Win32FreeFileMemory(void *Memory)
{
    VirtualFree(Memory, 0, MEM_RELEASE);
}

global_variable WINDOWPLACEMENT GlobalWindowPosition;
internal void
Win32ToggleFullscreen(HWND Window)
{
    DWORD Style = GetWindowLong(Window, GWL_STYLE);
    if (Style & WS_OVERLAPPEDWINDOW)
    {
        MONITORINFO mi = { sizeof(mi) };
        if (GetWindowPlacement(Window, &GlobalWindowPosition) &&
            GetMonitorInfo(MonitorFromWindow(Window, MONITOR_DEFAULTTOPRIMARY), &mi))
        {
            SetWindowLong(Window, GWL_STYLE,
                          Style & ~WS_OVERLAPPEDWINDOW);
            SetWindowPos(Window, HWND_TOP,
                         mi.rcMonitor.left, mi.rcMonitor.top,
                         mi.rcMonitor.right - mi.rcMonitor.left,
                         mi.rcMonitor.bottom - mi.rcMonitor.top,
                         SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
        }
    }
    else
    {
        SetWindowLong(Window, GWL_STYLE, Style | WS_OVERLAPPEDWINDOW);
        SetWindowPlacement(Window, &GlobalWindowPosition);
        SetWindowPos(Window, NULL, 0, 0, 0, 0,
                     SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER |
                     SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
    }
}

internal HWND
Win32CreateWindow(HINSTANCE InstanceHandle, i32 WindowWidth, i32 WindowHeight,
                  char *WindowName, char *WindowClassName, WNDPROC WindowProcedure)
{
    WNDCLASS WindowClass = {};
    WindowClass.style = CS_OWNDC|CS_VREDRAW|CS_HREDRAW;
    WindowClass.lpfnWndProc = WindowProcedure;
    WindowClass.hInstance = InstanceHandle;
    WindowClass.hCursor = LoadCursor(0, IDC_ARROW);
    WindowClass.lpszClassName = WindowClassName;
    RegisterClass(&WindowClass);
    
    DWORD WindowStyle = WS_VISIBLE|WS_OVERLAPPEDWINDOW;
    
    //find right window size
    RECT WindowSize = {};
    {
        HDC ScreenDeviceContext = GetWindowDC(0);
        
        int ScreenWidth = GetDeviceCaps(ScreenDeviceContext, HORZRES);
        int ScreenHeight = GetDeviceCaps(ScreenDeviceContext, VERTRES);
        
        int WindowLeft = (ScreenWidth - WindowWidth) / 2;
        int WindowTop = (ScreenHeight - WindowHeight) / 2;
        
        WindowSize = {WindowLeft, WindowTop, WindowLeft + WindowWidth, WindowTop + WindowHeight};
        AdjustWindowRect(&WindowSize, WindowStyle, FALSE);
        
        ReleaseDC(0, ScreenDeviceContext);
    }
    
    HWND Window = CreateWindow(
        WindowClassName,
        WindowName,
        WindowStyle, 
        WindowSize.left,
        WindowSize.top,
        WindowSize.right - WindowSize.left,
        WindowSize.bottom - WindowSize.top,
        0,
        0,
        InstanceHandle,
        0);
    
    return Window;
}

internal void
Win32BlitBufferToScreen(HDC WindowDC, void *Buffer, int Width, int Height)
{
    BITMAPINFO BitmapInfo = {};
    BitmapInfo.bmiHeader.biSize = sizeof(BitmapInfo.bmiHeader);
    BitmapInfo.bmiHeader.biWidth = Width;
    BitmapInfo.bmiHeader.biHeight = Height;
    BitmapInfo.bmiHeader.biPlanes = 1;
    BitmapInfo.bmiHeader.biBitCount = 32;
    BitmapInfo.bmiHeader.biCompression = BI_RGB;
    StretchDIBits(WindowDC, 0, 0, Width, Height, 0, 0, Width, Height, 
                  Buffer, &BitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}

void *
Win32GetOpenglFunction(char *FunctionName)
{
    void *Result = 0;
    Result = (void *)wglGetProcAddress(FunctionName);
    if (Result == 0 || (Result == (void *)0x1) || (Result == (void *)0x2)
        || (Result == (void *)0x3) || (Result == (void *)-1))
    {
        HMODULE OpenglLibrary = LoadLibraryA("opengl32.dll");
        Result = (void *)GetProcAddress(OpenglLibrary, FunctionName);
        FreeLibrary(OpenglLibrary);
    }
    
    return Result;
}

//WGL extension tokens
#define WGL_CONTEXT_MAJOR_VERSION_ARB           0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB           0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB             0x2093
#define WGL_CONTEXT_FLAGS_ARB                   0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB            0x9126
#define WGL_CONTEXT_DEBUG_BIT_ARB               0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB  0x0002
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB        0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_VERSION_ARB               0x2095
#define ERROR_INVALID_PROFILE_ARB               0x2096
#define WGL_SAMPLE_BUFFERS_ARB                  0x2041
#define WGL_SAMPLES_ARB                         0x2042

typedef BOOL WINAPI wgl_swap_interval_ext(int Interval);
typedef HGLRC WINAPI wgl_create_context_attribs_arb(HDC hDC, HGLRC hshareContext, const int *attribList);

//NOTE(chen): disable warning 4706
#pragma warning(push)
#pragma warning(disable: 4706)
internal b32
Win32InitializeOpengl(HDC WindowDC, int MajorVersion, int MinorVersion)
{
    PIXELFORMATDESCRIPTOR DesiredPixelFormat = {};
    DesiredPixelFormat.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    DesiredPixelFormat.nVersion = 1;
    DesiredPixelFormat.dwFlags = PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER;
    DesiredPixelFormat.iPixelType = PFD_TYPE_RGBA;
    DesiredPixelFormat.cColorBits = 32;
    DesiredPixelFormat.cStencilBits = 8;
    
    int SuggestedPixelFormatIndex = ChoosePixelFormat(WindowDC, &DesiredPixelFormat);
    PIXELFORMATDESCRIPTOR SuggestedPixelFormat;
    DescribePixelFormat(WindowDC, SuggestedPixelFormatIndex, sizeof(PIXELFORMATDESCRIPTOR), &SuggestedPixelFormat);
    SetPixelFormat(WindowDC, SuggestedPixelFormatIndex, &SuggestedPixelFormat);
    
    HGLRC Win32RenderContext = wglCreateContext(WindowDC);
    if (!wglMakeCurrent(WindowDC, Win32RenderContext))
    {
        ASSERT(!"Failed to make opengl 1.0 context current");
    }
    
    //NOTE(Chen): Probably the extensions u wanna get, but I comment it out here
#if 0
    wglSwapInterval = (wgl_swap_interval_ext *)wglGetProcAddress("wglSwapIntervalEXT");
    ASSERT(wglSwapInterval);
#endif
    
    wgl_create_context_attribs_arb *wglCreateContextAttribsARB = (wgl_create_context_attribs_arb *)wglGetProcAddress("wglCreateContextAttribsARB");
    ASSERT(wglCreateContextAttribsARB);
    
    //unblind current context
    wglMakeCurrent(WindowDC, 0);
    wglDeleteContext(Win32RenderContext);
    
    //make a new render context
    i32 AttributeList[] = {
        WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB,
        WGL_CONTEXT_MAJOR_VERSION_ARB, MajorVersion,
        WGL_CONTEXT_MINOR_VERSION_ARB, MinorVersion,
        WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
        0,
    };
    Win32RenderContext = wglCreateContextAttribsARB(WindowDC, 0, AttributeList);
    if (Win32RenderContext)
    {
        if (wglMakeCurrent(WindowDC, Win32RenderContext) == TRUE)
        {
            return true;
        }
    }
    
    return false;
}
#pragma warning(pop)
