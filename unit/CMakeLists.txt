cmake_minimum_required(VERSION 3.13)
project(unit)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})

set(TESTS
        example/ExampleTest.cpp
        example/ExampleTest2.cpp
        UnitCommon.h
        main.cpp)

add_executable(unit ${TESTS})

target_link_libraries(unit ${Boost_LIBRARIES})