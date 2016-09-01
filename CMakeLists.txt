cmake_minimum_required(VERSION 2.7)

project(cxxalgo CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")
set(PROJECT_TEST_NAME ctest)

include_directories(include)

# used in unittest and profile.
include(cmake/gtest.cmake)

## unittest

add_custom_target(unittest)

function(add_unittest test_name source)
  add_executable(${test_name}-test EXCLUDE_FROM_ALL ${source})
  target_link_libraries(${test_name}-test gtest gtest_main pthread util)

  add_custom_target(${test_name}-test-exec COMMAND $<TARGET_FILE:${test_name}-test> "--gtest_output=xml:${test_name}-unittest.xml")

  add_dependencies(unittest ${test_name}-test-exec)
  add_dependencies(${test_name}-test-exec ${test_name}-test)
endfunction(add_unittest)

add_subdirectory(test)

## profile

add_custom_target(profile)

function(add_profile profile_name source)
  add_executable(${profile_name}-profile EXCLUDE_FROM_ALL ${source})
  target_link_libraries(${profile_name}-profile gtest gtest_main pthread util)

  add_custom_target(${profile_name}-profile-exec COMMAND $<TARGET_FILE:${profile_name}-profile> "--gtest_output=xml:${profile_name}-profile.xml")

  add_dependencies(profile ${profile_name}-profile-exec)
  add_dependencies(${profile_name}-profile-exec ${profile_name}-profile)
endfunction(add_profile)

add_subdirectory(profile)

## coverage

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
if(CMAKE_COMPILER_IS_GNUCXX AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    include(CodeCoverage)
    setup_target_for_coverage(coverage ${PROJECT_TEST_NAME} coverage)
endif()
