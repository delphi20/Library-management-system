cmake_minimum_required(VERSION 3.24)
project(Library_management_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library_management_system
        main.cpp classes.h)

configure_file(books.txt ${CMAKE_BINARY_DIR}/books.txt COPYONLY)