cmake_minimum_required(VERSION 3.16)
project(lab_2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(lab_2_lib
    src/lab_2.cpp
)

enable_testing()
add_executable(run_tests_lab_2
    tests/test_lab_2.cpp
    src/lab_2.cpp
)
target_link_libraries(run_tests_lab_2 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests_lab_2)
