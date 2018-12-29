@echo off

IF EXIST .\release rmdir /S /Q .\release

mkdir .\release
mkdir .\release\build
echo f | xcopy .\build\win32_main.exe .\release\build\win32_cray.exe
echo d | xcopy /s .\data .\release\data
