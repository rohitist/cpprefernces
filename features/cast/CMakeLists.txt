cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(float_to_int_static_cast float_to_int_static_cast.cpp)