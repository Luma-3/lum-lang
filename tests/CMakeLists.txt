find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/includes)

set(SRC_FILEMANAGER
	${SOURCE_DIR}/FileManager.cpp
	FileManagerTest.cpp
)

set(SRC_TOKEN
	${SOURCE_DIR}/Token.cpp
	TokenTest.cpp
)

add_executable(FileManagerTest ${SRC_FILEMANAGER})
target_include_directories(FileManagerTest PUBLIC ${CMAKE_SOURCE_DIR}/includes)

target_link_libraries(FileManagerTest ${GTEST_LIBRARIES} pthread )

add_executable(TokenTest ${SRC_TOKEN})
target_include_directories(TokenTest PUBLIC ${CMAKE_SOURCE_DIR}/includes)

target_link_libraries(TokenTest ${GTEST_LIBRARIES} pthread )

add_test(
	NAME FileManagerTest
	COMMAND ./FileManagerTest
)

add_test(
	NAME TokenTest
	COMMAND ./TokenTest
)

