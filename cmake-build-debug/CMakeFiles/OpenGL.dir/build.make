# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Programs\ToolboxApps\apps\CLion\ch-0\191.7141.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Programs\ToolboxApps\apps\CLion\ch-0\191.7141.37\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\C++\CLion\OpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\C++\CLion\OpenGL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL.dir/flags.make

CMakeFiles/OpenGL.dir/main.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/main.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL.dir/main.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\main.cpp.obj -c D:\Projects\C++\CLion\OpenGL\main.cpp

CMakeFiles/OpenGL.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/main.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\main.cpp > CMakeFiles\OpenGL.dir\main.cpp.i

CMakeFiles/OpenGL.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/main.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\main.cpp -o CMakeFiles\OpenGL.dir\main.cpp.s

CMakeFiles/OpenGL.dir/InitWindow.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/InitWindow.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/InitWindow.cpp.obj: ../InitWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGL.dir/InitWindow.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\InitWindow.cpp.obj -c D:\Projects\C++\CLion\OpenGL\InitWindow.cpp

CMakeFiles/OpenGL.dir/InitWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/InitWindow.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\InitWindow.cpp > CMakeFiles\OpenGL.dir\InitWindow.cpp.i

CMakeFiles/OpenGL.dir/InitWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/InitWindow.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\InitWindow.cpp -o CMakeFiles\OpenGL.dir\InitWindow.cpp.s

CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.obj: ../code/mesh/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\code\mesh\Model.cpp.obj -c D:\Projects\C++\CLion\OpenGL\code\mesh\Model.cpp

CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\code\mesh\Model.cpp > CMakeFiles\OpenGL.dir\code\mesh\Model.cpp.i

CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\code\mesh\Model.cpp -o CMakeFiles\OpenGL.dir\code\mesh\Model.cpp.s

CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.obj: ../code/shader/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\code\shader\Shader.cpp.obj -c D:\Projects\C++\CLion\OpenGL\code\shader\Shader.cpp

CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\code\shader\Shader.cpp > CMakeFiles\OpenGL.dir\code\shader\Shader.cpp.i

CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\code\shader\Shader.cpp -o CMakeFiles\OpenGL.dir\code\shader\Shader.cpp.s

CMakeFiles/OpenGL.dir/code/object/Camera.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/code/object/Camera.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/code/object/Camera.cpp.obj: ../code/object/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OpenGL.dir/code/object/Camera.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\code\object\Camera.cpp.obj -c D:\Projects\C++\CLion\OpenGL\code\object\Camera.cpp

CMakeFiles/OpenGL.dir/code/object/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/code/object/Camera.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\code\object\Camera.cpp > CMakeFiles\OpenGL.dir\code\object\Camera.cpp.i

CMakeFiles/OpenGL.dir/code/object/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/code/object/Camera.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\code\object\Camera.cpp -o CMakeFiles\OpenGL.dir\code\object\Camera.cpp.s

CMakeFiles/OpenGL.dir/Prism.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/Prism.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/Prism.cpp.obj: ../Prism.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OpenGL.dir/Prism.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\Prism.cpp.obj -c D:\Projects\C++\CLion\OpenGL\Prism.cpp

CMakeFiles/OpenGL.dir/Prism.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/Prism.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\Prism.cpp > CMakeFiles\OpenGL.dir\Prism.cpp.i

CMakeFiles/OpenGL.dir/Prism.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/Prism.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\Prism.cpp -o CMakeFiles\OpenGL.dir\Prism.cpp.s

CMakeFiles/OpenGL.dir/Triangle.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/Triangle.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/Triangle.cpp.obj: ../Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OpenGL.dir/Triangle.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\Triangle.cpp.obj -c D:\Projects\C++\CLion\OpenGL\Triangle.cpp

CMakeFiles/OpenGL.dir/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/Triangle.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\Triangle.cpp > CMakeFiles\OpenGL.dir\Triangle.cpp.i

CMakeFiles/OpenGL.dir/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/Triangle.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\Triangle.cpp -o CMakeFiles\OpenGL.dir\Triangle.cpp.s

CMakeFiles/OpenGL.dir/code/object/Node.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/code/object/Node.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/code/object/Node.cpp.obj: ../code/object/Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OpenGL.dir/code/object/Node.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\code\object\Node.cpp.obj -c D:\Projects\C++\CLion\OpenGL\code\object\Node.cpp

CMakeFiles/OpenGL.dir/code/object/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/code/object/Node.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\code\object\Node.cpp > CMakeFiles\OpenGL.dir\code\object\Node.cpp.i

CMakeFiles/OpenGL.dir/code/object/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/code/object/Node.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\code\object\Node.cpp -o CMakeFiles\OpenGL.dir\code\object\Node.cpp.s

CMakeFiles/OpenGL.dir/code/object/Object.cpp.obj: CMakeFiles/OpenGL.dir/flags.make
CMakeFiles/OpenGL.dir/code/object/Object.cpp.obj: CMakeFiles/OpenGL.dir/includes_CXX.rsp
CMakeFiles/OpenGL.dir/code/object/Object.cpp.obj: ../code/object/Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/OpenGL.dir/code/object/Object.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OpenGL.dir\code\object\Object.cpp.obj -c D:\Projects\C++\CLion\OpenGL\code\object\Object.cpp

CMakeFiles/OpenGL.dir/code/object/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL.dir/code/object/Object.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\C++\CLion\OpenGL\code\object\Object.cpp > CMakeFiles\OpenGL.dir\code\object\Object.cpp.i

CMakeFiles/OpenGL.dir/code/object/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL.dir/code/object/Object.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\C++\CLion\OpenGL\code\object\Object.cpp -o CMakeFiles\OpenGL.dir\code\object\Object.cpp.s

# Object files for target OpenGL
OpenGL_OBJECTS = \
"CMakeFiles/OpenGL.dir/main.cpp.obj" \
"CMakeFiles/OpenGL.dir/InitWindow.cpp.obj" \
"CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.obj" \
"CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.obj" \
"CMakeFiles/OpenGL.dir/code/object/Camera.cpp.obj" \
"CMakeFiles/OpenGL.dir/Prism.cpp.obj" \
"CMakeFiles/OpenGL.dir/Triangle.cpp.obj" \
"CMakeFiles/OpenGL.dir/code/object/Node.cpp.obj" \
"CMakeFiles/OpenGL.dir/code/object/Object.cpp.obj"

# External object files for target OpenGL
OpenGL_EXTERNAL_OBJECTS =

OpenGL.exe: CMakeFiles/OpenGL.dir/main.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/InitWindow.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/code/mesh/Model.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/code/shader/Shader.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/code/object/Camera.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/Prism.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/Triangle.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/code/object/Node.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/code/object/Object.cpp.obj
OpenGL.exe: CMakeFiles/OpenGL.dir/build.make
OpenGL.exe: CMakeFiles/OpenGL.dir/linklibs.rsp
OpenGL.exe: CMakeFiles/OpenGL.dir/objects1.rsp
OpenGL.exe: CMakeFiles/OpenGL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable OpenGL.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OpenGL.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL.dir/build: OpenGL.exe

.PHONY : CMakeFiles/OpenGL.dir/build

CMakeFiles/OpenGL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OpenGL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL.dir/clean

CMakeFiles/OpenGL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\C++\CLion\OpenGL D:\Projects\C++\CLion\OpenGL D:\Projects\C++\CLion\OpenGL\cmake-build-debug D:\Projects\C++\CLion\OpenGL\cmake-build-debug D:\Projects\C++\CLion\OpenGL\cmake-build-debug\CMakeFiles\OpenGL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGL.dir/depend

