# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ycyz/masstree-wrapper-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ycyz/masstree-wrapper-master/build

# Include any dependencies generated for this target.
include CMakeFiles/masstree-wrapper.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/masstree-wrapper.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/masstree-wrapper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/masstree-wrapper.dir/flags.make

CMakeFiles/masstree-wrapper.dir/src/main.cpp.o: CMakeFiles/masstree-wrapper.dir/flags.make
CMakeFiles/masstree-wrapper.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/masstree-wrapper.dir/src/main.cpp.o: CMakeFiles/masstree-wrapper.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ycyz/masstree-wrapper-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/masstree-wrapper.dir/src/main.cpp.o"
	/opt/rh/devtoolset-9/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/masstree-wrapper.dir/src/main.cpp.o -MF CMakeFiles/masstree-wrapper.dir/src/main.cpp.o.d -o CMakeFiles/masstree-wrapper.dir/src/main.cpp.o -c /home/ycyz/masstree-wrapper-master/src/main.cpp

CMakeFiles/masstree-wrapper.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/masstree-wrapper.dir/src/main.cpp.i"
	/opt/rh/devtoolset-9/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ycyz/masstree-wrapper-master/src/main.cpp > CMakeFiles/masstree-wrapper.dir/src/main.cpp.i

CMakeFiles/masstree-wrapper.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/masstree-wrapper.dir/src/main.cpp.s"
	/opt/rh/devtoolset-9/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ycyz/masstree-wrapper-master/src/main.cpp -o CMakeFiles/masstree-wrapper.dir/src/main.cpp.s

# Object files for target masstree-wrapper
masstree__wrapper_OBJECTS = \
"CMakeFiles/masstree-wrapper.dir/src/main.cpp.o"

# External object files for target masstree-wrapper
masstree__wrapper_EXTERNAL_OBJECTS =

libmasstree-wrapper.so: CMakeFiles/masstree-wrapper.dir/src/main.cpp.o
libmasstree-wrapper.so: CMakeFiles/masstree-wrapper.dir/build.make
libmasstree-wrapper.so: CMakeFiles/masstree-wrapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ycyz/masstree-wrapper-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmasstree-wrapper.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/masstree-wrapper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/masstree-wrapper.dir/build: libmasstree-wrapper.so
.PHONY : CMakeFiles/masstree-wrapper.dir/build

CMakeFiles/masstree-wrapper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/masstree-wrapper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/masstree-wrapper.dir/clean

CMakeFiles/masstree-wrapper.dir/depend:
	cd /home/ycyz/masstree-wrapper-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ycyz/masstree-wrapper-master /home/ycyz/masstree-wrapper-master /home/ycyz/masstree-wrapper-master/build /home/ycyz/masstree-wrapper-master/build /home/ycyz/masstree-wrapper-master/build/CMakeFiles/masstree-wrapper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/masstree-wrapper.dir/depend

