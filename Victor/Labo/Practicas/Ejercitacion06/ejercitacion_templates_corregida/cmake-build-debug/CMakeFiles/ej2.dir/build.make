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
CMAKE_SOURCE_DIR = /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej2.dir/flags.make

CMakeFiles/ej2.dir/tests/test_templates.cpp.o: CMakeFiles/ej2.dir/flags.make
CMakeFiles/ej2.dir/tests/test_templates.cpp.o: ../tests/test_templates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej2.dir/tests/test_templates.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej2.dir/tests/test_templates.cpp.o -c /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/tests/test_templates.cpp

CMakeFiles/ej2.dir/tests/test_templates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej2.dir/tests/test_templates.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/tests/test_templates.cpp > CMakeFiles/ej2.dir/tests/test_templates.cpp.i

CMakeFiles/ej2.dir/tests/test_templates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej2.dir/tests/test_templates.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/tests/test_templates.cpp -o CMakeFiles/ej2.dir/tests/test_templates.cpp.s

# Object files for target ej2
ej2_OBJECTS = \
"CMakeFiles/ej2.dir/tests/test_templates.cpp.o"

# External object files for target ej2
ej2_EXTERNAL_OBJECTS =

ej2.exe: CMakeFiles/ej2.dir/tests/test_templates.cpp.o
ej2.exe: CMakeFiles/ej2.dir/build.make
ej2.exe: tests/google-test/libgtest.a
ej2.exe: tests/google-test/libgtest_main.a
ej2.exe: tests/google-test/libgtest.a
ej2.exe: CMakeFiles/ej2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ej2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej2.dir/build: ej2.exe

.PHONY : CMakeFiles/ej2.dir/build

CMakeFiles/ej2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej2.dir/clean

CMakeFiles/ej2.dir/depend:
	cd /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/cmake-build-debug /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/cmake-build-debug /cygdrive/c/Users/victo/Documents/Proyects/Facultad/Algo2/Victor/Labo/Practicas/Ejercitacion06/ejercitacion_templates_corregida/cmake-build-debug/CMakeFiles/ej2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej2.dir/depend

