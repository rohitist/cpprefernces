cmake_minimum_required(VERSION 3.0.0)

set(BUILD_FLAGS -Wall ${STD_COMPILER_VERSION})

add_executable(test_a_code test_a_code.cpp)
add_executable(reverse_words_in_sentence reverse_words_in_sentence.cpp)
add_executable(to_lower_basic to_lower_basic.cpp)
add_executable(stringreverse stringreverse.cpp)
add_executable(replace_word_in_sentence replace_word_in_sentence.cpp)
add_executable(replace_words_in_sentence replace_words_in_sentence.cpp)
