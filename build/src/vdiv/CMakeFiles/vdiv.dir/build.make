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
include src/vdiv/CMakeFiles/vdiv.dir/depend.make

# Include the progress variables for this target.
include src/vdiv/CMakeFiles/vdiv.dir/progress.make

# Include the compile flags for this target's objects.
include src/vdiv/CMakeFiles/vdiv.dir/flags.make

src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o: src/vdiv/CMakeFiles/vdiv.dir/flags.make
src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o: ../src/vdiv/vdiv.c
	$(CMAKE_COMMAND) -E cmake_progress_report /project/malikabh/upm-c-staging/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o"
	cd /project/malikabh/upm-c-staging/build/src/vdiv && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/vdiv.dir/vdiv.c.o   -c /project/malikabh/upm-c-staging/src/vdiv/vdiv.c

src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vdiv.dir/vdiv.c.i"
	cd /project/malikabh/upm-c-staging/build/src/vdiv && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /project/malikabh/upm-c-staging/src/vdiv/vdiv.c > CMakeFiles/vdiv.dir/vdiv.c.i

src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vdiv.dir/vdiv.c.s"
	cd /project/malikabh/upm-c-staging/build/src/vdiv && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /project/malikabh/upm-c-staging/src/vdiv/vdiv.c -o CMakeFiles/vdiv.dir/vdiv.c.s

src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.requires:
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.requires

src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.provides: src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.requires
	$(MAKE) -f src/vdiv/CMakeFiles/vdiv.dir/build.make src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.provides.build
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.provides

src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.provides.build: src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o

src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o: src/vdiv/CMakeFiles/vdiv.dir/flags.make
src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o: ../src/vdiv/vdiv.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /project/malikabh/upm-c-staging/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o"
	cd /project/malikabh/upm-c-staging/build/src/vdiv && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/vdiv.dir/vdiv.cxx.o -c /project/malikabh/upm-c-staging/src/vdiv/vdiv.cxx

src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vdiv.dir/vdiv.cxx.i"
	cd /project/malikabh/upm-c-staging/build/src/vdiv && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /project/malikabh/upm-c-staging/src/vdiv/vdiv.cxx > CMakeFiles/vdiv.dir/vdiv.cxx.i

src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vdiv.dir/vdiv.cxx.s"
	cd /project/malikabh/upm-c-staging/build/src/vdiv && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /project/malikabh/upm-c-staging/src/vdiv/vdiv.cxx -o CMakeFiles/vdiv.dir/vdiv.cxx.s

src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.requires:
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.requires

src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.provides: src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.requires
	$(MAKE) -f src/vdiv/CMakeFiles/vdiv.dir/build.make src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.provides.build
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.provides

src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.provides.build: src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o

# Object files for target vdiv
vdiv_OBJECTS = \
"CMakeFiles/vdiv.dir/vdiv.c.o" \
"CMakeFiles/vdiv.dir/vdiv.cxx.o"

# External object files for target vdiv
vdiv_EXTERNAL_OBJECTS =

src/vdiv/libupm-vdiv.so.0.7.0: src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o
src/vdiv/libupm-vdiv.so.0.7.0: src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o
src/vdiv/libupm-vdiv.so.0.7.0: src/vdiv/CMakeFiles/vdiv.dir/build.make
src/vdiv/libupm-vdiv.so.0.7.0: src/vdiv/CMakeFiles/vdiv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libupm-vdiv.so"
	cd /project/malikabh/upm-c-staging/build/src/vdiv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vdiv.dir/link.txt --verbose=$(VERBOSE)
	cd /project/malikabh/upm-c-staging/build/src/vdiv && $(CMAKE_COMMAND) -E cmake_symlink_library libupm-vdiv.so.0.7.0 libupm-vdiv.so.0 libupm-vdiv.so

src/vdiv/libupm-vdiv.so.0: src/vdiv/libupm-vdiv.so.0.7.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/vdiv/libupm-vdiv.so.0

src/vdiv/libupm-vdiv.so: src/vdiv/libupm-vdiv.so.0.7.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/vdiv/libupm-vdiv.so

# Rule to build all files generated by this target.
src/vdiv/CMakeFiles/vdiv.dir/build: src/vdiv/libupm-vdiv.so
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/build

src/vdiv/CMakeFiles/vdiv.dir/requires: src/vdiv/CMakeFiles/vdiv.dir/vdiv.c.o.requires
src/vdiv/CMakeFiles/vdiv.dir/requires: src/vdiv/CMakeFiles/vdiv.dir/vdiv.cxx.o.requires
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/requires

src/vdiv/CMakeFiles/vdiv.dir/clean:
	cd /project/malikabh/upm-c-staging/build/src/vdiv && $(CMAKE_COMMAND) -P CMakeFiles/vdiv.dir/cmake_clean.cmake
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/clean

src/vdiv/CMakeFiles/vdiv.dir/depend:
	cd /project/malikabh/upm-c-staging/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /project/malikabh/upm-c-staging /project/malikabh/upm-c-staging/src/vdiv /project/malikabh/upm-c-staging/build /project/malikabh/upm-c-staging/build/src/vdiv /project/malikabh/upm-c-staging/build/src/vdiv/CMakeFiles/vdiv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/vdiv/CMakeFiles/vdiv.dir/depend

