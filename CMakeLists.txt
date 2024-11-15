cmake_minimum_required(VERSION 3.29)
project(bloom_engine)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(bloom_engine src/main.cpp
        src/keys.h
        src/glad.c
        src/catv/vector.h
        src/catv/matrix.h
        src/catv/lintr.h
        src/bloom/vision/shader.cpp
        src/bloom/vision/shader.h
        src/bloom/vision/vbo.cpp
        src/bloom/vision/vbo.h
        src/bloom/vision/ebo.cpp
        src/bloom/vision/ebo.h
        src/bloom/vision/vao.cpp
        src/bloom/vision/vao.h)

# GLFW INCLUDE
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/glfw)
target_link_libraries(bloom_engine glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(bloom_engine OpenGL::GL)


