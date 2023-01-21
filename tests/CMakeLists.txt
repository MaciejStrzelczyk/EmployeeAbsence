cmake_minimum_required(VERSION 3.23)

project(Google_tests)

add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
                employeeTest.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)