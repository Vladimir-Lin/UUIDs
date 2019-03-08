@echo off

set NAME=UUIDs
set UUIDS=%~dp0
set ORIGINAL=%CD%
set COMPILEPATH=%CD%\UUIDs
set /p VERSION=<%UUIDS%\VERSION.txt

mkdir %COMPILEPATH%
cd %COMPILEPATH%

cmd /A /Q /K %UUIDS%\scripts\install.bat x86 release static
cmd /A /Q /K %UUIDS%\scripts\install.bat x86 release shared
cmd /A /Q /K %UUIDS%\scripts\install.bat x86 debug   static
cmd /A /Q /K %UUIDS%\scripts\install.bat x86 debug   shared
cmd /A /Q /K %UUIDS%\scripts\install.bat x64 release static
cmd /A /Q /K %UUIDS%\scripts\install.bat x64 release shared
cmd /A /Q /K %UUIDS%\scripts\install.bat x64 debug   static
cmd /A /Q /K %UUIDS%\scripts\install.bat x64 debug   shared

xcopy /Y %UUIDS%\include\UUIDs.hpp %CIOS%\include\UUIDs.hpp

cd %ORIGINAL%
rd /S /Q %COMPILEPATH%
echo Compile Done
rem exit
