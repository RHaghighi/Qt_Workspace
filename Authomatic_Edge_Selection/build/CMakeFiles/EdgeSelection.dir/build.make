# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build

# Include any dependencies generated for this target.
include CMakeFiles/EdgeSelection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EdgeSelection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EdgeSelection.dir/flags.make

ui_mainwindow.h: /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/mainwindow.ui
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ui_mainwindow.h"
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic -o /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/ui_mainwindow.h /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/mainwindow.ui

moc_mainwindow.cxx: /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/mainwindow.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating moc_mainwindow.cxx"
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc @/home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/moc_mainwindow.cxx_parameters

CMakeFiles/EdgeSelection.dir/main.cpp.o: CMakeFiles/EdgeSelection.dir/flags.make
CMakeFiles/EdgeSelection.dir/main.cpp.o: /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/EdgeSelection.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/EdgeSelection.dir/main.cpp.o -c /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/main.cpp

CMakeFiles/EdgeSelection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EdgeSelection.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/main.cpp > CMakeFiles/EdgeSelection.dir/main.cpp.i

CMakeFiles/EdgeSelection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EdgeSelection.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/main.cpp -o CMakeFiles/EdgeSelection.dir/main.cpp.s

CMakeFiles/EdgeSelection.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/EdgeSelection.dir/main.cpp.o.requires

CMakeFiles/EdgeSelection.dir/main.cpp.o.provides: CMakeFiles/EdgeSelection.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/EdgeSelection.dir/build.make CMakeFiles/EdgeSelection.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/EdgeSelection.dir/main.cpp.o.provides

CMakeFiles/EdgeSelection.dir/main.cpp.o.provides.build: CMakeFiles/EdgeSelection.dir/main.cpp.o

CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o: CMakeFiles/EdgeSelection.dir/flags.make
CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o: /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/mainwindow.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o -c /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/mainwindow.cpp

CMakeFiles/EdgeSelection.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EdgeSelection.dir/mainwindow.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/mainwindow.cpp > CMakeFiles/EdgeSelection.dir/mainwindow.cpp.i

CMakeFiles/EdgeSelection.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EdgeSelection.dir/mainwindow.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection/mainwindow.cpp -o CMakeFiles/EdgeSelection.dir/mainwindow.cpp.s

CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.requires:
.PHONY : CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.requires

CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.provides: CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/EdgeSelection.dir/build.make CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.provides.build
.PHONY : CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.provides

CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.provides.build: CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o

CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o: CMakeFiles/EdgeSelection.dir/flags.make
CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o: moc_mainwindow.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o -c /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/moc_mainwindow.cxx

CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/moc_mainwindow.cxx > CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.i

CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/moc_mainwindow.cxx -o CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.s

CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.requires:
.PHONY : CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.requires

CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.provides: CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.requires
	$(MAKE) -f CMakeFiles/EdgeSelection.dir/build.make CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.provides.build
.PHONY : CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.provides

CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.provides.build: CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o

# Object files for target EdgeSelection
EdgeSelection_OBJECTS = \
"CMakeFiles/EdgeSelection.dir/main.cpp.o" \
"CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o" \
"CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o"

# External object files for target EdgeSelection
EdgeSelection_EXTERNAL_OBJECTS =

