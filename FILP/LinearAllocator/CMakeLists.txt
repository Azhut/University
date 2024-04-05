cmake_minimum_required(VERSION 3.27)
project(LinearAllocator)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        LinearAllocator
        main.cpp
        LinearAllocator.cpp
        LinearAllocator.h
)
