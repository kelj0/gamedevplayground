# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/kelj0/Downloads/clion-2020.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kelj0/Downloads/clion-2020.3.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kelj0/github/gamedevplayground/2D_shooter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kelj0/github/gamedevplayground/2D_shooter/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2D_shooter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2D_shooter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2D_shooter.dir/flags.make

CMakeFiles/2D_shooter.dir/main.cpp.o: CMakeFiles/2D_shooter.dir/flags.make
CMakeFiles/2D_shooter.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2D_shooter.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2D_shooter.dir/main.cpp.o -c /home/kelj0/github/gamedevplayground/2D_shooter/main.cpp

CMakeFiles/2D_shooter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2D_shooter.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kelj0/github/gamedevplayground/2D_shooter/main.cpp > CMakeFiles/2D_shooter.dir/main.cpp.i

CMakeFiles/2D_shooter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2D_shooter.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kelj0/github/gamedevplayground/2D_shooter/main.cpp -o CMakeFiles/2D_shooter.dir/main.cpp.s

# Object files for target 2D_shooter
2D_shooter_OBJECTS = \
"CMakeFiles/2D_shooter.dir/main.cpp.o"

# External object files for target 2D_shooter
2D_shooter_EXTERNAL_OBJECTS =

2D_shooter: CMakeFiles/2D_shooter.dir/main.cpp.o
2D_shooter: CMakeFiles/2D_shooter.dir/build.make
2D_shooter: CMakeFiles/2D_shooter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2D_shooter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2D_shooter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2D_shooter.dir/build: 2D_shooter

.PHONY : CMakeFiles/2D_shooter.dir/build

CMakeFiles/2D_shooter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2D_shooter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2D_shooter.dir/clean

CMakeFiles/2D_shooter.dir/depend:
	cd /home/kelj0/github/gamedevplayground/2D_shooter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kelj0/github/gamedevplayground/2D_shooter /home/kelj0/github/gamedevplayground/2D_shooter /home/kelj0/github/gamedevplayground/2D_shooter/cmake-build-debug /home/kelj0/github/gamedevplayground/2D_shooter/cmake-build-debug /home/kelj0/github/gamedevplayground/2D_shooter/cmake-build-debug/CMakeFiles/2D_shooter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2D_shooter.dir/depend
