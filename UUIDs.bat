@echo off
set BLOB=UUIDs
mkdir %BLOB%
cd %BLOB%
call %~dp0\scripts\windows.bat
cd ..
rd /S /Q %BLOB%
