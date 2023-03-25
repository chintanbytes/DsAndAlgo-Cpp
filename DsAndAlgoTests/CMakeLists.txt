cmake_minimum_required(VERSION 3.0.0)
set(this DsAndAlgoTests)

set(Sources
    LinkedListTests.cpp
)

project(${this})

add_executable(${this} ${Sources})