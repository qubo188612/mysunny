# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qubo/mysunny/src/modbus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qubo/mysunny/build/modbus

# Include any dependencies generated for this target.
include test/CMakeFiles/bandwidth-server.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/bandwidth-server.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/bandwidth-server.dir/flags.make

test/CMakeFiles/bandwidth-server.dir/bandwidth-server.c.o: test/CMakeFiles/bandwidth-server.dir/flags.make
test/CMakeFiles/bandwidth-server.dir/bandwidth-server.c.o: /home/qubo/mysunny/src/modbus/test/bandwidth-server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qubo/mysunny/build/modbus/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/bandwidth-server.dir/bandwidth-server.c.o"
	cd /home/qubo/mysunny/build/modbus/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bandwidth-server.dir/bandwidth-server.c.o   -c /home/qubo/mysunny/src/modbus/test/bandwidth-server.c

test/CMakeFiles/bandwidth-server.dir/bandwidth-server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bandwidth-server.dir/bandwidth-server.c.i"
	cd /home/qubo/mysunny/build/modbus/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qubo/mysunny/src/modbus/test/bandwidth-server.c > CMakeFiles/bandwidth-server.dir/bandwidth-server.c.i

test/CMakeFiles/bandwidth-server.dir/bandwidth-server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bandwidth-server.dir/bandwidth-server.c.s"
	cd /home/qubo/mysunny/build/modbus/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qubo/mysunny/src/modbus/test/bandwidth-server.c -o CMakeFiles/bandwidth-server.dir/bandwidth-server.c.s

# Object files for target bandwidth-server
bandwidth__server_OBJECTS = \
"CMakeFiles/bandwidth-server.dir/bandwidth-server.c.o"

# External object files for target bandwidth-server
bandwidth__server_EXTERNAL_OBJECTS =

test/bandwidth-server: test/CMakeFiles/bandwidth-server.dir/bandwidth-server.c.o
test/bandwidth-server: test/CMakeFiles/bandwidth-server.dir/build.make
test/bandwidth-server: /home/qubo/modbus/libmodbus/install/lib/libmodbus.so
test/bandwidth-server: /usr/lib/x86_64-linux-gnu/libxml2.so
test/bandwidth-server: test/CMakeFiles/bandwidth-server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qubo/mysunny/build/modbus/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bandwidth-server"
	cd /home/qubo/mysunny/build/modbus/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bandwidth-server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/bandwidth-server.dir/build: test/bandwidth-server

.PHONY : test/CMakeFiles/bandwidth-server.dir/build

test/CMakeFiles/bandwidth-server.dir/clean:
	cd /home/qubo/mysunny/build/modbus/test && $(CMAKE_COMMAND) -P CMakeFiles/bandwidth-server.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/bandwidth-server.dir/clean

test/CMakeFiles/bandwidth-server.dir/depend:
	cd /home/qubo/mysunny/build/modbus && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qubo/mysunny/src/modbus /home/qubo/mysunny/src/modbus/test /home/qubo/mysunny/build/modbus /home/qubo/mysunny/build/modbus/test /home/qubo/mysunny/build/modbus/test/CMakeFiles/bandwidth-server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/bandwidth-server.dir/depend

