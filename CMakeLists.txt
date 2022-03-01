cmake_minimum_required(VERSION 3.20)
project(5b C)

set(CMAKE_C_STANDARD 11)

add_executable(5b main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h string/tasks/string_.c string/tasks/string_.h)

add_library(str string/tasks/string_.h string/tasks/string_.c)

target_link_libraries(5b str)