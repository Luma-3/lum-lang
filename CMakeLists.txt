cmake_minimum_required(VERSION 3.10)

Project(LumLang)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic")

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sources)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

add_executable(LumLang ${SOURCES})

add_subdirectory(includes)
add_subdirectory(tests)
enable_testing()