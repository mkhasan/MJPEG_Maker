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
CMAKE_SOURCE_DIR = /home/hasan/hdd/mjpeg_maker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hasan/hdd/mjpeg_maker/build

# Include any dependencies generated for this target.
include CMakeFiles/mjepg_maker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mjepg_maker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mjepg_maker.dir/flags.make

CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o: ../src/mjepg_maker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/mjepg_maker.cpp

CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/mjepg_maker.cpp > CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.i

CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/mjepg_maker.cpp -o CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.s

CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o


CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o: ../src/client_handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/client_handler.cpp

CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/client_handler.cpp > CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.i

CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/client_handler.cpp -o CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.s

CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o


CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o: ../src/CStreamer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/CStreamer.cpp

CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/CStreamer.cpp > CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.i

CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/CStreamer.cpp -o CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.s

CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o


CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o: ../src/JPEGSamples.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/JPEGSamples.cpp

CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/JPEGSamples.cpp > CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.i

CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/JPEGSamples.cpp -o CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.s

CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o


CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o: ../src/CRtspSession.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/CRtspSession.cpp

CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/CRtspSession.cpp > CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.i

CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/CRtspSession.cpp -o CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.s

CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o


CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o: ../src/JPEG_Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/JPEG_Test.cpp

CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/JPEG_Test.cpp > CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.i

CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/JPEG_Test.cpp -o CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.s

CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o


CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o: ../src/JPEG_Write.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/JPEG_Write.cpp

CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/JPEG_Write.cpp > CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.i

CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/JPEG_Write.cpp -o CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.s

CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o


CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o: ../src/mjpeg_tester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/mjpeg_tester.cpp

CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/mjpeg_tester.cpp > CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.i

CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/mjpeg_tester.cpp -o CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.s

CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o


CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o: ../src/stream_source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/stream_source.cpp

CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/stream_source.cpp > CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.i

CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/stream_source.cpp -o CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.s

CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o


CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o: CMakeFiles/mjepg_maker.dir/flags.make
CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o: ../src/fake_source.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o -c /home/hasan/hdd/mjpeg_maker/src/fake_source.cpp

CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hasan/hdd/mjpeg_maker/src/fake_source.cpp > CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.i

CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hasan/hdd/mjpeg_maker/src/fake_source.cpp -o CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.s

CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.requires:

.PHONY : CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.requires

CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.provides: CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.requires
	$(MAKE) -f CMakeFiles/mjepg_maker.dir/build.make CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.provides.build
.PHONY : CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.provides

CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.provides.build: CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o


# Object files for target mjepg_maker
mjepg_maker_OBJECTS = \
"CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o" \
"CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o"

# External object files for target mjepg_maker
mjepg_maker_EXTERNAL_OBJECTS =

../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/build.make
../bin/mjepg_maker: CMakeFiles/mjepg_maker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hasan/hdd/mjpeg_maker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable ../bin/mjepg_maker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mjepg_maker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mjepg_maker.dir/build: ../bin/mjepg_maker

.PHONY : CMakeFiles/mjepg_maker.dir/build

CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/mjepg_maker.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/client_handler.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/CStreamer.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/JPEGSamples.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/CRtspSession.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/JPEG_Test.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/JPEG_Write.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/mjpeg_tester.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/stream_source.cpp.o.requires
CMakeFiles/mjepg_maker.dir/requires: CMakeFiles/mjepg_maker.dir/src/fake_source.cpp.o.requires

.PHONY : CMakeFiles/mjepg_maker.dir/requires

CMakeFiles/mjepg_maker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mjepg_maker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mjepg_maker.dir/clean

CMakeFiles/mjepg_maker.dir/depend:
	cd /home/hasan/hdd/mjpeg_maker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hasan/hdd/mjpeg_maker /home/hasan/hdd/mjpeg_maker /home/hasan/hdd/mjpeg_maker/build /home/hasan/hdd/mjpeg_maker/build /home/hasan/hdd/mjpeg_maker/build/CMakeFiles/mjepg_maker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mjepg_maker.dir/depend

