#include "InitWindow.h"
#include <GLFW/glfw3.h>
#include <cstdio>
#include <string>

class InitWindow {
private:
    GLFWwindow *window;

public:
    InitWindow(int width, int height, const char *nameWindow, GLFWmonitor *monitor, GLFWwindow *share) {
        if (!glfwInit()) {
            fprintf(stderr, "Failed to initialize GLFW\n");
            return;
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, nameWindow, monitor, share);
    }
};
