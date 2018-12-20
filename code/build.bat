@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

set CompilerFlags=-nologo -Z7 -Od
set LinkerFlags=-incremental:no User32.lib Gdi32.lib Opengl32.lib
cl %CompilerFlags% ..\code\win32_main.cpp /link %LinkerFlags%

popd