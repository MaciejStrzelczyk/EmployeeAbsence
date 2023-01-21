cmake_minimum_required(VERSION 3.23)
project(absence_app)

set(CMAKE_CXX_STANDARD 20)

add_executable(absence_app main.cpp
        include/employee.h
        src/employee.cpp
        include/absence.h
        src/absence.cpp
        include/loadAndSendFiles.h
        src/loadAndSendFiles.cpp
        include/employeeRepository.h
        src/employeeRepository.cpp)

add_subdirectory(tests/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run
        tests/employeeTest.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main)