EdgeSelection: CMakeFiles/EdgeSelection.dir/main.cpp.o
EdgeSelection: CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o
EdgeSelection: CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o
EdgeSelection: CMakeFiles/EdgeSelection.dir/build.make
EdgeSelection: /usr/lib/x86_64-linux-gnu/libQtGui.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libQtCore.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_system.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_thread.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libpthread.so
EdgeSelection: /usr/lib/libpcl_common.so
EdgeSelection: /usr/lib/libpcl_octree.so
EdgeSelection: /usr/lib/libOpenNI.so
EdgeSelection: /usr/lib/libvtkCommon.so.5.8.0
EdgeSelection: /usr/lib/libvtkRendering.so.5.8.0
EdgeSelection: /usr/lib/libvtkHybrid.so.5.8.0
EdgeSelection: /usr/lib/libvtkCharts.so.5.8.0
EdgeSelection: /usr/lib/libpcl_io.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
EdgeSelection: /usr/lib/libpcl_kdtree.so
EdgeSelection: /usr/lib/libpcl_search.so
EdgeSelection: /usr/lib/libpcl_sample_consensus.so
EdgeSelection: /usr/lib/libpcl_filters.so
EdgeSelection: /usr/lib/libpcl_features.so
EdgeSelection: /usr/lib/libpcl_registration.so
EdgeSelection: /usr/lib/libpcl_recognition.so
EdgeSelection: /usr/lib/libpcl_visualization.so
EdgeSelection: /usr/lib/libpcl_segmentation.so
EdgeSelection: /usr/lib/libqhull.so
EdgeSelection: /usr/lib/libpcl_surface.so
EdgeSelection: /usr/lib/libpcl_keypoints.so
EdgeSelection: /usr/lib/libpcl_tracking.so
EdgeSelection: /usr/lib/libpcl_apps.so
EdgeSelection: /usr/lib/libpcl_people.so
EdgeSelection: /usr/lib/libpcl_outofcore.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_system.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_thread.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libpthread.so
EdgeSelection: /usr/lib/libqhull.so
EdgeSelection: /usr/lib/libOpenNI.so
EdgeSelection: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
EdgeSelection: /usr/lib/libvtkCommon.so.5.8.0
EdgeSelection: /usr/lib/libvtkRendering.so.5.8.0
EdgeSelection: /usr/lib/libvtkHybrid.so.5.8.0
EdgeSelection: /usr/lib/libvtkCharts.so.5.8.0
EdgeSelection: /usr/lib/libvtkRendering.so.5.8.0
EdgeSelection: /usr/lib/libvtkGraphics.so.5.8.0
EdgeSelection: /usr/lib/libvtkHybrid.so.5.8.0
EdgeSelection: /usr/lib/libQVTK.so.5.8.0
EdgeSelection: /usr/lib/libpcl_common.so
EdgeSelection: /usr/lib/libpcl_octree.so
EdgeSelection: /usr/lib/libpcl_io.so
EdgeSelection: /usr/lib/libpcl_kdtree.so
EdgeSelection: /usr/lib/libpcl_search.so
EdgeSelection: /usr/lib/libpcl_sample_consensus.so
EdgeSelection: /usr/lib/libpcl_filters.so
EdgeSelection: /usr/lib/libpcl_features.so
EdgeSelection: /usr/lib/libpcl_registration.so
EdgeSelection: /usr/lib/libpcl_recognition.so
EdgeSelection: /usr/lib/libpcl_visualization.so
EdgeSelection: /usr/lib/libpcl_segmentation.so
EdgeSelection: /usr/lib/libpcl_surface.so
EdgeSelection: /usr/lib/libpcl_keypoints.so
EdgeSelection: /usr/lib/libpcl_tracking.so
EdgeSelection: /usr/lib/libpcl_apps.so
EdgeSelection: /usr/lib/libpcl_people.so
EdgeSelection: /usr/lib/libpcl_outofcore.so
EdgeSelection: /usr/lib/libvtkViews.so.5.8.0
EdgeSelection: /usr/lib/libvtkInfovis.so.5.8.0
EdgeSelection: /usr/lib/libvtkWidgets.so.5.8.0
EdgeSelection: /usr/lib/libvtkHybrid.so.5.8.0
EdgeSelection: /usr/lib/libvtkParallel.so.5.8.0
EdgeSelection: /usr/lib/libvtkVolumeRendering.so.5.8.0
EdgeSelection: /usr/lib/libvtkRendering.so.5.8.0
EdgeSelection: /usr/lib/libvtkGraphics.so.5.8.0
EdgeSelection: /usr/lib/libvtkImaging.so.5.8.0
EdgeSelection: /usr/lib/libvtkIO.so.5.8.0
EdgeSelection: /usr/lib/libvtkFiltering.so.5.8.0
EdgeSelection: /usr/lib/libvtkCommon.so.5.8.0
EdgeSelection: /usr/lib/libvtksys.so.5.8.0
EdgeSelection: /usr/lib/libvtkQtChart.so.5.8.0
EdgeSelection: CMakeFiles/EdgeSelection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable EdgeSelection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EdgeSelection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EdgeSelection.dir/build: EdgeSelection
.PHONY : CMakeFiles/EdgeSelection.dir/build

CMakeFiles/EdgeSelection.dir/requires: CMakeFiles/EdgeSelection.dir/main.cpp.o.requires
CMakeFiles/EdgeSelection.dir/requires: CMakeFiles/EdgeSelection.dir/mainwindow.cpp.o.requires
CMakeFiles/EdgeSelection.dir/requires: CMakeFiles/EdgeSelection.dir/moc_mainwindow.cxx.o.requires
.PHONY : CMakeFiles/EdgeSelection.dir/requires

CMakeFiles/EdgeSelection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EdgeSelection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EdgeSelection.dir/clean

CMakeFiles/EdgeSelection.dir/depend: ui_mainwindow.h
CMakeFiles/EdgeSelection.dir/depend: moc_mainwindow.cxx
	cd /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection /home/reza/Qt_Workspace/Authomatic_Edge_Selection/EdgeSelection /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build /home/reza/Qt_Workspace/Authomatic_Edge_Selection/build/CMakeFiles/EdgeSelection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EdgeSelection.dir/depend
