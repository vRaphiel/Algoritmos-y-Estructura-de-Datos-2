# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /cygdrive/c/Users/victo/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/victo/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04

# Utility rule file for ej3_correrValgrind.

# Include the progress variables for this target.
include CMakeFiles/ej3_correrValgrind.dir/progress.make

CMakeFiles/ej3_correrValgrind: ej3.exe
	valgrind --leak-check=full -v ./ej3 2>&1

ej3_correrValgrind: CMakeFiles/ej3_correrValgrind
ej3_correrValgrind: CMakeFiles/ej3_correrValgrind.dir/build.make

.PHONY : ej3_correrValgrind

# Rule to build all files generated by this target.
CMakeFiles/ej3_correrValgrind.dir/build: ej3_correrValgrind

.PHONY : CMakeFiles/ej3_correrValgrind.dir/build

CMakeFiles/ej3_correrValgrind.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej3_correrValgrind.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej3_correrValgrind.dir/clean

CMakeFiles/ej3_correrValgrind.dir/depend:
	cd /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04 /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04 /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04 /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04 /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion04/CMakeFiles/ej3_correrValgrind.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej3_correrValgrind.dir/depend

