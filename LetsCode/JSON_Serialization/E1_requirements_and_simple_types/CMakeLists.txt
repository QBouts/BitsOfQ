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

if(CMAKE_CXX_COMPILER_ID MATCHES ".*[cC]lang|GNU")
  target_compile_options(LetsCode_JSONSerialization_E1_Test PUBLIC -std=c++20)
elseif(MSVC)
  target_compile_features(LetsCode_JSONSerialization_E1_Test PUBLIC cxx_std_20)
else()
  message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

include(GoogleTest)
gtest_discover_tests(LetsCode_JSONSerialization_E1_Test)
