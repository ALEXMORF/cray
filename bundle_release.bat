@echo off

IF EXIST .\release rmdir /S /Q .\release

mkdir .\release
mkdir .\release\win32_build
echo f | xcopy .\build\win32_main.exe .\release\win32_build\cray.exe
echo d | xcopy /s .\data .\release\data
