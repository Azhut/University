cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp "Node.h" TestStack.cpp printStack.cpp INIT.cpp PushBox.cpp DeleteBox.cpp)
