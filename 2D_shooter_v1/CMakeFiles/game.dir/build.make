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
CMAKE_SOURCE_DIR = /home/kelj0/github/gamedevplayground/2D_shooter_v1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kelj0/github/gamedevplayground/2D_shooter_v1

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter_v1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/main.cpp.o -c /home/kelj0/github/gamedevplayground/2D_shooter_v1/main.cpp

CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kelj0/github/gamedevplayground/2D_shooter_v1/main.cpp > CMakeFiles/game.dir/main.cpp.i

CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kelj0/github/gamedevplayground/2D_shooter_v1/main.cpp -o CMakeFiles/game.dir/main.cpp.s

CMakeFiles/game.dir/src/DebugEngine.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/DebugEngine.cpp.o: src/DebugEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter_v1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/DebugEngine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/DebugEngine.cpp.o -c /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/DebugEngine.cpp

CMakeFiles/game.dir/src/DebugEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/DebugEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/DebugEngine.cpp > CMakeFiles/game.dir/src/DebugEngine.cpp.i

CMakeFiles/game.dir/src/DebugEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/DebugEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/DebugEngine.cpp -o CMakeFiles/game.dir/src/DebugEngine.cpp.s

CMakeFiles/game.dir/src/Engine.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Engine.cpp.o: src/Engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter_v1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/Engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Engine.cpp.o -c /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Engine.cpp

CMakeFiles/game.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Engine.cpp > CMakeFiles/game.dir/src/Engine.cpp.i

CMakeFiles/game.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Engine.cpp -o CMakeFiles/game.dir/src/Engine.cpp.s

CMakeFiles/game.dir/src/Player.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Player.cpp.o: src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter_v1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Player.cpp.o -c /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Player.cpp

CMakeFiles/game.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Player.cpp > CMakeFiles/game.dir/src/Player.cpp.i

CMakeFiles/game.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Player.cpp -o CMakeFiles/game.dir/src/Player.cpp.s

CMakeFiles/game.dir/src/Position.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/Position.cpp.o: src/Position.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter_v1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/Position.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/Position.cpp.o -c /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Position.cpp

CMakeFiles/game.dir/src/Position.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/Position.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Position.cpp > CMakeFiles/game.dir/src/Position.cpp.i

CMakeFiles/game.dir/src/Position.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/Position.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kelj0/github/gamedevplayground/2D_shooter_v1/src/Position.cpp -o CMakeFiles/game.dir/src/Position.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main.cpp.o" \
"CMakeFiles/game.dir/src/DebugEngine.cpp.o" \
"CMakeFiles/game.dir/src/Engine.cpp.o" \
"CMakeFiles/game.dir/src/Player.cpp.o" \
"CMakeFiles/game.dir/src/Position.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/main.cpp.o
game: CMakeFiles/game.dir/src/DebugEngine.cpp.o
game: CMakeFiles/game.dir/src/Engine.cpp.o
game: CMakeFiles/game.dir/src/Player.cpp.o
game: CMakeFiles/game.dir/src/Position.cpp.o
game: CMakeFiles/game.dir/build.make
game: /home/kelj0/github/gamedevplayground/SFML/lib/libsfml-graphics.so.2.5.1
game: /home/kelj0/github/gamedevplayground/SFML/lib/libsfml-audio.so.2.5.1
game: /home/kelj0/github/gamedevplayground/SFML/lib/libsfml-window.so.2.5.1
game: /home/kelj0/github/gamedevplayground/SFML/lib/libsfml-system.so.2.5.1
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kelj0/github/gamedevplayground/2D_shooter_v1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/kelj0/github/gamedevplayground/2D_shooter_v1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kelj0/github/gamedevplayground/2D_shooter_v1 /home/kelj0/github/gamedevplayground/2D_shooter_v1 /home/kelj0/github/gamedevplayground/2D_shooter_v1 /home/kelj0/github/gamedevplayground/2D_shooter_v1 /home/kelj0/github/gamedevplayground/2D_shooter_v1/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

