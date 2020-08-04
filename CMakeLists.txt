cmake_minimum_required(VERSION 3.17)
project(ENCE260 C)

set(CMAKE_C_STANDARD 11)

add_executable(ENCE260
        expressions.c
        lab2.c
        lab2_2.c
        test1.c)

target_link_libraries(ENCE260 C)