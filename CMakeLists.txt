cmake_minimum_required(VERSION 3.9.2)
project(hw2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -fPIC")

find_package(Threads REQUIRED)


set(SOURCE_FILES project/my_array/Array.c project/my_list/List.c project/employee/Employee.c)
set(HEADER_FILES project/my_array/Array.h project/my_list/List.h project/employee/Employee.h)


if (MULTITHREADING)
    set(WorkWithEmployeesLib SharedLib)
    set(position_split project/my_list/parallel.c)
else()
    set(WorkWithEmployeesLib StaticLib)
    set(position_split project/my_list/static.c)
endif()

#---------------STATIC LIB------------------------

add_library(StaticLib STATIC ${SOURCE_FILES} ${position_split})
target_include_directories(StaticLib PUBLIC include)

#---------------STATIC LIB------------------------



#---------------SHARED LIB------------------------

set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
add_library(SharedLib SHARED ${SOURCE_FILES} ${position_split})
target_link_libraries(SharedLib pthread)
target_include_directories(SharedLib PUBLIC include)

#---------------SHARED LIB------------------------

set(SOURCE project/main.c)

add_executable(hw2 ${SOURCE})

add_subdirectory(test)

target_link_libraries(hw2 ${WorkWithEmployeesLib})