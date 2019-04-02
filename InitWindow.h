//
// Created by Mateusz on 02.04.2019.
//

#ifndef OPENGL_INITWINDOW_H
#define OPENGL_INITWINDOW_H

#include <GLFW/glfw3.h>

class InitWindow {
private:
    GLFWwindow *window;
    GLclampf red;
    GLclampf green;
    GLclampf blue;
    GLclampf alpha;
public:
    InitWindow(int width, int height, const char *nameWindow, GLFWmonitor *monitor, GLFWwindow *share);

    GLFWwindow* getWindow();

    void setBackground(GLclampf read, GLclampf green, GLclampf blue, GLclampf alpha);

    void mainLoop();
};

#endif
