cmake_minimum_required(VERSION 3.11)

project(MySingleton)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.h" 
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(MySingletonLib SHARED ${SOURCES})

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(MySingleton main.cpp)
target_link_libraries(MySingleton MySingletonLib)
