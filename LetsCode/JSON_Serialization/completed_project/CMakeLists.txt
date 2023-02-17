enable_testing()

add_executable(
  LetsCode_JSONSerialization_Completed_Test 
  main.cpp
)
target_link_libraries(
  LetsCode_JSONSerialization_Completed_Test 
  project_warnings
  pthread
  gtest
  gtest_main
)

target_compile_options(LetsCode_JSONSerialization_Completed_Test PUBLIC -std=c++2a)

include(GoogleTest)
gtest_discover_tests(LetsCode_JSONSerialization_Completed_Test)
