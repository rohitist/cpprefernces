cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(fork fork.cpp)
add_executable(vfork vfork.cpp)
