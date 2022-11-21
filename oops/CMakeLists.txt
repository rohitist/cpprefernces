cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(constexpr_cpp_11 constexpr_cpp_11.cpp)
add_executable(default_inheritence default_inheritence.cpp)
add_executable(default_inheritence_2 default_inheritence_2.cpp)
add_executable(overload_return_type_cpp_11 overload_return_type_cpp_11.cpp)
add_executable(private_inheritence private_inheritence.cpp)
add_executable(private_inheritence_2 private_inheritence_2.cpp)
add_executable(public_inheritence public_inheritence.cpp)
add_executable(virtual virtual.cpp)
