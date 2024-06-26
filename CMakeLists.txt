cmake_minimum_required(VERSION 3.25)

set(NAME minirt)
set(TEST_NAME minirt_test)

project(${NAME} C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

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

# add minirt
file(GLOB_RECURSE SRC_FILES "srcs/*.c")
file(GLOB_RECURSE INCLUDE_FILES "includes/*.h")
add_library(${NAME} STATIC ${SRC_FILES} ${INCLUDE_FILES})
target_link_libraries(${NAME} libft)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_BINARY_DIR}/_deps/libft-src/includes)

# add test
file(GLOB_RECURSE TEST_FILES "test/*.cpp")
add_executable(${TEST_NAME} ${TEST_FILES})
target_link_libraries(${TEST_NAME} libft gtest_main)
