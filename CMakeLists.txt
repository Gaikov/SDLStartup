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

include_directories(./src)

find_package(OpenGL REQUIRED)

set(SOURCES
        src/desktop/main.cpp
        src/GLTexture.cpp
        src/GLUtils.cpp
        src/desktop/DevilUtils.cpp
        src/GLDebug.cpp
        src/GLTexturesCache.cpp
        src/BitmapData.cpp
        src/ResourcesCache.cpp
        src/GLRenderer.cpp
        src/GLVertexBuffer.cpp
        src/functional/IFunctionalTest.cpp
        src/functional/TexturesTest.cpp
        src/functional/TexturesTest.cpp
        src/functional/FunctionalTestRunner.cpp
        src/functional/VertexColorTest.cpp
        src/engine/Engine.cpp
        src/desktop/DesktopGameApp.cpp
        src/desktop/DevilImagesDecoder.cpp
)

add_executable(SDLTest ${SOURCES})

target_link_libraries(SDLTest
        glfw
        ${OPENGL_LIBRARIES}
        ${IL_LIBRARIES}
        ${ILU_LIBRARIES}
        ${ILUT_LIBRARIES})

print_all_variables()
