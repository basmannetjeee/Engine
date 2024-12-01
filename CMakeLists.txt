cmake_minimum_required(VERSION 3.28)
project(OPENSCREAML)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)

add_executable(OPENSCREAML
    src/main.cpp
    src/engine/utilities/shapes/2D/rectangle/rectangle.cpp
    src/engine/utilities/shaders/shaders.cpp
    src/engine/utilities/math/math.cpp
    src/engine/utilities/fps/fps.cpp
    src/engine/engine.cpp
    src/engine/loop.cpp
)

target_link_libraries(OPENSCREAML
    ${SDL2_LIBRARIES}
    OpenGL::GL
)
