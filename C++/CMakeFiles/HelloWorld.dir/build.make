# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/pate/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pate/C++

# Include any dependencies generated for this target.
include CMakeFiles/HelloWorld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloWorld.dir/flags.make

CMakeFiles/HelloWorld.dir/src/Main.cpp.o: CMakeFiles/HelloWorld.dir/flags.make
CMakeFiles/HelloWorld.dir/src/Main.cpp.o: src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pate/C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloWorld.dir/src/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HelloWorld.dir/src/Main.cpp.o -c /home/pate/C++/src/Main.cpp

CMakeFiles/HelloWorld.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pate/C++/src/Main.cpp > CMakeFiles/HelloWorld.dir/src/Main.cpp.i

CMakeFiles/HelloWorld.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pate/C++/src/Main.cpp -o CMakeFiles/HelloWorld.dir/src/Main.cpp.s

CMakeFiles/HelloWorld.dir/src/Main.cpp.o.requires:

.PHONY : CMakeFiles/HelloWorld.dir/src/Main.cpp.o.requires

CMakeFiles/HelloWorld.dir/src/Main.cpp.o.provides: CMakeFiles/HelloWorld.dir/src/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/HelloWorld.dir/build.make CMakeFiles/HelloWorld.dir/src/Main.cpp.o.provides.build
.PHONY : CMakeFiles/HelloWorld.dir/src/Main.cpp.o.provides

CMakeFiles/HelloWorld.dir/src/Main.cpp.o.provides.build: CMakeFiles/HelloWorld.dir/src/Main.cpp.o


# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles/HelloWorld.dir/src/Main.cpp.o"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld: CMakeFiles/HelloWorld.dir/src/Main.cpp.o
HelloWorld: CMakeFiles/HelloWorld.dir/build.make
HelloWorld: CMakeFiles/HelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pate/C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloWorld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HelloWorld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloWorld.dir/build: HelloWorld

.PHONY : CMakeFiles/HelloWorld.dir/build

CMakeFiles/HelloWorld.dir/requires: CMakeFiles/HelloWorld.dir/src/Main.cpp.o.requires

.PHONY : CMakeFiles/HelloWorld.dir/requires

CMakeFiles/HelloWorld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HelloWorld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HelloWorld.dir/clean

CMakeFiles/HelloWorld.dir/depend:
	cd /home/pate/C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pate/C++ /home/pate/C++ /home/pate/C++ /home/pate/C++ /home/pate/C++/CMakeFiles/HelloWorld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloWorld.dir/depend

