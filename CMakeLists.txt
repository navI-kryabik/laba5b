cmake_minimum_required(VERSION 3.20)
project(5b C)

set(CMAKE_C_STANDARD 11)

add_executable(5b main.c libs/data_structures/vector/vector.c libs/data_structures/vector/vector.h libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h string/string_.c string/string_.h string/tasks/removeNonLetters.h string/tasks/replacingNumbersWithSpaces.h string/tasks/removeAdjacentEqualLetters.h string/tasks/puttingWordsInReverseOrder.h string/tasks/haveTheSameWords.h string/tasks/startReversedNumbersEndLetters.h)

add_library(str string/string_.h string/string_.c string/tasks/removeNonLetters.h string/tasks/removeAdjacentEqualLetters.h string/tasks/puttingWordsInReverseOrder.h string/tasks/haveTheSameWords.h string/tasks/startReversedNumbersEndLetters.h)

target_link_libraries(5b str)