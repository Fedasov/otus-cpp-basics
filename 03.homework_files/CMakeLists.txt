cmake_minimum_required(VERSION 3.5)

project(index)

add_executable(index
    src/index.cpp
    src/random.cpp
    src/inter.cpp
    src/slovar_resultatov.cpp
)

target_include_directories(index PRIVATE include)


# if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR   #  следующее предупреждение рассматривается как ошибка: преобразование "time_t" в "unsigned int", возможн
                                                 #  а потеря данных [C:\Users\User\Desktop\Plus\03.homework_files\build\index.vcxproj]
#     CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     target_compile_options(index PRIVATE 
#         -g
#         -Wall
#         -Wextra
#         -Werror
#         -pedantic
#     )
# elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#     target_compile_options(index PRIVATE
#         /EHsc
#         /W4
#         /WX
#     )
# endif()

set_target_properties(index PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)