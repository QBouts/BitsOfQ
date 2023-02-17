enable_testing()

add_executable(
  LetsCode_JSONSerialization_E1_Test 
  main.cpp
)
target_link_libraries(
  LetsCode_JSONSerialization_E1_Test 
  project_warnings
  gtest
  gtest_main
  pthread
)

target_compile_options(LetsCode_JSONSerialization_E1_Test PUBLIC -std=c++2a)

include(GoogleTest)
gtest_discover_tests(LetsCode_JSONSerialization_E1_Test)
