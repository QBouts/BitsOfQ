cmake_minimum_required(VERSION 3.16)

project(bitsofq)

# Setup global CMake configuration
# include(cmake/StandardProjectSettings.cmake)

# Link this 'library' to warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# Link this 'library' to set the C++ standard / compile-time options requested
add_library(project_options INTERFACE)

# Setup compiler flags and compiler specific settings for supported compilers
include(cmake/CompilerSetup.cmake)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# include cmake macros
include(cmake/CMakeMacros.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Metaprogramming)
add_subdirectory(LetsCode)
