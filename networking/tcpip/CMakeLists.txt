cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(tcpip_server tcpip_server.cpp)
add_executable(tcpip_client tcpip_client.cpp)