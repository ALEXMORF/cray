@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

ctime -begin cray.ctm

set CompilerFlags=-nologo -Z7 -Od -FC
set LinkerFlags=-subsystem:windows -incremental:no User32.lib Gdi32.lib Opengl32.lib
cl %CompilerFlags% ..\code\win32_main.cpp /link %LinkerFlags%

ctime -end cray.ctm

popd