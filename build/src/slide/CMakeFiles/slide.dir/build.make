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
include src/slide/CMakeFiles/slide.dir/depend.make

# Include the progress variables for this target.
include src/slide/CMakeFiles/slide.dir/progress.make

# Include the compile flags for this target's objects.
include src/slide/CMakeFiles/slide.dir/flags.make

src/slide/CMakeFiles/slide.dir/slide.cxx.o: src/slide/CMakeFiles/slide.dir/flags.make
src/slide/CMakeFiles/slide.dir/slide.cxx.o: ../src/slide/slide.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /project/malikabh/upm-c-staging/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/slide/CMakeFiles/slide.dir/slide.cxx.o"
	cd /project/malikabh/upm-c-staging/build/src/slide && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/slide.dir/slide.cxx.o -c /project/malikabh/upm-c-staging/src/slide/slide.cxx

src/slide/CMakeFiles/slide.dir/slide.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/slide.dir/slide.cxx.i"
	cd /project/malikabh/upm-c-staging/build/src/slide && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/malikabh/upm-c-staging/src/slide/slide.cxx > CMakeFiles/slide.dir/slide.cxx.i

src/slide/CMakeFiles/slide.dir/slide.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/slide.dir/slide.cxx.s"
	cd /project/malikabh/upm-c-staging/build/src/slide && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/malikabh/upm-c-staging/src/slide/slide.cxx -o CMakeFiles/slide.dir/slide.cxx.s

src/slide/CMakeFiles/slide.dir/slide.cxx.o.requires:
.PHONY : src/slide/CMakeFiles/slide.dir/slide.cxx.o.requires

src/slide/CMakeFiles/slide.dir/slide.cxx.o.provides: src/slide/CMakeFiles/slide.dir/slide.cxx.o.requires
	$(MAKE) -f src/slide/CMakeFiles/slide.dir/build.make src/slide/CMakeFiles/slide.dir/slide.cxx.o.provides.build
.PHONY : src/slide/CMakeFiles/slide.dir/slide.cxx.o.provides

src/slide/CMakeFiles/slide.dir/slide.cxx.o.provides.build: src/slide/CMakeFiles/slide.dir/slide.cxx.o

src/slide/CMakeFiles/slide.dir/slide.c.o: src/slide/CMakeFiles/slide.dir/flags.make
src/slide/CMakeFiles/slide.dir/slide.c.o: ../src/slide/slide.c
	$(CMAKE_COMMAND) -E cmake_progress_report /project/malikabh/upm-c-staging/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/slide/CMakeFiles/slide.dir/slide.c.o"
	cd /project/malikabh/upm-c-staging/build/src/slide && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/slide.dir/slide.c.o   -c /project/malikabh/upm-c-staging/src/slide/slide.c

src/slide/CMakeFiles/slide.dir/slide.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/slide.dir/slide.c.i"
	cd /project/malikabh/upm-c-staging/build/src/slide && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /project/malikabh/upm-c-staging/src/slide/slide.c > CMakeFiles/slide.dir/slide.c.i

src/slide/CMakeFiles/slide.dir/slide.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/slide.dir/slide.c.s"
	cd /project/malikabh/upm-c-staging/build/src/slide && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /project/malikabh/upm-c-staging/src/slide/slide.c -o CMakeFiles/slide.dir/slide.c.s

src/slide/CMakeFiles/slide.dir/slide.c.o.requires:
.PHONY : src/slide/CMakeFiles/slide.dir/slide.c.o.requires

src/slide/CMakeFiles/slide.dir/slide.c.o.provides: src/slide/CMakeFiles/slide.dir/slide.c.o.requires
	$(MAKE) -f src/slide/CMakeFiles/slide.dir/build.make src/slide/CMakeFiles/slide.dir/slide.c.o.provides.build
.PHONY : src/slide/CMakeFiles/slide.dir/slide.c.o.provides

src/slide/CMakeFiles/slide.dir/slide.c.o.provides.build: src/slide/CMakeFiles/slide.dir/slide.c.o

# Object files for target slide
slide_OBJECTS = \
"CMakeFiles/slide.dir/slide.cxx.o" \
"CMakeFiles/slide.dir/slide.c.o"

# External object files for target slide
slide_EXTERNAL_OBJECTS =

src/slide/libupm-slide.so.0.7.0: src/slide/CMakeFiles/slide.dir/slide.cxx.o
src/slide/libupm-slide.so.0.7.0: src/slide/CMakeFiles/slide.dir/slide.c.o
src/slide/libupm-slide.so.0.7.0: src/slide/CMakeFiles/slide.dir/build.make
src/slide/libupm-slide.so.0.7.0: src/slide/CMakeFiles/slide.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libupm-slide.so"
	cd /project/malikabh/upm-c-staging/build/src/slide && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/slide.dir/link.txt --verbose=$(VERBOSE)
	cd /project/malikabh/upm-c-staging/build/src/slide && $(CMAKE_COMMAND) -E cmake_symlink_library libupm-slide.so.0.7.0 libupm-slide.so.0 libupm-slide.so

src/slide/libupm-slide.so.0: src/slide/libupm-slide.so.0.7.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/slide/libupm-slide.so.0

src/slide/libupm-slide.so: src/slide/libupm-slide.so.0.7.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/slide/libupm-slide.so

# Rule to build all files generated by this target.
src/slide/CMakeFiles/slide.dir/build: src/slide/libupm-slide.so
.PHONY : src/slide/CMakeFiles/slide.dir/build

src/slide/CMakeFiles/slide.dir/requires: src/slide/CMakeFiles/slide.dir/slide.cxx.o.requires
src/slide/CMakeFiles/slide.dir/requires: src/slide/CMakeFiles/slide.dir/slide.c.o.requires
.PHONY : src/slide/CMakeFiles/slide.dir/requires

src/slide/CMakeFiles/slide.dir/clean:
	cd /project/malikabh/upm-c-staging/build/src/slide && $(CMAKE_COMMAND) -P CMakeFiles/slide.dir/cmake_clean.cmake
.PHONY : src/slide/CMakeFiles/slide.dir/clean

src/slide/CMakeFiles/slide.dir/depend:
	cd /project/malikabh/upm-c-staging/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/malikabh/upm-c-staging /project/malikabh/upm-c-staging/src/slide /project/malikabh/upm-c-staging/build /project/malikabh/upm-c-staging/build/src/slide /project/malikabh/upm-c-staging/build/src/slide/CMakeFiles/slide.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/slide/CMakeFiles/slide.dir/depend

