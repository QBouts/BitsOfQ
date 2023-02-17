![linux build](https://github.com/QBouts/BitsOfQ/actions/workflows/build_linux.yml/badge.svg) 
![windows build](https://github.com/QBouts/BitsOfQ/actions/workflows/build_windows.yml/badge.svg)

# BitsOfQ
This repository contains tutorial code from the [BitsOfQ YouTube channel](https://bitsofq.com)


## Compilation

A CMake based configuration is available to compile and run all code. It is also used on GitHub's continuous integration pipeline (GitHub Actions) to compile against 3 compilers on two platforms.

The code has been verified to compile on:
* GCC-11 on Ubuntu
* Clang-12 on Ubuntu & clang-13 on Debian
* Visual Studio Enterprise 2019 (16.11.32106.194) on Windows Server 2019 (through github CI)

## Dependencies

The code related to most tutorials does not have any dependencies outside of the standard library.  In the LetsCode series google test is used for testing the implementation.

If using the supplied build configuration, a reasonably recent [CMake](https://cmake.org) version is required (Tested with CMake 3.18 and 3.22). When building on Windows, [vcpkg](https://vcpkg.io/en/index.html) is used for automatically retrieving dependencies.

## Running online

Several of the smaller tutorials can also be compiled and executed online using compiler explorer.

### Template Metaprogramming in C++
* E1 [Intro to template metaprogramming](https://godbolt.org/z/z4nYE5G8x)
* E2 [Writing metafunctions](https://godbolt.org/z/ddGWxKxjo)
* E3 [Variadic templates](https://godbolt.org/z/ddjGP7erb)
* E4 [Starting a metaprogramming library](https://godbolt.org/z/4YzhqYoMc)
* E5 [Improving our metaprogramming library](https://godbolt.org/z/fYcfofcKM)
* E6 [Composing metafunctions](https://godbolt.org/z/K5x58zz3M)
