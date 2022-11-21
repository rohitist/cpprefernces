cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})


add_executable(chararraypointer chararraypointer.cpp)
add_executable(charpointer charpointer.cpp)
add_executable(charpointer_diff charpointer_diff.cpp)
add_executable(charpointer_modify charpointer_modify.cpp)
add_executable(charptr_to_intptr charptr_to_intptr.cpp)
add_executable(func_pointer func_pointer.cpp)
add_executable(incr_pointer_to_int incr_pointer_to_int.cpp)
add_executable(int_pointer int_pointer.cpp)
add_executable(int_pointer2 int_pointer2.cpp)
add_executable(inttocharpointer inttocharpointer.cpp)
add_executable(sizeofpointers sizeofpointers.cpp)
add_executable(struct_pointer struct_pointer.cpp)
