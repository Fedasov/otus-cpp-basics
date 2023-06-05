cmake_minimum_required(VERSION 3.5)

project(01.hello_github)

add_executable(hello_github
    Hello_GitHub.cpp
)

set_target_properties(hello_github PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)