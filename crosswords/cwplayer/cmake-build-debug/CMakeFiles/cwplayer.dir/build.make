# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cwplayer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cwplayer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cwplayer.dir/flags.make

CMakeFiles/cwplayer.dir/board.cpp.o: CMakeFiles/cwplayer.dir/flags.make
CMakeFiles/cwplayer.dir/board.cpp.o: ../board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cwplayer.dir/board.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cwplayer.dir/board.cpp.o -c /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/board.cpp

CMakeFiles/cwplayer.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cwplayer.dir/board.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/board.cpp > CMakeFiles/cwplayer.dir/board.cpp.i

CMakeFiles/cwplayer.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cwplayer.dir/board.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/board.cpp -o CMakeFiles/cwplayer.dir/board.cpp.s

CMakeFiles/cwplayer.dir/board.cpp.o.requires:

.PHONY : CMakeFiles/cwplayer.dir/board.cpp.o.requires

CMakeFiles/cwplayer.dir/board.cpp.o.provides: CMakeFiles/cwplayer.dir/board.cpp.o.requires
	$(MAKE) -f CMakeFiles/cwplayer.dir/build.make CMakeFiles/cwplayer.dir/board.cpp.o.provides.build
.PHONY : CMakeFiles/cwplayer.dir/board.cpp.o.provides

CMakeFiles/cwplayer.dir/board.cpp.o.provides.build: CMakeFiles/cwplayer.dir/board.cpp.o


CMakeFiles/cwplayer.dir/cwcreator.cpp.o: CMakeFiles/cwplayer.dir/flags.make
CMakeFiles/cwplayer.dir/cwcreator.cpp.o: ../cwcreator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cwplayer.dir/cwcreator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cwplayer.dir/cwcreator.cpp.o -c /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cwcreator.cpp

CMakeFiles/cwplayer.dir/cwcreator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cwplayer.dir/cwcreator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cwcreator.cpp > CMakeFiles/cwplayer.dir/cwcreator.cpp.i

CMakeFiles/cwplayer.dir/cwcreator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cwplayer.dir/cwcreator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cwcreator.cpp -o CMakeFiles/cwplayer.dir/cwcreator.cpp.s

CMakeFiles/cwplayer.dir/cwcreator.cpp.o.requires:

.PHONY : CMakeFiles/cwplayer.dir/cwcreator.cpp.o.requires

CMakeFiles/cwplayer.dir/cwcreator.cpp.o.provides: CMakeFiles/cwplayer.dir/cwcreator.cpp.o.requires
	$(MAKE) -f CMakeFiles/cwplayer.dir/build.make CMakeFiles/cwplayer.dir/cwcreator.cpp.o.provides.build
.PHONY : CMakeFiles/cwplayer.dir/cwcreator.cpp.o.provides

CMakeFiles/cwplayer.dir/cwcreator.cpp.o.provides.build: CMakeFiles/cwplayer.dir/cwcreator.cpp.o


CMakeFiles/cwplayer.dir/dictionary.cpp.o: CMakeFiles/cwplayer.dir/flags.make
CMakeFiles/cwplayer.dir/dictionary.cpp.o: ../dictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cwplayer.dir/dictionary.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cwplayer.dir/dictionary.cpp.o -c /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/dictionary.cpp

CMakeFiles/cwplayer.dir/dictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cwplayer.dir/dictionary.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/dictionary.cpp > CMakeFiles/cwplayer.dir/dictionary.cpp.i

CMakeFiles/cwplayer.dir/dictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cwplayer.dir/dictionary.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/dictionary.cpp -o CMakeFiles/cwplayer.dir/dictionary.cpp.s

CMakeFiles/cwplayer.dir/dictionary.cpp.o.requires:

.PHONY : CMakeFiles/cwplayer.dir/dictionary.cpp.o.requires

CMakeFiles/cwplayer.dir/dictionary.cpp.o.provides: CMakeFiles/cwplayer.dir/dictionary.cpp.o.requires
	$(MAKE) -f CMakeFiles/cwplayer.dir/build.make CMakeFiles/cwplayer.dir/dictionary.cpp.o.provides.build
.PHONY : CMakeFiles/cwplayer.dir/dictionary.cpp.o.provides

CMakeFiles/cwplayer.dir/dictionary.cpp.o.provides.build: CMakeFiles/cwplayer.dir/dictionary.cpp.o


CMakeFiles/cwplayer.dir/player.cpp.o: CMakeFiles/cwplayer.dir/flags.make
CMakeFiles/cwplayer.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cwplayer.dir/player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cwplayer.dir/player.cpp.o -c /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/player.cpp

CMakeFiles/cwplayer.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cwplayer.dir/player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/player.cpp > CMakeFiles/cwplayer.dir/player.cpp.i

CMakeFiles/cwplayer.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cwplayer.dir/player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/player.cpp -o CMakeFiles/cwplayer.dir/player.cpp.s

CMakeFiles/cwplayer.dir/player.cpp.o.requires:

.PHONY : CMakeFiles/cwplayer.dir/player.cpp.o.requires

CMakeFiles/cwplayer.dir/player.cpp.o.provides: CMakeFiles/cwplayer.dir/player.cpp.o.requires
	$(MAKE) -f CMakeFiles/cwplayer.dir/build.make CMakeFiles/cwplayer.dir/player.cpp.o.provides.build
.PHONY : CMakeFiles/cwplayer.dir/player.cpp.o.provides

CMakeFiles/cwplayer.dir/player.cpp.o.provides.build: CMakeFiles/cwplayer.dir/player.cpp.o


# Object files for target cwplayer
cwplayer_OBJECTS = \
"CMakeFiles/cwplayer.dir/board.cpp.o" \
"CMakeFiles/cwplayer.dir/cwcreator.cpp.o" \
"CMakeFiles/cwplayer.dir/dictionary.cpp.o" \
"CMakeFiles/cwplayer.dir/player.cpp.o"

# External object files for target cwplayer
cwplayer_EXTERNAL_OBJECTS =

cwplayer: CMakeFiles/cwplayer.dir/board.cpp.o
cwplayer: CMakeFiles/cwplayer.dir/cwcreator.cpp.o
cwplayer: CMakeFiles/cwplayer.dir/dictionary.cpp.o
cwplayer: CMakeFiles/cwplayer.dir/player.cpp.o
cwplayer: CMakeFiles/cwplayer.dir/build.make
cwplayer: CMakeFiles/cwplayer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable cwplayer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cwplayer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cwplayer.dir/build: cwplayer

.PHONY : CMakeFiles/cwplayer.dir/build

CMakeFiles/cwplayer.dir/requires: CMakeFiles/cwplayer.dir/board.cpp.o.requires
CMakeFiles/cwplayer.dir/requires: CMakeFiles/cwplayer.dir/cwcreator.cpp.o.requires
CMakeFiles/cwplayer.dir/requires: CMakeFiles/cwplayer.dir/dictionary.cpp.o.requires
CMakeFiles/cwplayer.dir/requires: CMakeFiles/cwplayer.dir/player.cpp.o.requires

.PHONY : CMakeFiles/cwplayer.dir/requires

CMakeFiles/cwplayer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cwplayer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cwplayer.dir/clean

CMakeFiles/cwplayer.dir/depend:
	cd /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug /Users/Mariana/Documents/GitHub/Trabalho-PROG/crosswords/cwplayer/cmake-build-debug/CMakeFiles/cwplayer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cwplayer.dir/depend
