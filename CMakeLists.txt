cmake_minimum_required(VERSION 3.24)
project(Final_Project_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Final_Project_2
        hashtable.cpp
        hashtable.h main.cpp Food.h Food.cpp)
