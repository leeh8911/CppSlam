cmake_minimum_required(VERSION 3.11.3)

project(CPP_SLAM)

set(PROJECT_NAME CPP_SLAM)
set(TEST_NAME CPP_SLAM_TEST)

# Set the C++ standard we will use
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)

add_subdirectory(test)

add_dependencies(${TEST_NAME} ${PROJECT_NAME})