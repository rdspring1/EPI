cmake_minimum_required (VERSION 2.8)
project (EPI)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build)
set (CMAKE_C_FLAGS			"-std=c99 -pedantic -g -O0")

include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories (${CMAKE_SOURCE_DIR})

add_executable(ll_cycle ll_cycle.cpp)
