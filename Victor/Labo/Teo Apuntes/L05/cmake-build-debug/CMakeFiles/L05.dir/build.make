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
CMAKE_COMMAND = /cygdrive/c/Users/victor/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/victor/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/L05.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/L05.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/L05.dir/flags.make

CMakeFiles/L05.dir/main.cpp.o: CMakeFiles/L05.dir/flags.make
CMakeFiles/L05.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/L05.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/L05.dir/main.cpp.o -c "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/main.cpp"

CMakeFiles/L05.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L05.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/main.cpp" > CMakeFiles/L05.dir/main.cpp.i

CMakeFiles/L05.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L05.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/main.cpp" -o CMakeFiles/L05.dir/main.cpp.s

CMakeFiles/L05.dir/testStruct.cpp.o: CMakeFiles/L05.dir/flags.make
CMakeFiles/L05.dir/testStruct.cpp.o: ../testStruct.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/L05.dir/testStruct.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/L05.dir/testStruct.cpp.o -c "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/testStruct.cpp"

CMakeFiles/L05.dir/testStruct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/L05.dir/testStruct.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/testStruct.cpp" > CMakeFiles/L05.dir/testStruct.cpp.i

CMakeFiles/L05.dir/testStruct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/L05.dir/testStruct.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/testStruct.cpp" -o CMakeFiles/L05.dir/testStruct.cpp.s

# Object files for target L05
L05_OBJECTS = \
"CMakeFiles/L05.dir/main.cpp.o" \
"CMakeFiles/L05.dir/testStruct.cpp.o"

# External object files for target L05
L05_EXTERNAL_OBJECTS =

L05.exe: CMakeFiles/L05.dir/main.cpp.o
L05.exe: CMakeFiles/L05.dir/testStruct.cpp.o
L05.exe: CMakeFiles/L05.dir/build.make
L05.exe: CMakeFiles/L05.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable L05.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/L05.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/L05.dir/build: L05.exe

.PHONY : CMakeFiles/L05.dir/build

CMakeFiles/L05.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/L05.dir/cmake_clean.cmake
.PHONY : CMakeFiles/L05.dir/clean

CMakeFiles/L05.dir/depend:
	cd "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05" "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05" "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug" "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug" "/cygdrive/d/CLionProjects/Algo2/Victor/Labo/Teo Apuntes/L05/cmake-build-debug/CMakeFiles/L05.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/L05.dir/depend
