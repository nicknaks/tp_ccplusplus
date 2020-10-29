cmake_minimum_required(VERSION 3.17)
project(hw2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -fPIC")

#find_package(GTest REQUIRED)
find_package(Threads REQUIRED)


set(SOURCE_FILES project/my_array/Array.c project/my_list/List.c project/Employee.c)
set(HEADER_FILES project/my_array/Array.h project/my_list/List.h project/Employee.h)


if (MULTI_THREAD)
    set(lib SharedLib)
    set(print_node project/my_list/parallel.c)
else()
    set(lib StaticLib)
    set(print_node project/my_list/static.c)
endif()


#---------------STATIC LIB------------------------
add_library(StaticLib STATIC ${SOURCE_FILES} ${print_node})
target_link_libraries(StaticLib)
target_include_directories(StaticLib PUBLIC include)

#---------------STATIC LIB------------------------

#---------------SHARED LIB------------------------
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
add_library(SharedLib SHARED project/my_array/Array.c project/my_list/List.c project/Employee.c ${print_node})
target_link_libraries(SharedLib)
target_include_directories(SharedLib PUBLIC include)
#---------------SHARED LIB------------------------

add_executable(TestLib main.c)

add_subdirectory(test)

target_link_libraries(TestLib ${lib})