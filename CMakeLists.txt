cmake_minimum_required(VERSION 3.13)
project(OpenGL)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

include_directories(glew-2.1.0/include)
link_directories(glew-2.1.0/lib/Release/Win32)

include_directories(glfw-3.2.1.bin.WIN32/include)
link_directories(glfw-3.2.1.bin.WIN32/lib-mingw)

add_executable(OpenGL main.cpp InitWindow.cpp InitWindow.h code/mesh/Model.cpp code/mesh/Model.h Shader.cpp Shader.h Camera.cpp Camera.h Prism.cpp Prism.h Triangle.cpp Triangle.h code/object/Node.cpp code/object/Node.h)
target_link_libraries(OpenGL glfw3.a glew32 ${OPENGL_LIBRARIES})
