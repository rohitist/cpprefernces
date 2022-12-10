cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(constexpr_cpp_11 constexpr_cpp_11.cpp)
add_executable(modify_in_const_function modify_in_const_function.cpp)
add_executable(free_const_function free_const_function.cpp)