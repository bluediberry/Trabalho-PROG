cmake_minimum_required(VERSION 3.9)
project(cwcreator)

set(CMAKE_CXX_STANDARD 11)

add_executable(cwcreator
        cmake-build-debug/B001.TXT
        cmake-build-debug/B002.TXT
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/cross_words
        cmake-build-debug/cross_words.cbp
        cmake-build-debug/Makefile
        board.cpp
        board.h
        CMakeLists.txt
        cwcreator.cpp
        dictionary.cpp
        dictionary.h
        synonyms_dictionary.txt)
