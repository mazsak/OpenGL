#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "glm/glm/glm.hpp"
#include "InitWindow.h"

using namespace glm;

int main() {
    int width = 1366, height = 768;
    const char *name = "First app with OpenGL";
    InitWindow *initWindow = new InitWindow(width, height, name);
    initWindow->setRed(0.2f);
    initWindow->setBlue(0.2f);
    initWindow->mainLoop();
}