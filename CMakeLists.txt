cmake_minimum_required(VERSION 3.17)
project(hw_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw_1 main.c my_list.c my_list.h date.c date.h doc.c doc.h gtest/dateTest.cpp)

add_subdirectory(gtest)
