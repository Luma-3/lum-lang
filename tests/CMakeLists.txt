find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/includes)

set(TEST_SOURCES
	${SOURCE_DIR}/FileManager.cpp
	FileManagerTest.cpp
)

add_executable(FileManagerTest ${TEST_SOURCES})
target_include_directories(FileManagerTest PUBLIC ${CMAKE_SOURCE_DIR}/includes)

target_link_libraries(FileManagerTest ${GTEST_LIBRARIES} pthread )


add_test(
	NAME FileManagerTest
	COMMAND FileManagerTest
)

