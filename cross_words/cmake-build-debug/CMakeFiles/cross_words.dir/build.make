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
CMAKE_SOURCE_DIR = /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cross_words.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cross_words.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cross_words.dir/flags.make

CMakeFiles/cross_words.dir/board.cpp.o: CMakeFiles/cross_words.dir/flags.make
CMakeFiles/cross_words.dir/board.cpp.o: ../board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cross_words.dir/board.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cross_words.dir/board.cpp.o -c /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/board.cpp

CMakeFiles/cross_words.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cross_words.dir/board.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/board.cpp > CMakeFiles/cross_words.dir/board.cpp.i

CMakeFiles/cross_words.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cross_words.dir/board.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/board.cpp -o CMakeFiles/cross_words.dir/board.cpp.s

CMakeFiles/cross_words.dir/board.cpp.o.requires:

.PHONY : CMakeFiles/cross_words.dir/board.cpp.o.requires

CMakeFiles/cross_words.dir/board.cpp.o.provides: CMakeFiles/cross_words.dir/board.cpp.o.requires
	$(MAKE) -f CMakeFiles/cross_words.dir/build.make CMakeFiles/cross_words.dir/board.cpp.o.provides.build
.PHONY : CMakeFiles/cross_words.dir/board.cpp.o.provides

CMakeFiles/cross_words.dir/board.cpp.o.provides.build: CMakeFiles/cross_words.dir/board.cpp.o


CMakeFiles/cross_words.dir/cwcreator.cpp.o: CMakeFiles/cross_words.dir/flags.make
CMakeFiles/cross_words.dir/cwcreator.cpp.o: ../cwcreator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cross_words.dir/cwcreator.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cross_words.dir/cwcreator.cpp.o -c /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cwcreator.cpp

CMakeFiles/cross_words.dir/cwcreator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cross_words.dir/cwcreator.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cwcreator.cpp > CMakeFiles/cross_words.dir/cwcreator.cpp.i

CMakeFiles/cross_words.dir/cwcreator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cross_words.dir/cwcreator.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cwcreator.cpp -o CMakeFiles/cross_words.dir/cwcreator.cpp.s

CMakeFiles/cross_words.dir/cwcreator.cpp.o.requires:

.PHONY : CMakeFiles/cross_words.dir/cwcreator.cpp.o.requires

CMakeFiles/cross_words.dir/cwcreator.cpp.o.provides: CMakeFiles/cross_words.dir/cwcreator.cpp.o.requires
	$(MAKE) -f CMakeFiles/cross_words.dir/build.make CMakeFiles/cross_words.dir/cwcreator.cpp.o.provides.build
.PHONY : CMakeFiles/cross_words.dir/cwcreator.cpp.o.provides

CMakeFiles/cross_words.dir/cwcreator.cpp.o.provides.build: CMakeFiles/cross_words.dir/cwcreator.cpp.o


CMakeFiles/cross_words.dir/dictionary.cpp.o: CMakeFiles/cross_words.dir/flags.make
CMakeFiles/cross_words.dir/dictionary.cpp.o: ../dictionary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cross_words.dir/dictionary.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cross_words.dir/dictionary.cpp.o -c /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/dictionary.cpp

CMakeFiles/cross_words.dir/dictionary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cross_words.dir/dictionary.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/dictionary.cpp > CMakeFiles/cross_words.dir/dictionary.cpp.i

CMakeFiles/cross_words.dir/dictionary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cross_words.dir/dictionary.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/dictionary.cpp -o CMakeFiles/cross_words.dir/dictionary.cpp.s

CMakeFiles/cross_words.dir/dictionary.cpp.o.requires:

.PHONY : CMakeFiles/cross_words.dir/dictionary.cpp.o.requires

CMakeFiles/cross_words.dir/dictionary.cpp.o.provides: CMakeFiles/cross_words.dir/dictionary.cpp.o.requires
	$(MAKE) -f CMakeFiles/cross_words.dir/build.make CMakeFiles/cross_words.dir/dictionary.cpp.o.provides.build
.PHONY : CMakeFiles/cross_words.dir/dictionary.cpp.o.provides

CMakeFiles/cross_words.dir/dictionary.cpp.o.provides.build: CMakeFiles/cross_words.dir/dictionary.cpp.o


# Object files for target cross_words
cross_words_OBJECTS = \
"CMakeFiles/cross_words.dir/board.cpp.o" \
"CMakeFiles/cross_words.dir/cwcreator.cpp.o" \
"CMakeFiles/cross_words.dir/dictionary.cpp.o"

# External object files for target cross_words
cross_words_EXTERNAL_OBJECTS =

cross_words: CMakeFiles/cross_words.dir/board.cpp.o
cross_words: CMakeFiles/cross_words.dir/cwcreator.cpp.o
cross_words: CMakeFiles/cross_words.dir/dictionary.cpp.o
cross_words: CMakeFiles/cross_words.dir/build.make
cross_words: CMakeFiles/cross_words.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable cross_words"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cross_words.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cross_words.dir/build: cross_words

.PHONY : CMakeFiles/cross_words.dir/build

CMakeFiles/cross_words.dir/requires: CMakeFiles/cross_words.dir/board.cpp.o.requires
CMakeFiles/cross_words.dir/requires: CMakeFiles/cross_words.dir/cwcreator.cpp.o.requires
CMakeFiles/cross_words.dir/requires: CMakeFiles/cross_words.dir/dictionary.cpp.o.requires

.PHONY : CMakeFiles/cross_words.dir/requires

CMakeFiles/cross_words.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cross_words.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cross_words.dir/clean

CMakeFiles/cross_words.dir/depend:
	cd /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug /Users/Mariana/Documents/GitHub/Trabalho-PROG/cross_words/cmake-build-debug/CMakeFiles/cross_words.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cross_words.dir/depend
