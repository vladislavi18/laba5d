cmake_minimum_required(VERSION 3.20)
project(laba5d C)

set(CMAKE_C_STANDARD 11)

add_executable(laba5d main.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h)
