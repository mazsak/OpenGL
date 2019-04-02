#include "InitWindow.h"
#include <cstdio>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

InitWindow::InitWindow(int width, int height, const char *nameWindow, GLFWmonitor *monitor, GLFWwindow *share) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, nameWindow, monitor, share);

    if (window == NULL) {
        fprintf(stderr,"Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

GLFWwindow* InitWindow::getWindow() {
    return window;
}

void InitWindow::setBackground(GLclampf read, GLclampf green, GLclampf blue, GLclampf alpha) {
    glClearColor(read, green,blue,alpha);
}

void InitWindow::mainLoop() {

}
