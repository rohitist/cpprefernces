cmake_minimum_required(VERSION 3.0.0)
project(cppreferences VERSION 0.1.0)

set(STD_COMPILER_VERSION -std=c++11)
SET(CMAKE_CXX_FLAGS "-g -O0")

#add_executable(cppreferences main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#add subdirectories to build
add_subdirectory(bitwise)
#add_subdirectory(implementation)
#add_subdirectory(misc)
#add_subdirectory(oops)
#add_subdirectory(pointer)
#add_subdirectory(recursion)
#add_subdirectory(smartpointer)
#add_subdirectory(stl)
#add_subdirectory(string)
#add_subdirectory(thread)
