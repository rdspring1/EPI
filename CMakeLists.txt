cmake_minimum_required (VERSION 2.8)
project (EPI)

set (CMAKE_CXX_FLAGS			"-std=c++11 -pedantic -g -O0")

include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories (${CMAKE_SOURCE_DIR})

file(GLOB SUPPORT_SRC_FILES "src/*.cpp")
file(GLOB EXERCISE_SRC_FILES "exercises/*.cpp")

add_executable(EPI ${SUPPORT_SRC_FILES} ${EXERCISE_SRC_FILES} epi.cpp)
target_link_libraries(EPI gtest pthread)
