#ifndef OPENGL_INITWINDOW_H
#define OPENGL_INITWINDOW_H

#include <GLFW/glfw3.h>
#include "../object/Camera.h"
#include "../object/Light.h"
#include "../mesh/Model.h"
#include "../object/Object.h"

class InitWindow {
private:
    GLFWwindow *window;
    GLclampf red = 0.0f;
    GLclampf green = 0.0f;
    GLclampf blue = 0.0f;
    GLclampf alpha = 0.0f;
    GLuint VertexArrayID;
    Shader *shader;
    Node *root;
    Camera *camera;
    Light *sun;
    int width;
    int height;
    int levelForest = 1;
    int counter = 0;

public:
    InitWindow(int width, int height, const char *nameWindow);

    GLFWwindow *getWindow() const;

    void setRed(GLclampf red);

    void setGreen(GLclampf green);

    void setBlue(GLclampf blue);

    void setAlpha(GLclampf alpha);

    void mainLoop();

    void generateForest(int level, Model *model, Node *parent, float size);

    void generateSolarSystem();

};

#endif
