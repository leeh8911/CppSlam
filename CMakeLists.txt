cmake_minimum_required(VERSION 3.11.3)

project(AUTONOMOUS_DRIVING_FRAMEWORK)

set(PROJECT_NAME AUTONOMOUS_DRIVING_FRAMEWORK)
set(TEST_NAME AD_TEST)

# Set the C++ standard we will use
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_STANDARD 14)

find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
message(STATUS "activate clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "${CLANGTIDY};-extra-arg=-Wno-unknown-warning-option;-header-filter=${CMAKE_SOURCE_DIR}/src/*;-fix")
else()
message(SEND_ERROR "clang-tidy requested but executable not found")
endif()

add_subdirectory(src)

add_subdirectory(test)

add_dependencies(${TEST_NAME} ${PROJECT_NAME})