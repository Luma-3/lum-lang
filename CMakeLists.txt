cmake_minimum_required(VERSION 3.10)

Project(LumLang)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -g3 -O3 ")

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sources)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

add_executable(LumLang ${SOURCES})

add_subdirectory(includes)

option(ENABLE_TESTS "Enable tests" OFF)

if (ENABLE_TESTS)
	enable_testing()
	add_subdirectory(tests)
endif()