cmake_minimum_required(VERSION 3.0.0)
set(this DsAndAlgo)

project(${this} VERSION 0.1.0)

include(ctest)
include(GoogleTest)
enable_testing()

set(Headers
    LinkedList/Node.h
    LinkedList/LinkedList.h
    LinkedList/Doubly.h
    LinkedList/Circular.h)

set(Sources
    CppBasic/BuiltIns.cpp    
    LinkedList/LinkedList.cpp
    LinkedList/Doubly.cpp
    LinkedList/Circular.cpp
    Sorting/Sorting.cpp
    Searching/Searching.cpp
    Recursion/Recursion.cpp
    Stack/Stacks.cpp
    Queue/Queues.cpp
    Tree/TreeNode.cpp
    Tree/Tree.cpp
    Tree/BinaryTreeNode.cpp
    Tree/BinaryTree.cpp
    Tree/Bst.cpp)

add_library(${this} ${Sources} ${Headers})
target_compile_features(${this} PUBLIC cxx_std_20)

add_subdirectory(DsAndAlgoTests)
add_subdirectory(googletest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
