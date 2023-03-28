cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(singleton singleton.cpp)
add_executable(singleton_multithreaded_issue singleton_multithreaded_issue.cpp)
add_executable(singleton_double_checked_lock singleton_double_checked_lock.cpp)
