cmake_minimum_required(VERSION 3.16)

find_package(GTest REQUIRED)
include(GoogleTest)

add_library(letscode_options INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*[cC]lang|GNU")
	target_compile_options(letscode_options INTERFACE -std=c++20 -fPIC)
else()
	target_compile_features(letscode_options INTERFACE cxx_std_20)
endif()

target_link_libraries(
	letscode_options
	INTERFACE
	project_warnings
	GTest::GTest
	GTest::Main
)

add_subdirectory(JSON_Serialization)
