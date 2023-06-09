cmake_minimum_required(VERSION 3.5)

project(01.index)

add_executable(index
    index.cpp
)

set_target_properties(index PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)