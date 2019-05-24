#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "../mesh/Model.h"
#include "InitWindow.h"
#include "../shader/Shader.h"
#include "../object/Object.h"
#include "../object/Light.h"

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
    Model *stump = new Model((char *) "models_blender/stump/stump.obj",
                             (char *) "models_blender/stump/stump.bmp",
                             (char *) "models_blender/stump/stump.mtl");

    Node *root = new Node(0, nullptr);
    Light *sun = new Light(1, root, 50.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    Camera *camera = new Camera(3, root, width, height);
    Object *object = new Object(1, root, stump);
    Object *object1 = new Object(2, object, stump);
    Object *object2 = new Object(2, object1, stump);
    Object *object3 = new Object(2, object2, stump);

    sun->setTranslation(glm::vec3(4.0, 4.0, 4.0));
    sun->updateAbsolutePosition();

    object1->setTranslation(glm::vec3(4.0, 0.0, 0.0));
    object1->updateAbsolutePosition();
    object2->setTranslation(glm::vec3(4.0, 0.0, 0.0));
    object2->updateAbsolutePosition();
    object3->setTranslation(glm::vec3(4.0, 0.0, 0.0));
    object3->updateAbsolutePosition();


    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader->getProgramId());
        camera->move(&window);

        glActiveTexture(GL_TEXTURE0);


        root->update(camera->getTranslation(), camera->getRotation());
        root->render(shader);


        glfwSwapBuffers(InitWindow::window);
        glfwPollEvents();

    } while (glfwGetKey(InitWindow::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(InitWindow::window) == 0);

    stump->clear();
    glDeleteProgram(shader->getProgramId());
    glDeleteVertexArrays(1, &VertexArrayID);

    glfwTerminate();
}

InitWindow::InitWindow(int width, int height, const char *nameWindow) {
    InitWindow::width = width;
    InitWindow::height = height;
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

    shader = new Shader((char *) "code/shader/VertexShaderObject.cpp",
                        (char *) "code/shader/FragmentShaderObject.cpp");

}

