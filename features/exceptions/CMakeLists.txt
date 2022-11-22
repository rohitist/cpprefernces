cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(exception_in_dtor exception_in_dtor.cpp)
add_executable(uncaught_exception uncaught_exception.cpp)