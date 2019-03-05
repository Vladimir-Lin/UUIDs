@echo off

set NAME=UUIDs
set UUIDS=%~dp0
set ORIGINAL=%CD%
set COMPILEPATH=%CD%\UUIDs
set /p VERSION=<%UUIDS%\VERSION.txt

mkdir %COMPILEPATH%
cd %COMPILEPATH%

cmd /A /Q /K %UUIDS%\scripts\x86.bat %COMPILEPATH% Release static 1 0
cmd /A /Q /K %UUIDS%\scripts\x86.bat %COMPILEPATH% Release shared 0 1
cmd /A /Q /K %UUIDS%\scripts\x86.bat %COMPILEPATH% Debug   static 1 0
cmd /A /Q /K %UUIDS%\scripts\x86.bat %COMPILEPATH% Debug   shared 0 1
cmd /A /Q /K %UUIDS%\scripts\x64.bat %COMPILEPATH% Release static 1 0
cmd /A /Q /K %UUIDS%\scripts\x64.bat %COMPILEPATH% Release shared 0 1
cmd /A /Q /K %UUIDS%\scripts\x64.bat %COMPILEPATH% Debug   static 1 0
cmd /A /Q /K %UUIDS%\scripts\x64.bat %COMPILEPATH% Debug   shared 0 1

cd %ORIGINAL%
rd /S /Q %COMPILEPATH%
echo Compile Done
rem exit
