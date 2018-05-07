cmake_minimum_required(VERSION 3.9)
project(cross_words)

set(CMAKE_CXX_STANDARD 11)

add_executable(cross_words
        board.cpp
        board.h
        cwcreator.cpp
        dictionary.cpp
        dictionary.h)
