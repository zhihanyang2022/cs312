# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build

# Include any dependencies generated for this target.
include CMakeFiles/midiout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/midiout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/midiout.dir/flags.make

CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.o: CMakeFiles/midiout.dir/flags.make
CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.o: /Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.o -c /Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp

CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp > CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.i

CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp -o CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.s

CMakeFiles/midiout.dir/c623_rt_midiout.cpp.o: CMakeFiles/midiout.dir/flags.make
CMakeFiles/midiout.dir/c623_rt_midiout.cpp.o: ../c623_rt_midiout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/midiout.dir/c623_rt_midiout.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/midiout.dir/c623_rt_midiout.cpp.o -c /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/c623_rt_midiout.cpp

CMakeFiles/midiout.dir/c623_rt_midiout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/midiout.dir/c623_rt_midiout.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/c623_rt_midiout.cpp > CMakeFiles/midiout.dir/c623_rt_midiout.cpp.i

CMakeFiles/midiout.dir/c623_rt_midiout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/midiout.dir/c623_rt_midiout.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/c623_rt_midiout.cpp -o CMakeFiles/midiout.dir/c623_rt_midiout.cpp.s

# Object files for target midiout
midiout_OBJECTS = \
"CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.o" \
"CMakeFiles/midiout.dir/c623_rt_midiout.cpp.o"

# External object files for target midiout
midiout_EXTERNAL_OBJECTS =

midiout: CMakeFiles/midiout.dir/Volumes/cs312-00-w20/StuWork/yangz2/common/RtMidi/RtMidi.cpp.o
midiout: CMakeFiles/midiout.dir/c623_rt_midiout.cpp.o
midiout: CMakeFiles/midiout.dir/build.make
midiout: CMakeFiles/midiout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable midiout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/midiout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/midiout.dir/build: midiout

.PHONY : CMakeFiles/midiout.dir/build

CMakeFiles/midiout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/midiout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/midiout.dir/clean

CMakeFiles/midiout.dir/depend:
	cd /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build /Volumes/cs312-00-w20/StuWork/yangz2/cs312/hw62/c623_rt_midiout/build/CMakeFiles/midiout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/midiout.dir/depend

