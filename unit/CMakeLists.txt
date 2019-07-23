cmake_minimum_required(VERSION 3.13)
project(unit)

add_definitions(-DBOOST_TEST_MAIN -DBOOST_TEST_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})

set(TESTS
        ExampleTest.cpp
        ExampleTest2.cpp)

add_executable(unit ${TESTS})

target_link_libraries(unit ${Boost_LIBRARIES})