# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /Users/siddiqui/Documents/Projects/cpp-concepts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siddiqui/Documents/Projects/cpp-concepts/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/learning_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learning_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learning_cpp.dir/flags.make

CMakeFiles/learning_cpp.dir/main.cpp.o: CMakeFiles/learning_cpp.dir/flags.make
CMakeFiles/learning_cpp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siddiqui/Documents/Projects/cpp-concepts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learning_cpp.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/learning_cpp.dir/main.cpp.o -c /Users/siddiqui/Documents/Projects/cpp-concepts/main.cpp

CMakeFiles/learning_cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learning_cpp.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siddiqui/Documents/Projects/cpp-concepts/main.cpp > CMakeFiles/learning_cpp.dir/main.cpp.i

CMakeFiles/learning_cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learning_cpp.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siddiqui/Documents/Projects/cpp-concepts/main.cpp -o CMakeFiles/learning_cpp.dir/main.cpp.s

CMakeFiles/learning_cpp.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/learning_cpp.dir/main.cpp.o.requires

CMakeFiles/learning_cpp.dir/main.cpp.o.provides: CMakeFiles/learning_cpp.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/learning_cpp.dir/build.make CMakeFiles/learning_cpp.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/learning_cpp.dir/main.cpp.o.provides

CMakeFiles/learning_cpp.dir/main.cpp.o.provides.build: CMakeFiles/learning_cpp.dir/main.cpp.o


# Object files for target learning_cpp
learning_cpp_OBJECTS = \
"CMakeFiles/learning_cpp.dir/main.cpp.o"

# External object files for target learning_cpp
learning_cpp_EXTERNAL_OBJECTS =

learning_cpp: CMakeFiles/learning_cpp.dir/main.cpp.o
learning_cpp: CMakeFiles/learning_cpp.dir/build.make
learning_cpp: CMakeFiles/learning_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/siddiqui/Documents/Projects/cpp-concepts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable learning_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learning_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learning_cpp.dir/build: learning_cpp

.PHONY : CMakeFiles/learning_cpp.dir/build

CMakeFiles/learning_cpp.dir/requires: CMakeFiles/learning_cpp.dir/main.cpp.o.requires

.PHONY : CMakeFiles/learning_cpp.dir/requires

CMakeFiles/learning_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learning_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learning_cpp.dir/clean

CMakeFiles/learning_cpp.dir/depend:
	cd /Users/siddiqui/Documents/Projects/cpp-concepts/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siddiqui/Documents/Projects/cpp-concepts /Users/siddiqui/Documents/Projects/cpp-concepts /Users/siddiqui/Documents/Projects/cpp-concepts/cmake-build-debug /Users/siddiqui/Documents/Projects/cpp-concepts/cmake-build-debug /Users/siddiqui/Documents/Projects/cpp-concepts/cmake-build-debug/CMakeFiles/learning_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learning_cpp.dir/depend

