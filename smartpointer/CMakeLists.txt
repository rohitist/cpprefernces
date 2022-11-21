cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})


add_executable(weak_ptr weak_ptr.cpp)
add_executable(weakpointer_with_class_memleak weakpointer_with_class_memleak.cpp)
add_executable(weakpointer_with_class_noleak weakpointer_with_class_noleak.cpp)
