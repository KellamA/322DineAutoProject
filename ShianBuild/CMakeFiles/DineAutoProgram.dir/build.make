# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shianwen123/DineAuto/322DineAutoProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shianwen123/DineAuto/322DineAutoProject/ShianBuild

# Include any dependencies generated for this target.
include CMakeFiles/DineAutoProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DineAutoProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DineAutoProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DineAutoProgram.dir/flags.make

CMakeFiles/DineAutoProgram.dir/main.cpp.o: CMakeFiles/DineAutoProgram.dir/flags.make
CMakeFiles/DineAutoProgram.dir/main.cpp.o: ../main.cpp
CMakeFiles/DineAutoProgram.dir/main.cpp.o: CMakeFiles/DineAutoProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shianwen123/DineAuto/322DineAutoProject/ShianBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DineAutoProgram.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DineAutoProgram.dir/main.cpp.o -MF CMakeFiles/DineAutoProgram.dir/main.cpp.o.d -o CMakeFiles/DineAutoProgram.dir/main.cpp.o -c /home/shianwen123/DineAuto/322DineAutoProject/main.cpp

CMakeFiles/DineAutoProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DineAutoProgram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shianwen123/DineAuto/322DineAutoProject/main.cpp > CMakeFiles/DineAutoProgram.dir/main.cpp.i

CMakeFiles/DineAutoProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DineAutoProgram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shianwen123/DineAuto/322DineAutoProject/main.cpp -o CMakeFiles/DineAutoProgram.dir/main.cpp.s

CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o: CMakeFiles/DineAutoProgram.dir/flags.make
CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o: ../orderDataBase.cpp
CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o: CMakeFiles/DineAutoProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shianwen123/DineAuto/322DineAutoProject/ShianBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o -MF CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o.d -o CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o -c /home/shianwen123/DineAuto/322DineAutoProject/orderDataBase.cpp

CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shianwen123/DineAuto/322DineAutoProject/orderDataBase.cpp > CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.i

CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shianwen123/DineAuto/322DineAutoProject/orderDataBase.cpp -o CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.s

CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o: CMakeFiles/DineAutoProgram.dir/flags.make
CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o: ../menuItem.cpp
CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o: CMakeFiles/DineAutoProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shianwen123/DineAuto/322DineAutoProject/ShianBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o -MF CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o.d -o CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o -c /home/shianwen123/DineAuto/322DineAutoProject/menuItem.cpp

CMakeFiles/DineAutoProgram.dir/menuItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DineAutoProgram.dir/menuItem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shianwen123/DineAuto/322DineAutoProject/menuItem.cpp > CMakeFiles/DineAutoProgram.dir/menuItem.cpp.i

CMakeFiles/DineAutoProgram.dir/menuItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DineAutoProgram.dir/menuItem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shianwen123/DineAuto/322DineAutoProject/menuItem.cpp -o CMakeFiles/DineAutoProgram.dir/menuItem.cpp.s

CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o: CMakeFiles/DineAutoProgram.dir/flags.make
CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o: ../shoppingCart.cpp
CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o: CMakeFiles/DineAutoProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shianwen123/DineAuto/322DineAutoProject/ShianBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o -MF CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o.d -o CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o -c /home/shianwen123/DineAuto/322DineAutoProject/shoppingCart.cpp

CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shianwen123/DineAuto/322DineAutoProject/shoppingCart.cpp > CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.i

CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shianwen123/DineAuto/322DineAutoProject/shoppingCart.cpp -o CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.s

# Object files for target DineAutoProgram
DineAutoProgram_OBJECTS = \
"CMakeFiles/DineAutoProgram.dir/main.cpp.o" \
"CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o" \
"CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o" \
"CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o"

# External object files for target DineAutoProgram
DineAutoProgram_EXTERNAL_OBJECTS =

DineAutoProgram: CMakeFiles/DineAutoProgram.dir/main.cpp.o
DineAutoProgram: CMakeFiles/DineAutoProgram.dir/orderDataBase.cpp.o
DineAutoProgram: CMakeFiles/DineAutoProgram.dir/menuItem.cpp.o
DineAutoProgram: CMakeFiles/DineAutoProgram.dir/shoppingCart.cpp.o
DineAutoProgram: CMakeFiles/DineAutoProgram.dir/build.make
DineAutoProgram: CMakeFiles/DineAutoProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shianwen123/DineAuto/322DineAutoProject/ShianBuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DineAutoProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DineAutoProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DineAutoProgram.dir/build: DineAutoProgram
.PHONY : CMakeFiles/DineAutoProgram.dir/build

CMakeFiles/DineAutoProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DineAutoProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DineAutoProgram.dir/clean

CMakeFiles/DineAutoProgram.dir/depend:
	cd /home/shianwen123/DineAuto/322DineAutoProject/ShianBuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shianwen123/DineAuto/322DineAutoProject /home/shianwen123/DineAuto/322DineAutoProject /home/shianwen123/DineAuto/322DineAutoProject/ShianBuild /home/shianwen123/DineAuto/322DineAutoProject/ShianBuild /home/shianwen123/DineAuto/322DineAutoProject/ShianBuild/CMakeFiles/DineAutoProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DineAutoProgram.dir/depend

