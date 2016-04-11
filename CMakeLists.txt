cmake_minimum_required(VERSION 2.8)
project(dire)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)
set(SOURCE_FILES main.c)
add_executable(dire ${SOURCE_FILES})