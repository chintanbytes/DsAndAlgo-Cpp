cmake_minimum_required(VERSION 3.0.0)
set(this DsAndAlgoTests)

set(Sources
    LinkedListTests.cpp
    DoublyLinkedListTests.cpp
    CircularLinkedListTests.cpp
    SortingTests.cpp
    SearchingTests.cpp
    RecursionTests.cpp
    StacksTests.cpp
)

project(${this})

add_executable(${this} ${Sources})

target_link_libraries(${this} PUBLIC
    gtest_main
    DsAndAlgo    
)

add_test(
    NAME ${this}
    COMMAND ${this}
)