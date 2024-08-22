cmake_minimum_required(VERSION 3.25)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra -Werror)

set(NAME minirt)
project(${NAME} C CXX)

set(LIB_NAME ${NAME})
set(EXEC_NAME minirt_exec)
set(TEST_NAME minirt_test)

option(ENABLE_COVERAGE "Enable coverage" OFF)
if(ENABLE_COVERAGE)
	add_compile_options(--coverage)
	link_libraries(--coverage)
endif()

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

FetchContent_Declare(
    minilibx
    GIT_REPOSITORY https://github.com/shelldivers/minilibx.git
    GIT_TAG v1.0.2
)
FetchContent_MakeAvailable(minilibx)
add_custom_target(build_minilibx ALL
	COMMAND make -C ${minilibx_SOURCE_DIR} -j1
	COMMAND cp ${minilibx_SOURCE_DIR}/libmlx.dylib ${CMAKE_BINARY_DIR}
)
set(MINILIBX_LIBRARY ${minilibx_SOURCE_DIR}/libmlx.dylib)

# build minirt library
file(GLOB_RECURSE SRC_FILES "srcs/*.c")
add_library(${LIB_NAME} STATIC ${SRC_FILES})
add_dependencies(${LIB_NAME} build_minilibx)
target_link_libraries(${LIB_NAME} libft ${MINILIBX_LIBRARY})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_LIBFT_SRC_DIR}/includes)

# build minirt executable
add_executable(${EXEC_NAME} "main.c")
add_dependencies(${EXEC_NAME} build_minilibx)
target_link_libraries(${EXEC_NAME} ${LIB_NAME} libft ${MINILIBX_LIBRARY})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes ${CMAKE_LIBFT_SRC_DIR}/includes ${minilibx_SOURCE_DIR})

add_custom_target(mlx
	COMMAND cp ${CMAKE_SOURCE_DIR}/example.rt ${CMAKE_BINARY_DIR}
	COMMAND cp -r ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_BINARY_DIR}/${EXEC_NAME} example.rt
    DEPENDS ${EXEC_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# build minirt test executable
file(GLOB_RECURSE TEST_SRC_FILES "test/*.cpp")
add_executable(${TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${TEST_NAME} build_minilibx)
target_link_libraries(${TEST_NAME} ${LIB_NAME} libft gtest ${MINILIBX_LIBRARY})

# add tests
add_test(
	NAME ${TEST_NAME}
	COMMAND ${TEST_NAME}
)

# build coverage
add_custom_target(coverage
	COMMAND find ${CMAKE_BINARY_DIR} -name "*.gcda" -type f -print0 | xargs -0 rm
	COMMAND ${CMAKE_COMMAND} -B${CMAKE_BINARY_DIR} -DENABLE_COVERAGE=ON ${CMAKE_SOURCE_DIR}
	COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${TEST_NAME}
	COMMAND ${CMAKE_BINARY_DIR}/${TEST_NAME}
	COMMAND mkdir -p ${CMAKE_BINARY_DIR}/reports
	COMMAND gcovr -r ${CMAKE_SOURCE_DIR}
				-e '${CMAKE_BINARY_DIR}/_deps/*'
				-e '${CMAKE_SOURCE_DIR}/test/*'
				--html --html-details
				-o '${CMAKE_BINARY_DIR}/reports/test-coverage.html'
	COMMAND find ${CMAKE_BINARY_DIR} -name "*.gcda" -type f -print0 | xargs -0 rm
	COMMAND rm -f ${CMAKE_BINARY_DIR}/${TEST_NAME} ${CMAKE_BINARY_DIR}/${EXEC_NAME} 
)