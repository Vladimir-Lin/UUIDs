@echo off

set ARCHX=x64
set COMPILE=%1
set BTYPE=%2
set DLLX=%3
set DOSTATIC=%4
set DOSHARED=%5

call %~dp0\..\settings.bat
call %VC_PATH%\vcvars64.bat

set TARGET=%NAME%-%ARCHX%-%BTYPE%-%DLLX%
set SOURCEDIR=%COMPILE%\%PACKAGE%
set INSTALLDIR=-DCMAKE_INSTALL_PREFIX=%COMPILE%\%TARGET%
set BUILDTYPE=-DCMAKE_CONFIGURATION_TYPES=%BTYPE%
set PARAMETERS=-DBUILD_SHARED_LIBS=%DOSHARED%
set PLATFORMS=-G %VC_CMAKE%

mkdir %TARGET%
mkdir %NAME%-compile-%ARCHX%-%BTYPE%-%DLLX%

cd %COMPILE%\%NAME%-compile-%ARCHX%-%BTYPE%-%DLLX%

cmake %PLATFORMS% %SOURCEDIR% %INSTALLDIR% %BUILDTYPE% %PARAMETERS%

devenv %NAME%.sln /Build
devenv %NAME%.sln /Build %BTYPE% /Project INSTALL

cd ..

7z a %TARGET%.7z %TARGET%

del /Q %ROOT%\%TARGET%.7z
move /Y %TARGET%.7z %ROOT%
rd /S /Q %TARGET%
rd /S /Q %NAME%-compile-%ARCHX%-%BTYPE%-%DLLX%

exit
