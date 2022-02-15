cmake_minimum_required(VERSION 3.20)
project(5b C)

set(CMAKE_C_STANDARD 11)

add_executable(5b main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h)
