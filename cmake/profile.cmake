cmake_minimum_required(VERSION 2.7)

add_custom_target(profile)

function(add_profile profile_name source)
  add_executable(${profile_name}-profile EXCLUDE_FROM_ALL ${source})
  target_link_libraries(${profile_name}-profile gtest gtest_main pthread util)

  add_custom_target(${profile_name}-profile-exec COMMAND $<TARGET_FILE:${profile_name}-profile> "--gtest_output=xml:${profile_name}-profile.xml")

  add_dependencies(profile ${profile_name}-profile-exec)
  add_dependencies(${profile_name}-profile-exec ${profile_name}-profile)
endfunction(add_profile)

add_subdirectory(profile)
