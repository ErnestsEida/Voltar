@echo off
REM Delete the build directory
rmdir /s /q build

REM Run CMake to configure the build
cmake -B build
