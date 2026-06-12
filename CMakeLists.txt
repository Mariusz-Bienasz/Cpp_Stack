cmake_minimum_required(VERSION 4.1)
project(Stack)

set(CMAKE_CXX_STANDARD 20)

add_executable(Stack main.cpp
        Stack.h
        Node.h
        FullStackException.h)
