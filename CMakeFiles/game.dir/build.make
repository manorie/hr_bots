# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /home/mcetin/Dev/cpp/hr_bots

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mcetin/Dev/cpp/hr_bots

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mcetin/Dev/cpp/hr_bots/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/main.cpp.o"
	$(CMAKE_COMMAND) -E __run_co_compile --cppcheck=cppcheck --source=/home/mcetin/Dev/cpp/hr_bots/main.cpp -- /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/main.cpp.o -c /home/mcetin/Dev/cpp/hr_bots/main.cpp

CMakeFiles/game.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mcetin/Dev/cpp/hr_bots/main.cpp > CMakeFiles/game.dir/main.cpp.i

CMakeFiles/game.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mcetin/Dev/cpp/hr_bots/main.cpp -o CMakeFiles/game.dir/main.cpp.s

CMakeFiles/game.dir/board.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/board.cpp.o: board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mcetin/Dev/cpp/hr_bots/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/board.cpp.o"
	$(CMAKE_COMMAND) -E __run_co_compile --cppcheck=cppcheck --source=/home/mcetin/Dev/cpp/hr_bots/board.cpp -- /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/board.cpp.o -c /home/mcetin/Dev/cpp/hr_bots/board.cpp

CMakeFiles/game.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mcetin/Dev/cpp/hr_bots/board.cpp > CMakeFiles/game.dir/board.cpp.i

CMakeFiles/game.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mcetin/Dev/cpp/hr_bots/board.cpp -o CMakeFiles/game.dir/board.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/main.cpp.o" \
"CMakeFiles/game.dir/board.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/main.cpp.o
game: CMakeFiles/game.dir/board.cpp.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mcetin/Dev/cpp/hr_bots/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/mcetin/Dev/cpp/hr_bots && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mcetin/Dev/cpp/hr_bots /home/mcetin/Dev/cpp/hr_bots /home/mcetin/Dev/cpp/hr_bots /home/mcetin/Dev/cpp/hr_bots /home/mcetin/Dev/cpp/hr_bots/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

