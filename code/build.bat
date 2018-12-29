@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

ctime -begin bake_shader.ctm
REM ctime -begin baker.ctm
REM cl -nologo -Z7 -Od -FC ..\code\win32_shader_baker.cpp /link -incremental:no
REM ctime -end baker.ctm
win32_shader_baker
ctime -end bake_shader.ctm

ctime -begin cray.ctm

set CompilerFlags=-nologo -Z7 -O2 -FC /I ../code/3rd/
set LinkerFlags=-subsystem:windows -incremental:no User32.lib Gdi32.lib Opengl32.lib
cl %CompilerFlags% ..\code\win32_main.cpp /link %LinkerFlags%

ctime -end cray.ctm

popd