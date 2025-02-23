cmake_minimum_required(VERSION 3.11)

project(MyCache)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.h" 
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(MyArgParserLib SHARED ${SOURCES})

include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(main main.cpp)
target_link_libraries(main MyArgParserLib)
