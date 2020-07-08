cmake_minimum_required(VERSION 3.16)
project(TestTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "-Werror -Wpedantic -std=c++1z")

set(includes ${PROJECT_SOURCE_DIR}/include)
include_directories(${includes})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(TestTask ${sources} main.cpp)

