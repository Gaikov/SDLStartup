cmake_minimum_required(VERSION 3.13)
project(SDLTest)

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
    message(SEND_ERROR "Failed to find SDL")
    return()
else()
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

add_executable(SDLTest main.cpp)
target_link_libraries(SDLTest ${SDL2_LIBRARIES})

#print_all_variables()
