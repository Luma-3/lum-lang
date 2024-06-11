cmake_minimum_required(VERSION 3.10)

Project(LumLang)

set(CMAKE_CXX_STANDARD 11)

option(ENABLE_DEBUG "Enable debug" OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -O3")

if(ENABLE_DEBUG)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -DDEBUG")
endif()

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sources)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

add_executable(LumLang ${SOURCES})

add_subdirectory(includes)

enable_testing()
add_subdirectory(tests)
