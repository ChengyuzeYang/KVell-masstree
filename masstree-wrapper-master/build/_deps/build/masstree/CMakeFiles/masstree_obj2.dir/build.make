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
include _deps/build/masstree/CMakeFiles/masstree_obj2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/build/masstree/CMakeFiles/masstree_obj2.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/build/masstree/CMakeFiles/masstree_obj2.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/build/masstree/CMakeFiles/masstree_obj2.dir/flags.make

_deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.o: _deps/build/masstree/CMakeFiles/masstree_obj2.dir/flags.make
_deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.o: _deps/src/masstree/clp.c
_deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.o: _deps/build/masstree/CMakeFiles/masstree_obj2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ycyz/masstree-wrapper-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.o"
	cd /home/ycyz/masstree-wrapper-master/build/_deps/build/masstree && /opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.o -MF CMakeFiles/masstree_obj2.dir/clp.c.o.d -o CMakeFiles/masstree_obj2.dir/clp.c.o -c /home/ycyz/masstree-wrapper-master/build/_deps/src/masstree/clp.c

_deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/masstree_obj2.dir/clp.c.i"
	cd /home/ycyz/masstree-wrapper-master/build/_deps/build/masstree && /opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ycyz/masstree-wrapper-master/build/_deps/src/masstree/clp.c > CMakeFiles/masstree_obj2.dir/clp.c.i

_deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/masstree_obj2.dir/clp.c.s"
	cd /home/ycyz/masstree-wrapper-master/build/_deps/build/masstree && /opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ycyz/masstree-wrapper-master/build/_deps/src/masstree/clp.c -o CMakeFiles/masstree_obj2.dir/clp.c.s

masstree_obj2: _deps/build/masstree/CMakeFiles/masstree_obj2.dir/clp.c.o
masstree_obj2: _deps/build/masstree/CMakeFiles/masstree_obj2.dir/build.make
.PHONY : masstree_obj2

# Rule to build all files generated by this target.
_deps/build/masstree/CMakeFiles/masstree_obj2.dir/build: masstree_obj2
.PHONY : _deps/build/masstree/CMakeFiles/masstree_obj2.dir/build

_deps/build/masstree/CMakeFiles/masstree_obj2.dir/clean:
	cd /home/ycyz/masstree-wrapper-master/build/_deps/build/masstree && $(CMAKE_COMMAND) -P CMakeFiles/masstree_obj2.dir/cmake_clean.cmake
.PHONY : _deps/build/masstree/CMakeFiles/masstree_obj2.dir/clean

_deps/build/masstree/CMakeFiles/masstree_obj2.dir/depend:
	cd /home/ycyz/masstree-wrapper-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ycyz/masstree-wrapper-master /home/ycyz/masstree-wrapper-master/build/_deps/src/masstree /home/ycyz/masstree-wrapper-master/build /home/ycyz/masstree-wrapper-master/build/_deps/build/masstree /home/ycyz/masstree-wrapper-master/build/_deps/build/masstree/CMakeFiles/masstree_obj2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/build/masstree/CMakeFiles/masstree_obj2.dir/depend

