cmake_minimum_required(VERSION 2.7)

project(cxxalgo CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")
set(PROJECT_TEST_NAME ctest)

include_directories(include)

# used in unittest and profile.
include(cmake/gtest.cmake)
include(cmake/benchmark.cmake)
include(cmake/unittest.cmake)
include(cmake/profile.cmake)
