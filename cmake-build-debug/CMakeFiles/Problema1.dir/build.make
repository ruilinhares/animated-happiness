# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Asus\Documents\GitHub\animated-happiness

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Asus\Documents\GitHub\animated-happiness\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Problema1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Problema1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Problema1.dir/flags.make

CMakeFiles/Problema1.dir/true_main.c.obj: CMakeFiles/Problema1.dir/flags.make
CMakeFiles/Problema1.dir/true_main.c.obj: ../true_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Asus\Documents\GitHub\animated-happiness\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Problema1.dir/true_main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Problema1.dir\true_main.c.obj   -c C:\Users\Asus\Documents\GitHub\animated-happiness\true_main.c

CMakeFiles/Problema1.dir/true_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Problema1.dir/true_main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Asus\Documents\GitHub\animated-happiness\true_main.c > CMakeFiles\Problema1.dir\true_main.c.i

CMakeFiles/Problema1.dir/true_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Problema1.dir/true_main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Asus\Documents\GitHub\animated-happiness\true_main.c -o CMakeFiles\Problema1.dir\true_main.c.s

CMakeFiles/Problema1.dir/true_main.c.obj.requires:

.PHONY : CMakeFiles/Problema1.dir/true_main.c.obj.requires

CMakeFiles/Problema1.dir/true_main.c.obj.provides: CMakeFiles/Problema1.dir/true_main.c.obj.requires
	$(MAKE) -f CMakeFiles\Problema1.dir\build.make CMakeFiles/Problema1.dir/true_main.c.obj.provides.build
.PHONY : CMakeFiles/Problema1.dir/true_main.c.obj.provides

CMakeFiles/Problema1.dir/true_main.c.obj.provides.build: CMakeFiles/Problema1.dir/true_main.c.obj


# Object files for target Problema1
Problema1_OBJECTS = \
"CMakeFiles/Problema1.dir/true_main.c.obj"

# External object files for target Problema1
Problema1_EXTERNAL_OBJECTS =

Problema1.exe: CMakeFiles/Problema1.dir/true_main.c.obj
Problema1.exe: CMakeFiles/Problema1.dir/build.make
Problema1.exe: CMakeFiles/Problema1.dir/linklibs.rsp
Problema1.exe: CMakeFiles/Problema1.dir/objects1.rsp
Problema1.exe: CMakeFiles/Problema1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Asus\Documents\GitHub\animated-happiness\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Problema1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Problema1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Problema1.dir/build: Problema1.exe

.PHONY : CMakeFiles/Problema1.dir/build

CMakeFiles/Problema1.dir/requires: CMakeFiles/Problema1.dir/true_main.c.obj.requires

.PHONY : CMakeFiles/Problema1.dir/requires

CMakeFiles/Problema1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Problema1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Problema1.dir/clean

CMakeFiles/Problema1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Asus\Documents\GitHub\animated-happiness C:\Users\Asus\Documents\GitHub\animated-happiness C:\Users\Asus\Documents\GitHub\animated-happiness\cmake-build-debug C:\Users\Asus\Documents\GitHub\animated-happiness\cmake-build-debug C:\Users\Asus\Documents\GitHub\animated-happiness\cmake-build-debug\CMakeFiles\Problema1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Problema1.dir/depend

