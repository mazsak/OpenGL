#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm/glm.hpp"
#include "InitWindow.h"
#include "code/shader/Shader.h"

using namespace glm;

int main() {
    int width = 1280, height = 960;
    const char *name = "First app with OpenGL";
    InitWindow *initWindow = new InitWindow(width, height, name);
    initWindow->setBlue(0.7f);
    initWindow->setGreen(0.2f);
    initWindow->setAlpha(1.0f);
    initWindow->mainLoop();
}