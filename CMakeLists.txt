cmake_minimum_required(VERSION 3.29)
project(bloom_engine)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(bloom_engine src/main.cpp
        src/keys.h
        src/glad.c
        src/engine.cpp
        src/engine.h)

# GLFW INCLUDE
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
target_link_libraries(bloom_engine glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(bloom_engine OpenGL::GL)


