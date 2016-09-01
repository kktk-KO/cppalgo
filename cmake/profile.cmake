cmake_minimum_required(VERSION 2.7)

add_custom_target(profile)

function(add_profile profile_name source)
  add_executable(${profile_name}-profile EXCLUDE_FROM_ALL ${source})
  target_link_libraries(${profile_name}-profile benchmark pthread)

  add_custom_target(${profile_name}-profile-exec
    COMMAND $<TARGET_FILE:${profile_name}-profile> "--benchmark_out=${profile_name}-profile-raw.csv" "--benchmark_out_format=csv"
  )

  add_custom_target(${profile_name}-profile-extract
    COMMAND sh ${PROJECT_SOURCE_DIR}/tool/benchmark-format.sh "${CMAKE_CURRENT_BINARY_DIR}/${profile_name}"
  )

  add_dependencies(profile ${profile_name}-profile-extract)
  add_dependencies(${profile_name}-profile-extract ${profile_name}-profile-exec)
endfunction(add_profile)

add_subdirectory(profile)
