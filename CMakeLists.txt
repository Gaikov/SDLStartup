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
    include_directories(${SDL2_INCLUDE_DIRS}
            ${SDL2_INCLUDE_DIRS}/.. #fix on macOS
            )
endif()

find_package(OPENGL REQUIRED)
if(NOT OPENGL_FOUND)
    message(SEND_ERROR "Failed to find OPENGL")
    return()
endif()

set(SOURCES
        main.cpp
        GLTexture.cpp headers.h GLUtils.cpp GLUtils.h TextureUtils.cpp TextureUtils.h)

add_executable(SDLTest ${SOURCES})
target_link_libraries(SDLTest ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} SDL2_image)

#print_all_variables()
