#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "Solid.h"
#include "InitWindow.h"
#include "Shader.h"

GLFWwindow *InitWindow::getWindow() const {
    return window;
}

void InitWindow::setRed(GLclampf red) {
    InitWindow::red = red;
    glClearColor(InitWindow::red, InitWindow::green, InitWindow::blue, InitWindow::alpha);
}

void InitWindow::setGreen(GLclampf green) {
    InitWindow::green = green;
    glClearColor(InitWindow::red, InitWindow::green, InitWindow::blue, InitWindow::alpha);
}

void InitWindow::setBlue(GLclampf blue) {
    InitWindow::blue = blue;
    glClearColor(InitWindow::red, InitWindow::green, InitWindow::blue, InitWindow::alpha);
}

void InitWindow::setAlpha(GLclampf alpha) {
    InitWindow::alpha = alpha;
    glClearColor(InitWindow::red, InitWindow::green, InitWindow::blue, InitWindow::alpha);
}

void InitWindow::mainLoop() {
    int choose = 0;
    glm::vec3 lightPos = glm::vec3(4, 4, 4);
    Model *model = new Model((char *) R"(D:\Projects\C++\CLion\OpenGL\stump.obj)",
                             (char *) R"(D:\Projects\C++\CLion\OpenGL\stump.bmp)");
    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);
        camera->move(&window);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &camera->getMvp()[0][0]);
        glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &camera->getModel()[0][0]);
        glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &camera->getView()[0][0]);
        glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
        glUniform1i(chooseID, choose);

        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
            choose = 1;
        }
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
            choose = 2;
        }
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
            choose = 3;
        }
        if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
            choose = 4;
        }
        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
            lightPos.z += 1;
        }
        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
            lightPos.z -= 1;
        }
        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
            lightPos.x += 1;
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
            lightPos.x -= 1;
        }
        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
            lightPos = glm::vec3(4, 4, 4);
        }


        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, model->getTexture());
        glUniform1i(TextureID, 0);
        model->drawModel();


        glfwSwapBuffers(InitWindow::window);
        glfwPollEvents();

    } while (glfwGetKey(InitWindow::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(InitWindow::window) == 0);

    model->clear();
    glDeleteProgram(programID);
    glDeleteVertexArrays(1, &VertexArrayID);

    glfwTerminate();
}

InitWindow::InitWindow(int width, int height, const char *nameWindow) {
    glewExperimental = true;
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    InitWindow::window = glfwCreateWindow(width, height, nameWindow, NULL, NULL);

    if (InitWindow::window == NULL) {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(InitWindow::window);
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return;
    }

    glfwSetInputMode(InitWindow::window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwPollEvents();

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    programID = LoadShaders(R"(D:\Projects\C++\CLion\OpenGL\VertexShader.cpp)",
                            R"(D:\Projects\C++\CLion\OpenGL\FragmentShader.cpp)");
    MatrixID = glGetUniformLocation(programID, "MVP");
    ViewMatrixID = glGetUniformLocation(programID, "V");
    ModelMatrixID = glGetUniformLocation(programID, "M");
    TextureID = glGetUniformLocation(programID, "myTextureSampler");
    LightID = glGetUniformLocation(programID, "LightPosition_worldspace");
    chooseID = glGetUniformLocation(programID, "choose");
    camera = new Camera(width, height);

}

