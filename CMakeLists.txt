cmake_minimum_required(VERSION 3.16)
project(Ancestor_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ancestor_Tree
        Demo.cpp
        FamilyTree.cpp
        FamilyTree.hpp
        )
