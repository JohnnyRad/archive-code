@echo off
:-  Build and install Xitami 5.0a0 and dependent products

:-  Set the IBASE variable to the installation directory
if "%IBASE%"=="" (
    echo The IBASE environment variable is not defined.
    echo Set this to desired installation directory, e.g. c:ibase.
    echo Then, add ^%IBASE^%/bin to your PATH for best results.
    exit /b 1
)

:-  Build foreign
cd foreign
call boomake build test install
if errorlevel 1 (
    echo E: Build of foreign failed
    exit /b 1
)
cd ..

:-  Build base2
cd base2
call boomake build test install
if errorlevel 1 (
    echo E: Build of base2 failed
    exit /b 1
)
cd ..

:-  Done successfully
echo Finished building and installing Xitami 5.0a0.

