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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/correrTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/correrTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/correrTests.dir/flags.make

CMakeFiles/correrTests.dir/tests/lista_tests.cpp.o: CMakeFiles/correrTests.dir/flags.make
CMakeFiles/correrTests.dir/tests/lista_tests.cpp.o: ../tests/lista_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/correrTests.dir/tests/lista_tests.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/correrTests.dir/tests/lista_tests.cpp.o -c /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/tests/lista_tests.cpp

CMakeFiles/correrTests.dir/tests/lista_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/correrTests.dir/tests/lista_tests.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/tests/lista_tests.cpp > CMakeFiles/correrTests.dir/tests/lista_tests.cpp.i

CMakeFiles/correrTests.dir/tests/lista_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/correrTests.dir/tests/lista_tests.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/tests/lista_tests.cpp -o CMakeFiles/correrTests.dir/tests/lista_tests.cpp.s

# Object files for target correrTests
correrTests_OBJECTS = \
"CMakeFiles/correrTests.dir/tests/lista_tests.cpp.o"

# External object files for target correrTests
correrTests_EXTERNAL_OBJECTS =

correrTests.exe: CMakeFiles/correrTests.dir/tests/lista_tests.cpp.o
correrTests.exe: CMakeFiles/correrTests.dir/build.make
correrTests.exe: libgtest.a
correrTests.exe: libgtest_main.a
correrTests.exe: CMakeFiles/correrTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable correrTests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/correrTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/correrTests.dir/build: correrTests.exe

.PHONY : CMakeFiles/correrTests.dir/build

CMakeFiles/correrTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/correrTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/correrTests.dir/clean

CMakeFiles/correrTests.dir/depend:
	cd /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/cmake-build-debug /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/cmake-build-debug /cygdrive/c/Users/victo/Documents/zPersonal/Facultad/AED2/Victor/Labo/Practicas/Ejercitacion05/alumnos/cmake-build-debug/CMakeFiles/correrTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/correrTests.dir/depend

