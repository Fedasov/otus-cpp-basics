cmake_minimum_required(VERSION 3.5)

project(index)

add_executable(index
    src/index.cpp
    src/random.cpp
    src/inter.cpp
    src/slovar_resultatov.cpp
)

target_include_directories(index PRIVATE include)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR  
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(index PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(index PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()


target_compile_features(index PUBLIC cxx_std_17)