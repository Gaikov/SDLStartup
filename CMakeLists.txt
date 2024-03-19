cmake_minimum_required(VERSION 3.13)
project(SDLTest)

add_subdirectory(unit)

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()

set(CMAKE_CXX_STANDARD 17)

find_package(DevIL REQUIRED)

find_package(GLFW3 REQUIRED)

include_directories(./)

find_package(OpenGL REQUIRED)

set(SOURCES
        main.cpp
        GLTexture.cpp
        GLUtils.cpp
        TextureUtils.cpp
        GLDebug.cpp
        GLTexturesCache.cpp
        BitmapData.cpp
        ResourcesCache.cpp
        GLRenderer.cpp
        GLVertexBuffer.cpp
        functional/IFunctionalTest.cpp
        functional/TexturesTest.cpp
        functional/TexturesTest.cpp
        functional/FunctionalTestRunner.cpp functional/VertexColorTest.cpp functional/VertexColorTest.h)

add_executable(SDLTest ${SOURCES})

target_link_libraries(SDLTest
        glfw
        ${OPENGL_LIBRARIES}
        ${IL_LIBRARIES}
        ${ILU_LIBRARIES}
        ${ILUT_LIBRARIES})

print_all_variables()
