# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ej2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ej2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ej2.dir/flags.make

CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.o: CMakeFiles/ej2.dir/flags.make
CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.o: ../tests/ej2_periodo_y_fecha.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.o -c /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/tests/ej2_periodo_y_fecha.cpp

CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/tests/ej2_periodo_y_fecha.cpp > CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.i

CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/tests/ej2_periodo_y_fecha.cpp -o CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.s

CMakeFiles/ej2.dir/src/Periodo.cpp.o: CMakeFiles/ej2.dir/flags.make
CMakeFiles/ej2.dir/src/Periodo.cpp.o: ../src/Periodo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ej2.dir/src/Periodo.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ej2.dir/src/Periodo.cpp.o -c /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/src/Periodo.cpp

CMakeFiles/ej2.dir/src/Periodo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ej2.dir/src/Periodo.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/src/Periodo.cpp > CMakeFiles/ej2.dir/src/Periodo.cpp.i

CMakeFiles/ej2.dir/src/Periodo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ej2.dir/src/Periodo.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/src/Periodo.cpp -o CMakeFiles/ej2.dir/src/Periodo.cpp.s

# Object files for target ej2
ej2_OBJECTS = \
"CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.o" \
"CMakeFiles/ej2.dir/src/Periodo.cpp.o"

# External object files for target ej2
ej2_EXTERNAL_OBJECTS =

ej2: CMakeFiles/ej2.dir/tests/ej2_periodo_y_fecha.cpp.o
ej2: CMakeFiles/ej2.dir/src/Periodo.cpp.o
ej2: CMakeFiles/ej2.dir/build.make
ej2: libgtest.a
ej2: libgtest_main.a
ej2: CMakeFiles/ej2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ej2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ej2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ej2.dir/build: ej2

.PHONY : CMakeFiles/ej2.dir/build

CMakeFiles/ej2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej2.dir/clean

CMakeFiles/ej2.dir/depend:
	cd /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug /Users/lisandrodiaz/Desktop/Facultad/Algoritmos2/labo/ejercitacion_member-classes/cmake-build-debug/CMakeFiles/ej2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ej2.dir/depend

