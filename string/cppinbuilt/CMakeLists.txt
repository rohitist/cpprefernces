cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})


add_executable(to_lower to_lower.cpp)
add_executable(stringstream_tokenize stringstream_tokenize.cpp)
add_executable(stringreverse_inbuilt stringreverse_inbuilt.cpp)
