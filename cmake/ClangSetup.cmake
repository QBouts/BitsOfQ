cmake_minimum_required(VERSION 3.16)
include(${CMAKE_CURRENT_LIST_DIR}/ClangGccShared.cmake)
target_compile_options(project_options INTERFACE -stdlib=libc++ -fbracket-depth=512)
target_link_options(project_options INTERFACE -stdlib=libc++ -lm -fuse-ld=lld -lc++)
target_compile_definitions(project_options INTERFACE -DBOQ_USE_LIBCPP)
target_compile_options(project_options INTERFACE -fcolor-diagnostics)

set(CONAN_EXTRA_SETTINGS SETTINGS compiler.libcxx=libc++)