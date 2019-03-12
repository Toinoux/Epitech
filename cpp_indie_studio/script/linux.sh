#!/bin/bash
if [ $# -eq 1 ]; then
    if [ "$1" = "compile" ]; then
	echo "Compiling Linux"
	cmake CMakeLists.txt
	make
    elif [ "$1" = "clean" ]; then
	echo "Cleaning"
	make clean
	rm -rf CMakeCache.txt CMakeFiles/ Makefile cmake_install.cmake
    else
	echo "USAGE: $0 [compile/clean]"
    fi
else
    echo "USAGE: $0 [compile/clean]"
fi
