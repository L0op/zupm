# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /project/malikabh/upm-c-staging

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /project/malikabh/upm-c-staging/build

# Include any dependencies generated for this target.
include src/loudness/CMakeFiles/loudness.dir/depend.make

# Include the progress variables for this target.
include src/loudness/CMakeFiles/loudness.dir/progress.make

# Include the compile flags for this target's objects.
include src/loudness/CMakeFiles/loudness.dir/flags.make

src/loudness/CMakeFiles/loudness.dir/loudness.c.o: src/loudness/CMakeFiles/loudness.dir/flags.make
src/loudness/CMakeFiles/loudness.dir/loudness.c.o: ../src/loudness/loudness.c
	$(CMAKE_COMMAND) -E cmake_progress_report /project/malikabh/upm-c-staging/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/loudness/CMakeFiles/loudness.dir/loudness.c.o"
	cd /project/malikabh/upm-c-staging/build/src/loudness && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/loudness.dir/loudness.c.o   -c /project/malikabh/upm-c-staging/src/loudness/loudness.c

src/loudness/CMakeFiles/loudness.dir/loudness.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/loudness.dir/loudness.c.i"
	cd /project/malikabh/upm-c-staging/build/src/loudness && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /project/malikabh/upm-c-staging/src/loudness/loudness.c > CMakeFiles/loudness.dir/loudness.c.i

src/loudness/CMakeFiles/loudness.dir/loudness.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/loudness.dir/loudness.c.s"
	cd /project/malikabh/upm-c-staging/build/src/loudness && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /project/malikabh/upm-c-staging/src/loudness/loudness.c -o CMakeFiles/loudness.dir/loudness.c.s

src/loudness/CMakeFiles/loudness.dir/loudness.c.o.requires:
.PHONY : src/loudness/CMakeFiles/loudness.dir/loudness.c.o.requires

src/loudness/CMakeFiles/loudness.dir/loudness.c.o.provides: src/loudness/CMakeFiles/loudness.dir/loudness.c.o.requires
	$(MAKE) -f src/loudness/CMakeFiles/loudness.dir/build.make src/loudness/CMakeFiles/loudness.dir/loudness.c.o.provides.build
.PHONY : src/loudness/CMakeFiles/loudness.dir/loudness.c.o.provides

src/loudness/CMakeFiles/loudness.dir/loudness.c.o.provides.build: src/loudness/CMakeFiles/loudness.dir/loudness.c.o

# Object files for target loudness
loudness_OBJECTS = \
"CMakeFiles/loudness.dir/loudness.c.o"

# External object files for target loudness
loudness_EXTERNAL_OBJECTS =

src/loudness/libupm-loudness.so.0.7.0: src/loudness/CMakeFiles/loudness.dir/loudness.c.o
src/loudness/libupm-loudness.so.0.7.0: src/loudness/CMakeFiles/loudness.dir/build.make
src/loudness/libupm-loudness.so.0.7.0: src/loudness/CMakeFiles/loudness.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library libupm-loudness.so"
	cd /project/malikabh/upm-c-staging/build/src/loudness && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/loudness.dir/link.txt --verbose=$(VERBOSE)
	cd /project/malikabh/upm-c-staging/build/src/loudness && $(CMAKE_COMMAND) -E cmake_symlink_library libupm-loudness.so.0.7.0 libupm-loudness.so.0 libupm-loudness.so

src/loudness/libupm-loudness.so.0: src/loudness/libupm-loudness.so.0.7.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/loudness/libupm-loudness.so.0

src/loudness/libupm-loudness.so: src/loudness/libupm-loudness.so.0.7.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/loudness/libupm-loudness.so

# Rule to build all files generated by this target.
src/loudness/CMakeFiles/loudness.dir/build: src/loudness/libupm-loudness.so
.PHONY : src/loudness/CMakeFiles/loudness.dir/build

src/loudness/CMakeFiles/loudness.dir/requires: src/loudness/CMakeFiles/loudness.dir/loudness.c.o.requires
.PHONY : src/loudness/CMakeFiles/loudness.dir/requires

src/loudness/CMakeFiles/loudness.dir/clean:
	cd /project/malikabh/upm-c-staging/build/src/loudness && $(CMAKE_COMMAND) -P CMakeFiles/loudness.dir/cmake_clean.cmake
.PHONY : src/loudness/CMakeFiles/loudness.dir/clean

src/loudness/CMakeFiles/loudness.dir/depend:
	cd /project/malikabh/upm-c-staging/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/malikabh/upm-c-staging /project/malikabh/upm-c-staging/src/loudness /project/malikabh/upm-c-staging/build /project/malikabh/upm-c-staging/build/src/loudness /project/malikabh/upm-c-staging/build/src/loudness/CMakeFiles/loudness.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/loudness/CMakeFiles/loudness.dir/depend

