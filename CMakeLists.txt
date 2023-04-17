cmake_minimum_required(VERSION 3.24)
project(COP3530-Project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(COP3530-Project3
         main.cpp Food.h Food.cpp RBTree.h RBTree.cpp)
