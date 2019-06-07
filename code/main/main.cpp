#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../glm/glm/glm.hpp"
#include "InitWindow.h"
#include "../shader/Shader.h"

using namespace glm;

int main() {
    int width = 1280, height = 960;
    const char *name = "First app with OpenGL";
    InitWindow *initWindow = new InitWindow(width, height, name);
    initWindow->setBlue(0.0f);
    initWindow->setGreen(0.0f);
    initWindow->setRed(0.0f);
    initWindow->setAlpha(1.0f);
    initWindow->mainLoop();
}