# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tazukiswift/Programming/C-Project-Euler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tazukiswift/Programming/C-Project-Euler/build

# Include any dependencies generated for this target.
include CMakeFiles/ProjectE.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProjectE.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjectE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjectE.dir/flags.make

CMakeFiles/ProjectE.dir/projecte.c.o: CMakeFiles/ProjectE.dir/flags.make
CMakeFiles/ProjectE.dir/projecte.c.o: ../projecte.c
CMakeFiles/ProjectE.dir/projecte.c.o: CMakeFiles/ProjectE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tazukiswift/Programming/C-Project-Euler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjectE.dir/projecte.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjectE.dir/projecte.c.o -MF CMakeFiles/ProjectE.dir/projecte.c.o.d -o CMakeFiles/ProjectE.dir/projecte.c.o -c /home/tazukiswift/Programming/C-Project-Euler/projecte.c

CMakeFiles/ProjectE.dir/projecte.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectE.dir/projecte.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tazukiswift/Programming/C-Project-Euler/projecte.c > CMakeFiles/ProjectE.dir/projecte.c.i

CMakeFiles/ProjectE.dir/projecte.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectE.dir/projecte.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tazukiswift/Programming/C-Project-Euler/projecte.c -o CMakeFiles/ProjectE.dir/projecte.c.s

CMakeFiles/ProjectE.dir/questions/questions.c.o: CMakeFiles/ProjectE.dir/flags.make
CMakeFiles/ProjectE.dir/questions/questions.c.o: ../questions/questions.c
CMakeFiles/ProjectE.dir/questions/questions.c.o: CMakeFiles/ProjectE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tazukiswift/Programming/C-Project-Euler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjectE.dir/questions/questions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjectE.dir/questions/questions.c.o -MF CMakeFiles/ProjectE.dir/questions/questions.c.o.d -o CMakeFiles/ProjectE.dir/questions/questions.c.o -c /home/tazukiswift/Programming/C-Project-Euler/questions/questions.c

CMakeFiles/ProjectE.dir/questions/questions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectE.dir/questions/questions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tazukiswift/Programming/C-Project-Euler/questions/questions.c > CMakeFiles/ProjectE.dir/questions/questions.c.i

CMakeFiles/ProjectE.dir/questions/questions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectE.dir/questions/questions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tazukiswift/Programming/C-Project-Euler/questions/questions.c -o CMakeFiles/ProjectE.dir/questions/questions.c.s

CMakeFiles/ProjectE.dir/questions/useful.c.o: CMakeFiles/ProjectE.dir/flags.make
CMakeFiles/ProjectE.dir/questions/useful.c.o: ../questions/useful.c
CMakeFiles/ProjectE.dir/questions/useful.c.o: CMakeFiles/ProjectE.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tazukiswift/Programming/C-Project-Euler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ProjectE.dir/questions/useful.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjectE.dir/questions/useful.c.o -MF CMakeFiles/ProjectE.dir/questions/useful.c.o.d -o CMakeFiles/ProjectE.dir/questions/useful.c.o -c /home/tazukiswift/Programming/C-Project-Euler/questions/useful.c

CMakeFiles/ProjectE.dir/questions/useful.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjectE.dir/questions/useful.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tazukiswift/Programming/C-Project-Euler/questions/useful.c > CMakeFiles/ProjectE.dir/questions/useful.c.i

CMakeFiles/ProjectE.dir/questions/useful.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjectE.dir/questions/useful.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tazukiswift/Programming/C-Project-Euler/questions/useful.c -o CMakeFiles/ProjectE.dir/questions/useful.c.s

# Object files for target ProjectE
ProjectE_OBJECTS = \
"CMakeFiles/ProjectE.dir/projecte.c.o" \
"CMakeFiles/ProjectE.dir/questions/questions.c.o" \
"CMakeFiles/ProjectE.dir/questions/useful.c.o"

# External object files for target ProjectE
ProjectE_EXTERNAL_OBJECTS =

ProjectE: CMakeFiles/ProjectE.dir/projecte.c.o
ProjectE: CMakeFiles/ProjectE.dir/questions/questions.c.o
ProjectE: CMakeFiles/ProjectE.dir/questions/useful.c.o
ProjectE: CMakeFiles/ProjectE.dir/build.make
ProjectE: CMakeFiles/ProjectE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tazukiswift/Programming/C-Project-Euler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ProjectE"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjectE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjectE.dir/build: ProjectE
.PHONY : CMakeFiles/ProjectE.dir/build

CMakeFiles/ProjectE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjectE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjectE.dir/clean

CMakeFiles/ProjectE.dir/depend:
	cd /home/tazukiswift/Programming/C-Project-Euler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tazukiswift/Programming/C-Project-Euler /home/tazukiswift/Programming/C-Project-Euler /home/tazukiswift/Programming/C-Project-Euler/build /home/tazukiswift/Programming/C-Project-Euler/build /home/tazukiswift/Programming/C-Project-Euler/build/CMakeFiles/ProjectE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjectE.dir/depend
