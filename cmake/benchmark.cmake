cmake_minimum_required(VERSION 2.8)

# Google Test settings
include(ExternalProject)

ExternalProject_Add(
  GoogleBenchmark
  GIT_REPOSITORY https://github.com/google/benchmark
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/lib
  INSTALL_COMMAND ""
  LOG_DOWNLOAD ON
  CMAKE_ARGS "-DCMAKE_BUILD_TYPE=release" "-DBENCHMARK_ENABLE_LTO=true" "-DCMAKE_CXX_FLAGS='-Wno-error=unused-function'"
)

ExternalProject_Get_Property(GoogleBenchmark source_dir)

include_directories(${source_dir}/include)

ExternalProject_Get_Property(GoogleBenchmark binary_dir)

add_library(benchmark STATIC IMPORTED)
set_property(
  TARGET benchmark
  PROPERTY IMPORTED_LOCATION ${binary_dir}/src/libbenchmark.a
)
