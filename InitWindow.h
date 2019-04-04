#ifndef OPENGL_INITWINDOW_H
#define OPENGL_INITWINDOW_H

#include <GLFW/glfw3.h>
#include "Camera.h"

class InitWindow {
private:
    GLFWwindow *window;
    GLclampf red = 0.0f;
    GLclampf green = 0.0f;
    GLclampf blue = 0.0f;
    GLclampf alpha = 0.0f;
    GLuint programID;
    Camera *camera;
    GLuint MatrixID;
public:
    InitWindow(int width, int height, const char *nameWindow);

    GLFWwindow *getWindow() const;

    void setRed(GLclampf red);

    void setGreen(GLclampf green);

    void setBlue(GLclampf blue);

    void setAlpha(GLclampf alpha);

    void mainLoop();
};

#endif
