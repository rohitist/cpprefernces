cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(decimalToBinary decimalToBinary.cpp)
add_executable(check_endianess check_endianess.cpp)
add_executable(flip_a_bit flip_a_bit.cpp)
add_executable(flip_two_bits flip_two_bits.cpp)
add_executable(get_a_bit get_a_bit.cpp)
add_executable(obtain_bit_using_struct obtain_bit_using_struct.cpp)
add_executable(reset_a_bit reset_a_bit.cpp)
add_executable(set_a_bit set_a_bit.cpp)
add_executable(test_even_odd test_even_odd.cpp)
