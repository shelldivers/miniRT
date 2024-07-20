cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror)

set(NAME minirt)
set(LIB_NAME libminirt)
set(TEST_NAME minirt_test)

add_compile_options(--coverage)
link_libraries(--coverage)

project(${NAME} C CXX)

# CTest
enable_testing()

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.14.x
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
	libft
	GIT_REPOSITORY https://github.com/shelldivers/libft.git
	GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(libft)
set(CMAKE_LIBFT_SRC_DIR ${CMAKE_BINARY_DIR}/_deps/libft-src)

# build minirt library
file(GLOB_RECURSE SRC_FILES "srcs/*.c")
add_library(${LIB_NAME} STATIC ${SRC_FILES})
target_link_libraries(${LIB_NAME} libft)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_LIBFT_SRC_DIR}/includes)

# build minirt executable
add_executable(${NAME} "minirt.c")
target_link_libraries(${NAME} ${LIB_NAME} libft)

# build minirt test executable
file(GLOB_RECURSE TEST_SRC_FILES "test/*.cpp")
add_executable(${TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${TEST_NAME} ${LIB_NAME} libft gtest_main)

add_test(
	NAME ${TEST_NAME}
	COMMAND ${TEST_NAME}
)

add_custom_target(coverage
  COMMAND gcovr --root ${CMAKE_SOURCE_DIR} --exclude '${CMAKE_SOURCE_DIR}/build/_deps/googletest-src/*' --exclude '${CMAKE_SOURCE_DIR}/build/_deps/libft-src/*'
)