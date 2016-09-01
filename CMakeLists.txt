cmake_minimum_required(VERSION 2.7)

project(cxxalgo CXX)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")
set(PROJECT_TEST_NAME ctest)

include_directories(include)

## test

if(NOT without-test)
  enable_testing()
  include(cmake/gtest.cmake)

  function(add_google_test test_name source)
    add_executable(${test_name}-test ${source})
    target_link_libraries(${test_name}-test gtest gtest_main pthread util)
    add_test(NAME ${test_name}
      COMMAND $<TARGET_FILE:${test_name}-test> "--gtest_output=xml:${test_name}-gtest.xml"
    )
    set_property(TEST ${test_name} PROPERTY LABELS ${test_name})
  endfunction(add_google_test)

  add_subdirectory(test)
endif()

## coverage

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
if(CMAKE_COMPILER_IS_GNUCXX AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    include(CodeCoverage)
    setup_target_for_coverage(coverage ${PROJECT_TEST_NAME} coverage)
endif()
