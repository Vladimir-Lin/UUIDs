@echo off

set CURRENT=%CD%
call %~dp0\..\settings.bat

7z x %ROOT%\%TAR%

cmd /A /Q /K %~dp0\x86.bat %CURRENT% Release static 1 0
cmd /A /Q /K %~dp0\x86.bat %CURRENT% Release shared 0 1
cmd /A /Q /K %~dp0\x86.bat %CURRENT% Debug   static 1 0
cmd /A /Q /K %~dp0\x86.bat %CURRENT% Debug   shared 0 1
cmd /A /Q /K %~dp0\x64.bat %CURRENT% Release static 1 0
cmd /A /Q /K %~dp0\x64.bat %CURRENT% Release shared 0 1
cmd /A /Q /K %~dp0\x64.bat %CURRENT% Debug   static 1 0
cmd /A /Q /K %~dp0\x64.bat %CURRENT% Debug   shared 0 1

rd /S /Q %CURRENT%\%PACKAGE%

set FILES=^
UUIDs-x64-Release-static.7z ^
UUIDs-x64-Debug-static.7z ^
UUIDs-x64-Release-shared.7z ^
UUIDs-x64-Debug-shared.7z ^
UUIDs-x86-Release-static.7z ^
UUIDs-x86-Debug-static.7z ^
UUIDs-x86-Release-shared.7z ^
UUIDs-x86-Debug-shared.7z

for %%i in (%FILES%) do (
  7z x %ROOT%\%VERSION%\%%i
)

copy /Y UUIDs-x64-Release-static\include\*.hpp %CIOSPATH%\include
copy /Y UUIDs-x64-Release-shared\bin\UUIDs.dll %CIOSPATH%\Bin\UUIDs.dll

copy /Y UUIDs-x64-Release-static\lib\UUIDs.lib %CIOSPATH%\lib\x64\static\release\UUIDs.lib
copy /Y UUIDs-x64-Debug-static\lib\UUIDs.lib   %CIOSPATH%\lib\x64\static\debug\UUIDs.lib
copy /Y UUIDs-x86-Release-static\lib\UUIDs.lib %CIOSPATH%\lib\x86\static\release\UUIDs.lib
copy /Y UUIDs-x86-Debug-static\lib\UUIDs.lib   %CIOSPATH%\lib\x86\static\debug\UUIDs.lib

copy /Y UUIDs-x64-Release-shared\lib\UUIDs.lib %CIOSPATH%\lib\x64\shared\release\UUIDs.lib
copy /Y UUIDs-x64-Release-shared\bin\UUIDs.dll %CIOSPATH%\lib\x64\shared\release\DLL\UUIDs.dll

copy /Y UUIDs-x64-Debug-shared\lib\UUIDs.lib   %CIOSPATH%\lib\x64\shared\debug\UUIDs.lib
copy /Y UUIDs-x64-Debug-shared\bin\UUIDs.dll   %CIOSPATH%\lib\x64\shared\debug\DLL\UUIDs.dll

copy /Y UUIDs-x86-Release-shared\lib\UUIDs.lib %CIOSPATH%\lib\x86\shared\release\UUIDs.lib
copy /Y UUIDs-x86-Release-shared\bin\UUIDs.dll %CIOSPATH%\lib\x86\shared\release\DLL\UUIDs.dll

copy /Y UUIDs-x86-Debug-shared\lib\UUIDs.lib   %CIOSPATH%\lib\x86\shared\debug\UUIDs.lib
copy /Y UUIDs-x86-Debug-shared\bin\UUIDs.dll   %CIOSPATH%\lib\x86\shared\debug\DLL\UUIDs.dll
