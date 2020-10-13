cmake_minimum_required(VERSION 3.9.2)
project(hw_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw_1 src/main.c src/my_list.c include/my_list.h src/date.c include/date.h src/doc.c include/doc.h)

add_subdirectory(tests)
