cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(posix_signals_user_handler posix_signals_user_handler.cpp)
add_executable(posix_signals_ignore posix_signals_ignore.cpp)
add_executable(posix_signals_user posix_signals_user.cpp)