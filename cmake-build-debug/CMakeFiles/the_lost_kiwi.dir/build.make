# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/162/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/162/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/forestileao/Documents/the-lost-kiwi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/forestileao/Documents/the-lost-kiwi/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/the_lost_kiwi.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/the_lost_kiwi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/the_lost_kiwi.dir/flags.make

CMakeFiles/the_lost_kiwi.dir/src/main.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/main.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/main.cpp

CMakeFiles/the_lost_kiwi.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/main.cpp > CMakeFiles/the_lost_kiwi.dir/src/main.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/main.cpp -o CMakeFiles/the_lost_kiwi.dir/src/main.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Game.cpp

CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Game.cpp > CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Game.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.o: ../src/Entities/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Entities/Entity.cpp

CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Entities/Entity.cpp > CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Entities/Entity.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.o: ../src/Entities/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Entities/Player.cpp

CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Entities/Player.cpp > CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Entities/Player.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.o: ../src/Entities/Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Entities/Enemy.cpp

CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Entities/Enemy.cpp > CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Entities/Enemy.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.o: ../src/Stages/EntityList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Stages/EntityList.cpp

CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Stages/EntityList.cpp > CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Stages/EntityList.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.o: ../src/Stages/Stage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Stages/Stage.cpp

CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Stages/Stage.cpp > CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Stages/Stage.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.o: ../src/Entities/Character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Entities/Character.cpp

CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Entities/Character.cpp > CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Entities/Character.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.o: ../src/States/State.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/States/State.cpp

CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/States/State.cpp > CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/States/State.cpp -o CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.o: ../src/States/StateMachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/States/StateMachine.cpp

CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/States/StateMachine.cpp > CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/States/StateMachine.cpp -o CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.o: ../src/Managers/EventManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Managers/EventManager.cpp

CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Managers/EventManager.cpp > CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Managers/EventManager.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.o: ../src/Managers/GraphicManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Managers/GraphicManager.cpp

CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Managers/GraphicManager.cpp > CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Managers/GraphicManager.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.o: ../src/States/GameStateMachine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/States/GameStateMachine.cpp

CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/States/GameStateMachine.cpp > CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/States/GameStateMachine.cpp -o CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.o: ../src/States/PlayState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/States/PlayState.cpp

CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/States/PlayState.cpp > CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/States/PlayState.cpp -o CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.o: ../src/States/MainMenuState.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/States/MainMenuState.cpp

CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/States/MainMenuState.cpp > CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/States/MainMenuState.cpp -o CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.o: ../src/Entities/Projectile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Entities/Projectile.cpp

CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Entities/Projectile.cpp > CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Entities/Projectile.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.s

CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.o: CMakeFiles/the_lost_kiwi.dir/flags.make
CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.o: ../src/Entities/Archer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.o -c /home/forestileao/Documents/the-lost-kiwi/src/Entities/Archer.cpp

CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/forestileao/Documents/the-lost-kiwi/src/Entities/Archer.cpp > CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.i

CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/forestileao/Documents/the-lost-kiwi/src/Entities/Archer.cpp -o CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.s

# Object files for target the_lost_kiwi
the_lost_kiwi_OBJECTS = \
"CMakeFiles/the_lost_kiwi.dir/src/main.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.o" \
"CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.o"

# External object files for target the_lost_kiwi
the_lost_kiwi_EXTERNAL_OBJECTS =

the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/main.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Game.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Entities/Entity.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Entities/Player.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Entities/Enemy.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Stages/EntityList.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Stages/Stage.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Entities/Character.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/States/State.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/States/StateMachine.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Managers/EventManager.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Managers/GraphicManager.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/States/GameStateMachine.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/States/PlayState.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/States/MainMenuState.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Entities/Projectile.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/src/Entities/Archer.cpp.o
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/build.make
the_lost_kiwi: /usr/lib64/libsfml-graphics.so.2.5.1
the_lost_kiwi: /usr/lib64/libsfml-window.so.2.5.1
the_lost_kiwi: /usr/lib64/libsfml-system.so.2.5.1
the_lost_kiwi: CMakeFiles/the_lost_kiwi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable the_lost_kiwi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/the_lost_kiwi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/the_lost_kiwi.dir/build: the_lost_kiwi
.PHONY : CMakeFiles/the_lost_kiwi.dir/build

CMakeFiles/the_lost_kiwi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/the_lost_kiwi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/the_lost_kiwi.dir/clean

CMakeFiles/the_lost_kiwi.dir/depend:
	cd /home/forestileao/Documents/the-lost-kiwi/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/forestileao/Documents/the-lost-kiwi /home/forestileao/Documents/the-lost-kiwi /home/forestileao/Documents/the-lost-kiwi/cmake-build-debug /home/forestileao/Documents/the-lost-kiwi/cmake-build-debug /home/forestileao/Documents/the-lost-kiwi/cmake-build-debug/CMakeFiles/the_lost_kiwi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/the_lost_kiwi.dir/depend

