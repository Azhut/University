cmake_minimum_required(VERSION 3.27)
project(LynearLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(LynearLinkedList main.cpp
        CList.tpp
        CList.h)
