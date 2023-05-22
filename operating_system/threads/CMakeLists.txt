cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(pthread_basic pthread_basic.cpp)
add_executable(cp11_thread cp11_thread.cpp)
add_executable(cpp11_thread_not_joining cpp11_thread_not_joining.cpp)
add_executable(cpp11_thread_not_joining_solution cpp11_thread_not_joining_solution.cpp)

