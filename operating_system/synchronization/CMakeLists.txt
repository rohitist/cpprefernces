cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(condition_variable condition_variable.cpp)
add_executable(rw_lock rw_lock.cpp)
add_executable(deadlock_using_mutex deadlock_using_mutex.cpp)
add_executable(deadlock_using_mutex_solution_recursive_mutex deadlock_using_mutex_solution_recursive_mutex.cpp)
