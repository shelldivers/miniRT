cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror)

set(NAME minirt_exec)
set(LIB_NAME minirt)
set(TEST_NAME minirt_test)

option(ENABLE_COVERAGE "Enable GCC Coverage" OFF)

if(ENABLE_COVERAGE)
	add_compile_options(--coverage)
	link_libraries(--coverage)
endif()

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

# add tests
add_test(
	NAME ${TEST_NAME}
	COMMAND ${TEST_NAME}
)

# add coverage
add_custom_target(coverage
	COMMAND find ${CMAKE_BINARY_DIR} -name "*.gcda" -print0 | xargs -0 rm
	COMMAND ${CMAKE_COMMAND} -B${CMAKE_BINARY_DIR} -DENABLE_COVERAGE=ON ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${TEST_NAME}
	COMMAND ${CMAKE_BINARY_DIR}/${TEST_NAME}
	COMMAND gcovr -r ${CMAKE_SOURCE_DIR}
				-e '${CMAKE_BINARY_DIR}/_deps/googletest-src/*'
				-e '${CMAKE_BINARY_DIR}/_deps/libft-src/*'
				-o '${CMAKE_BINARY_DIR}/test-coverage.xml'
	COMMAND find ${CMAKE_BINARY_DIR} -name "*.gcda" -print0 | xargs -0 rm
)
