cmake_minimum_required(VERSION 3.17)
project(OpenGL)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp Icosa.h Icosa.cpp CleaningTheWindow.cpp)
# build for window
#target_link_libraries(main -lOpenGL32 -lfreeGLUT)
#build for linux
target_link_libraries(main -lglut -lGL -lGLU)