cmake_minimum_required(VERSION 3.24)
project(Library_management_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library_management_system
        main.cpp classes.h functions.h)

configure_file(library_data.txt ${CMAKE_BINARY_DIR}/library_data.txt COPYONLY)