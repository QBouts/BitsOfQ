enable_testing()

add_executable(
  LetsCode_JSONSerialization_E2_Test
  main.cpp
)
target_link_libraries(
  LetsCode_JSONSerialization_E2_Test
  letscode_options
)

include(GoogleTest)
gtest_discover_tests(LetsCode_JSONSerialization_E2_Test)
