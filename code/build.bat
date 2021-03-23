@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

REM ctime -begin baker.ctm
REM cl -nologo -Z7 -Od -FC ..\code\win32_shader_baker.cpp /link -incremental:no
REM ctime -end baker.ctm
win32_shader_baker

set Macros=-DCRAY_DEBUG=0 -DCRAY_MALLOC=0
set CompilerFlags=-nologo -Z7 -Od -FC /I ../code/3rd/ -WX -W4 -wd4201 -wd4100 -wd4189
set LinkerFlags=-subsystem:windows -incremental:no User32.lib Gdi32.lib d3d11.lib dxgi.lib d3dcompiler.lib
cl %Macros% %CompilerFlags% ..\code\win32_main.cpp /link %LinkerFlags%

popd
