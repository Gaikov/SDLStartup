cmake_minimum_required(VERSION 3.13)
project(unit)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIR})

add_executable(unit ExampleTest.cpp)

target_link_libraries(unit ${Boost_LIBRARIES})