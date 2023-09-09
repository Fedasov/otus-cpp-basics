cmake_minimum_required(VERSION 3.25)
project(HW06_containers)


include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG 703bd9caab50b139428cea1aaff9974ebee5742e
#        GIT_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850
)

FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(HW06_containers main.cpp my_containers/My_vector.h my_containers/My_list.h)
add_executable(containers_test test/containers_test.cpp
        my_containers/My_vector.h my_containers/My_vector.h
        test/DestructorTracer.cpp test/DestructorTracer.h)

target_include_directories(
        HW06_containers
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/my_containers")


target_include_directories(
        containers_test
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/my_containers" "${CMAKE_CURRENT_SOURCE_DIR}/test")

target_link_libraries(containers_test PRIVATE gtest gtest_main)

set_target_properties(HW06_containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(containers_test PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)


if (MSVC)
    target_compile_options(
            HW06_containers PRIVATE
            /W4
    )
    target_compile_options(
            containers_test PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
else ()
    target_compile_options(
            HW06_containers PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
            containers_test PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
endif()