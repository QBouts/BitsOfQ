cmake_minimum_required(VERSION 3.16)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(letscode_options INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*[cC]lang|GNU")
	target_compile_options(letscode_options INTERFACE -std=c++20)
elseif(MSVC)
	target_compile_features(letscode_options INTERFACE cxx_std_20)
else()
	message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

add_subdirectory(JSON_Serialization)
