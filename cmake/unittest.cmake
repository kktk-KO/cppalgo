cmake_minimum_required(VERSION 2.7)

find_program(GCOV_PATH gcov)
find_program(LCOV_PATH lcov)
FIND_PROGRAM(GENHTML_PATH genhtml)

IF(NOT GCOV_PATH)
	MESSAGE(FATAL_ERROR "missing gcov.")
ENDIF() # NOT GCOV_PATH

SET(CMAKE_CXX_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds."
    FORCE
)
SET(CMAKE_C_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C compiler during coverage builds."
    FORCE
)
SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used for linking binaries during coverage builds."
    FORCE
)
SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    ""
    CACHE STRING "Flags used by the shared libraries linker during coverage builds."
    FORCE
)
MARK_AS_ADVANCED(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE
)

set(coverage_info "${CMAKE_BINARY_DIR}/${_outputname}.info")
set(coverage_cleaned "${coverage_info}.cleaned")

add_custom_target(unittest)
add_custom_target(coverage
  COMMAND ${LCOV_PATH} --directory . --zerocounters
  COMMAND make unittest
  COMMAND ${LCOV_PATH} --directory . --rc lcov_branch_coverage=1 --capture --output-file ${coverage_info}
  COMMAND ${LCOV_PATH} --rc lcov_branch_coverage=1 --remove ${coverage_info} 'tests/*' '/usr/*' --output-file ${coverage_cleaned}
  COMMAND ${GENHTML_PATH} -o coverage ${coverage_cleaned} --function-coverage --branch-coverage --demangle-cpp
	COMMAND ${CMAKE_COMMAND} -E remove ${coverage_info} ${coverage_cleaned}
)

function(add_unittest test_name source)
  add_executable(${test_name}-test EXCLUDE_FROM_ALL ${source})
  target_link_libraries(${test_name}-test gtest gtest_main pthread util)

  add_custom_target(${test_name}-test-exec
    COMMAND $<TARGET_FILE:${test_name}-test> "--gtest_output=xml:${test_name}-unittest.xml"
  )

  add_dependencies(unittest ${test_name}-test-exec)
  add_dependencies(${test_name}-test-exec ${test_name}-test)
endfunction(add_unittest)

add_subdirectory(test)

