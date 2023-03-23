cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(unsigned_assign_negative_num unsigned_assign_negative_num.cpp)
add_executable(NULL_ambiguity NULL_ambiguity.cpp)
add_executable(NULL_ambiguity_solution NULL_ambiguity_solution.cpp)
add_executable(assign_large_val assign_large_val.cpp)
add_executable(struct_pack struct_pack.cpp)