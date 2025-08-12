# header-begin ------------------------------------------
# File       : CMakeLists.txt
#
# Author      : Unknown Author
# Email       : unknown@example.com
#
# Created on  : 8/3/2025
#
# header-end --------------------------------------------

cmake_minimum_required(VERSION 3.10)
project(HypercomplexNumberLibrary)

enable_testing()

set(CMAKE_C_COMPILER "/usr/bin/gcc-14")
set(CMAKE_CXX_COMPILER "/usr/bin/g++-14")

# set(CMAKE_C_COMPILER "/usr/bin/clang")
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

include_directories(include)

find_package(GTest REQUIRED)
add_executable(example src/main.cpp)
add_executable(complex_test tests/complex_tests.cpp)
target_link_libraries(complex_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(complex_test)

# add_custom_target(run_tests ALL
#   COMMAND ${CMAKE_CTEST_COMMAND} --verbose --output-on-failure
#   DEPENDS complex_test
#   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#   COMMENT "Running unit tests..."
# )

# footer-begin ------------------------------------------
# default.PlainText
# File       : CMakeLists.txt
# footer-end --------------------------------------------