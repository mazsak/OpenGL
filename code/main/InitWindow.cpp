#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "InitWindow.h"
#include "../shader/Shader.h"

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

    generateSolarSystem();

    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader->getProgramId());
        camera->move(&window);

//        glDisable(GL_TEXTURE_2D);
//        glActiveTexture(GL_TEXTURE0);
//        glDisable(GL_TEXTURE_2D);
//        glActiveTexture(GL_TEXTURE1);
//        glDisable(GL_TEXTURE_2D);
//        glActiveTexture(GL_TEXTURE2);

        root->update(camera->getTranslation(), camera->getRotation());
        root->render(shader);


        glfwSwapBuffers(InitWindow::window);
        glfwPollEvents();

    } while (glfwGetKey(InitWindow::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(InitWindow::window) == 0);

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

    glfwSetInputMode(InitWindow::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetInputMode(InitWindow::window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwPollEvents();

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    shader = new Shader((char *) "code/shader/VertexShaderObject.cpp",
                        (char *) "code/shader/FragmentShaderObject.cpp");

    root = new Node(counter, nullptr);
    counter++;
    sun = new Light(counter, root, 100000.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    counter++;
    camera = new Camera(counter, root, width, height);
    camera->setTranslation(glm::vec3(10, 0, 0));
    camera->setRotation(glm::vec3(0, 0, 0));
    camera->updateAbsolutePosition();
    counter++;

    sun->setTranslation(glm::vec3(0.0, 80.0, 0.0));
    sun->updateAbsolutePosition();

}

void InitWindow::generateForest(int level, Model *model, Node *parent, float size) {
    float distance = glm::pow(2, levelForest) * size;
    std::vector<glm::vec3> position;
    position.emplace_back(distance, 0, distance);
    position.emplace_back(-distance, 0, distance);
    position.emplace_back(-distance, 0, -distance);
    position.emplace_back(distance, 0, -distance);

    if (level != levelForest) {
        for (int i = 0; i < 4; i++) {
            Node *node = new Node(counter, parent);
            counter++;
            node->setTranslation(position[i]);
            node->setSize(distance * 2);
            node->updateAbsolutePosition();
            InitWindow::generateForest(level + 1, model, node, size / 2);
        }
    } else {
        for (int i = 0; i < 4; i++) {
            Object *object = new Object(counter, parent, model);
            counter++;
            object->setTranslation(position[i]);
            object->updateAbsolutePosition();
        }
    }
}

void InitWindow::generateSolarSystem() {

    Model *sunModel = new Model((char *) "models_blender/solar_system/sun/sun.obj",
                                (char *) "models_blender/solar_system/sun/sun_tex.bmp",
                                (char *) "models_blender/solar_system/sun/sun.mtl");

    Model *venusModel = new Model((char *) "models_blender/solar_system/venus/venus.obj",
                                (char *) "models_blender/solar_system/venus/venus_tex.bmp",
                                (char *) "models_blender/solar_system/venus/venus.mtl");

    Model *mercuryModel = new Model((char *) "models_blender/solar_system/mercury/mercury.obj",
                                    (char *) "models_blender/solar_system/mercury/mercury_tex.bmp",
                                    (char *) "models_blender/solar_system/mercury/mercury.mtl");

    Model *earthModel = new Model((char *) "models_blender/solar_system/earth/earth.obj",
                                  (char *) "models_blender/solar_system/earth/earth_tex.bmp",
                                  (char *) "models_blender/solar_system/earth/earth.mtl");

    Model *moonModel = new Model((char *) "models_blender/solar_system/moon/moon.obj",
                                 (char *) "models_blender/solar_system/moon/moon_earth_tex.bmp",
                                 (char *) "models_blender/solar_system/moon/moon.mtl");

    Model *marsModel = new Model((char *) "models_blender/solar_system/mars/mars.obj",
                                 (char *) "models_blender/solar_system/mars/mars_tex.bmp",
                                 (char *) "models_blender/solar_system/mars/mars.mtl");

    Model *jupiterModel = new Model((char *) "models_blender/solar_system/jupiter/jupiter.obj",
                                    (char *) "models_blender/solar_system/jupiter/jupiter_tex.bmp",
                                    (char *) "models_blender/solar_system/jupiter/jupiter.mtl");

    Model *saturnModel = new Model((char *) "models_blender/solar_system/saturn/saturn.obj",
                                    (char *) "models_blender/solar_system/saturn/saturn_tex.bmp",
                                    (char *) "models_blender/solar_system/saturn/saturn.mtl");

//    Model *ringsModel = new Model((char *) "models_blender/solar_system/rings/rings.obj",
//                                   (char *) "models_blender/solar_system/rings/rings_tex.bmp",
//                                   (char *) "models_blender/solar_system/rings/rings.mtl");

    Model *uranusModel = new Model((char *) "models_blender/solar_system/uranus/uranus.obj",
                                   (char *) "models_blender/solar_system/uranus/uranus_tex.bmp",
                                   (char *) "models_blender/solar_system/uranus/uranus.mtl");

    Model *neptuneModel = new Model((char *) "models_blender/solar_system/neptune/neptune.obj",
                                   (char *) "models_blender/solar_system/neptune/neptune_tex.bmp",
                                   (char *) "models_blender/solar_system/neptune/neptune.mtl");


//    Object *venusObject = new Object(counter, root, venusModel);
//    counter++;
//    Object *mercuryObject = new Object(counter, root, mercuryModel);
//    counter++;
    Object *earthObject = new Object(counter, root, earthModel);
    counter++;
    Object *moonObject = new Object(counter, root, moonModel);
    counter++;
    Object *sunObject = new Object(counter, root, sunModel);
    counter++;
//    Object *marsObject = new Object(counter, root, marsModel);
//    counter++;
//    Object *jupiterObject = new Object(counter, root, jupiterModel);
//    counter++;
//    Object *saturnObject = new Object(counter, root, saturnModel);
//    counter++;
//    Object *ringsObject = new Object(counter, root, ringsModel);
//    counter++;
//    Object *uranusObject = new Object(counter, root, uranusModel);
//    counter++;
//    Object *neptuneObject = new Object(counter, root, neptuneModel);
//    counter++;


//    venusObject->setTranslation(glm::vec3(50, 0, 0));
//    venusObject->updateAbsolutePosition();


//    mercuryObject->setTranslation(glm::vec3(100, 0, 0));
//    mercuryObject->updateAbsolutePosition();


    earthObject->setTranslation(glm::vec3(40, 0, 0));
    earthObject->updateAbsolutePosition();

    Animation* animation = new Animation(1024);

    Frame frame1;
    frame1.translation = glm::vec3(46, 0, 0);
    frame1.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame1.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame1);

    Frame frame2;
    frame2.translation = glm::vec3(0, 0, 46);
    frame2.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame2.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame2);

    Frame frame3;
    frame3.translation = glm::vec3(-46, 0, 0);
    frame3.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame3.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame3);

    Frame frame4;
    frame4.translation = glm::vec3(0, 0, -46);
    frame4.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame4.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame4);

    sunObject->setTranslation(glm::vec3(46, 0, 0));
    sunObject->updateAbsolutePosition();
    sunObject->addAnimation(animation);


//    marsObject->setTranslation(glm::vec3(200, 0, 0));
//    marsObject->updateAbsolutePosition();


//    jupiterObject->setTranslation(glm::vec3(250, 0, 0));
//    jupiterObject->updateAbsolutePosition();


//    saturnObject->setTranslation(glm::vec3(28, 0, 0));
//    saturnObject->updateAbsolutePosition();


//    uranusObject->setTranslation(glm::vec3(32, 0, 0));
//    uranusObject->updateAbsolutePosition();


//    neptuneObject->setTranslation(glm::vec3(36, 0, 0));
//    neptuneObject->updateAbsolutePosition();



}






