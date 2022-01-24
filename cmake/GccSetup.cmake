cmake_minimum_required(VERSION 3.16)
include(${CMAKE_CURRENT_LIST_DIR}/ClangGccShared.cmake)
# Output diagnostic colors
target_compile_options(project_options INTERFACE -fdiagnostics-color=always)
