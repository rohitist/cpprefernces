cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})


add_executable(memcpy memcpy.cpp)
add_executable(memset memset.cpp)
add_executable(sizeof sizeof.cpp)
add_executable(strtok strtok.cpp)
