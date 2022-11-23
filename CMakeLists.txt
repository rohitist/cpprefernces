cmake_minimum_required(VERSION 3.0.0)
project(cppreferences VERSION 0.1.0)

set(STD_COMPILER_VERSION -std=c++11)
SET(CMAKE_CXX_FLAGS "-g -O0")

#add_executable(cppreferences main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#add subdirectories to build
add_subdirectory(bitwise)
add_subdirectory(implementation)
add_subdirectory(misc)
add_subdirectory(oops/inheritance)
add_subdirectory(oops/class)
add_subdirectory(features/constant)
add_subdirectory(features/operator_overloading)
add_subdirectory(features/exceptions)
add_subdirectory(pointer)
add_subdirectory(recursion)
add_subdirectory(smartpointer)
add_subdirectory(stl/map)
add_subdirectory(stl/list)
add_subdirectory(stl/vector)
add_subdirectory(string)
add_subdirectory(threads)
