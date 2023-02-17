cmake_minimum_required(VERSION 3.16)
enable_testing()

add_executable(
  LetsCode_JSONSerialization_Completed_Test
  main.cpp
)
target_link_libraries(
  LetsCode_JSONSerialization_Completed_Test
  letscode_options
  project_warnings
  gtest
  gtest_main
  pthread
)

include(GoogleTest)
gtest_discover_tests(LetsCode_JSONSerialization_Completed_Test)
