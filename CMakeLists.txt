cmake_minimum_required(VERSION 3.17)
project(CS301_HW03_Unsorted_Lists)

set(CMAKE_CXX_STANDARD 14)

include_directories(tests)

add_executable(ListsDriver
        UnsortedListDriver.cpp
        ArrayADTList.cpp
        ArrayADTList.h
        LinkedADTList.cpp
        LinkedADTList.h)

add_executable(ArrayTest
        tests/array_test.cpp
        tests/catch.hpp
        ArrayADTList.cpp
        ArrayADTList.h )

add_executable(LinkedTest
        tests/linked_test.cpp
        tests/catch.hpp
        LinkedADTList.cpp
        LinkedADTList.h )

