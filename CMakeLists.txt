cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(NAME minirt)
set(TEST_NAME minirt_test)

project(${NAME} C CXX)

# CTest
enable_testing()

include(FetchContent)

# add_subdirectory(googletest)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.14.x
)
FetchContent_MakeAvailable(googletest)

# add_subdirectory(libft)
FetchContent_Declare(
	libft
	GIT_REPOSITORY https://github.com/shelldivers/libft.git
	GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(libft)
set(CMAKE_LIBFT_SRC_DIR ${CMAKE_BINARY_DIR}/_deps/libft-src)

# add minirt
file(GLOB_RECURSE SRC_FILES "srcs/*.c")
add_library(${NAME} STATIC ${SRC_FILES})
target_link_libraries(${NAME} libft)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_LIBFT_SRC_DIR}/includes)

# add minirt_test
file(GLOB_RECURSE TEST_FILES "test/*.cpp")
add_executable(${TEST_NAME} ${TEST_FILES})
target_link_libraries(${TEST_NAME} ${NAME} libft gtest_main)
