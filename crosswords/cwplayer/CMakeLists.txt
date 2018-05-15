cmake_minimum_required(VERSION 3.9)
project(cwplayer)

set(CMAKE_CXX_STANDARD 11)

add_executable(cwplayer
        board.cpp
        board.h
        CMakeLists.txt
        cwcreator.cpp
        dictionary.cpp
        dictionary.h
        player.cpp
        player.h
        synonyms_dictionary.txt)
