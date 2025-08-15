# header-begin ------------------------------------------
# File       : CMakeLists.txt
#
# Author      : Joshua E
# Email       : estesjn2020@gmail.com
#
# Created on  : 8/3/2025
#
# header-end --------------------------------------------

cmake_minimum_required(VERSION 3.10)
project(HypercomplexNumberLibrary)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER "/usr/bin/gcc-14")
set(CMAKE_CXX_COMPILER "/usr/bin/g++-14")

find_package(CUDAToolkit REQUIRED)

include_directories(include ${CUDAToolkit_INCLUDE_DIRS})

find_package(GTest REQUIRED)
add_executable(example src/main.cpp)
add_executable(complex_test tests/complex_tests.cpp)

target_link_libraries(example)
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