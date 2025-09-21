cmake_minimum_required(VERSION 3.16)
project(lab_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(lab_1
    src/main.cpp
    src/lab_1.cpp
)

add_subdirectory(external/googletest)
enable_testing()

add_executable(run_tests_lab_1
    tests/test_lab_1.cpp
    src/lab_1.cpp
)

target_link_libraries(run_tests_lab_1 gtest gtest_main)

add_test(NAME Lab1Tests COMMAND run_tests_lab_1)
