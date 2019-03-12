cls
@echo off
cd ../
cmake CMakeLists.txt -G"CodeBlocks - MinGW Makefiles"
mingw32-make
PAUSE