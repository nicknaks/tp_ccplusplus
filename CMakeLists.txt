cmake_minimum_required(VERSION 3.9.2)
project(hw_1 C)

set(CMAKE_C_STANDARD 99)

set(SOURCES src/main.c src/my_list.c src/date.c src/doc.c)

add_executable(hw_1 ${SOURCES})

add_subdirectory(tests)
