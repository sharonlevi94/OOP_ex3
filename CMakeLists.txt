# CMakeList.txt : CMake project for oop3, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("oop3")

# Add source to this project's executable.
add_executable (oop3 "oop3.cpp" "oop3.h" "Image.cpp" "Image.h" "Pixel.h" "Pixel.cpp" "Utilities.cpp" "Utilities.h" "ImageDataStracture.h")

# TODO: Add tests and install targets if needed.
