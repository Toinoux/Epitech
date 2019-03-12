cls
@echo off
cd ../
del CMakeCache.txt cmake_install.cmake Makefile bomberman.cbp bomberman.exe /Q /F
rd /S CMakeFiles /Q