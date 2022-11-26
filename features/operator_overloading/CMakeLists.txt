cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(overload_return_type_cpp_11 overload_return_type_cpp_11.cpp)
add_executable(conversion_operator conversion_operator.cpp)