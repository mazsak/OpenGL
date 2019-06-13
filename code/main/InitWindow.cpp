#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include "InitWindow.h"
#include "../shader/Shader.h"
#include "../object/Planet.h"
#include "../object/Monkey.h"
#include <typeinfo>

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

    myScene();
    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shader->getProgramId());
        camera->move(&window);
        monkeyObject->move(&window);


        root->update(camera->getTranslation(), camera->getRotation());
        root->render(shader);

        for (int i = 0; i < objects.size(); ++i) {
            for (int j = i + 1; j < objects.size(); ++j) {
                bool odp = checkCollision(objects[i], objects[j]);
                objects[i]->setCollision(odp);
                objects[j]->setCollision(odp);
            }
        }


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

    root->setScale(glm::vec3(0.25, 0.25, 0.25));
    root->updateAbsolutePosition();
    counter++;
    sun = new Light(counter, root, 10000.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    counter++;
    camera = new Camera(counter, root, width, height);
    camera->setTranslation(glm::vec3(10, 0, 0));
    camera->setRotation(glm::vec3(0, 0, 0));
    camera->updateAbsolutePosition();
    counter++;

    sun->setTranslation(glm::vec3(0.0, 40.0, 0.0));
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

    Model *venusModel = new Model((char *) "models_blender/solar_system/mars/mars.obj",
                                  (char *) "models_blender/solar_system/mars/mars_tex.bmp",
                                  (char *) "models_blender/solar_system/mars/mars.mtl");

    Model *mercuryModel = new Model((char *) "models_blender/solar_system/mercury/mercury.obj",
                                    (char *) "models_blender/solar_system/mercury/mercury_tex.bmp",
                                    (char *) "models_blender/solar_system/mercury/mercury.mtl");

    Model *earthModel = new Model((char *) "models_blender/solar_system/earth/earth.obj",
                                  (char *) "models_blender/solar_system/earth/earth_tex.bmp",
                                  (char *) "models_blender/solar_system/earth/earth.mtl");

    Model *moonModel = new Model((char *) "models_blender/solar_system/venus/venus.obj",
                                 (char *) "models_blender/solar_system/venus/venus_tex.bmp",
                                 (char *) "models_blender/solar_system/venus/venus.mtl");

    Model *marsModel = new Model((char *) "models_blender/solar_system/moon/moon.obj",
                                 (char *) "models_blender/solar_system/moon/moon_earth_tex.bmp",
                                 (char *) "models_blender/solar_system/moon/moon.mtl");

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
    Planet *venusObject = new Planet(counter, root, venusModel, 20.0f, 0.01f);
    venusObject->setTime(256);
    counter++;
    Object *moonObject = new Object(counter, root, moonModel);
    counter++;
    Planet *sunObject = new Planet(counter, root, sunModel, 46.0f, 0.1f);
    sunObject->setTime(1024);
    sunObject->setSpeedChangeFrame(0.05f);
    counter++;
    Planet *earthObject = new Planet(counter, sunObject, earthModel, 10.0f, 0.0f);
    earthObject->setTime(30);
    earthObject->setSpeedChangeFrame(0.01f);
    counter++;
    Planet *marsObject = new Planet(counter, root, marsModel, 98.0f, 0.1f);
    marsObject->setTime(1024);
    marsObject->setSpeedChangeFrame(0.05f);
    counter++;
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

void InitWindow::myScene() {
    Model *stump = new Model((char *) "models_blender/stump/stump.obj",
                             (char *) "models_blender/stump/stump.bmp",
                             (char *) "models_blender/stump/stump.mtl");


    monkeyObject = new Monkey(counter, root, stump);
    counter++;

    Object *stumpObject = new Object(counter, root, stump);
    counter++;
    Object *stumpObject1 = new Object(counter, root, stump);
    counter++;
    Object *stumpObject2 = new Object(counter, root, stump);
    counter++;

    Animation *animation = new Animation(256);

    Frame frame;
    frame.translation = glm::vec3(-4, 0, 4);
    frame.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame.scale = glm::vec3(3, 3, 3);
    animation->addFrame(frame);
    Frame frame1;
    frame1.translation = glm::vec3(8, 0, 8);
    frame1.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame1.scale = glm::vec3(3, 3, 3);
    animation->addFrame(frame1);

    stumpObject->addAnimation(animation);

    stumpObject->setTranslation(glm::vec3(-4, 0, 4));
    stumpObject->setScale(glm::vec3(3, 3, 3));
    stumpObject->updateAbsolutePosition();

    Animation *animation1 = new Animation(256);

    Frame frame11;
    frame11.translation = glm::vec3(4, 0, -4);
    frame11.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame11.scale = glm::vec3(3, 3, 3);
    animation1->addFrame(frame11);
    Frame frame12;
    frame12.translation = glm::vec3(-8, 0, -8);
    frame12.rotation = glm::vec3(0.0, 0.0, 0.0);
    frame12.scale = glm::vec3(3, 3, 3);
    animation1->addFrame(frame12);

    stumpObject1->addAnimation(animation1);

    stumpObject1->setTranslation(glm::vec3(4, 0, -4));
    stumpObject1->setScale(glm::vec3(3, 3, 3));
    stumpObject1->updateAbsolutePosition();

    stumpObject2->setTranslation(glm::vec3(4, 0, 10));
    stumpObject2->setScale(glm::vec3(3, 3, 3));
    stumpObject2->updateAbsolutePosition();

    objects.emplace_back(monkeyObject);
    objects.emplace_back(stumpObject);
    objects.emplace_back(stumpObject1);
    objects.emplace_back(stumpObject2);

}

bool InitWindow::checkCollision(Object *first, Object *second) {
    bool xAxis = (first->getBox().min.x <= second->getBox().max.x && first->getBox().max.x >= second->getBox().min.x);
    bool yAxis = (first->getBox().min.y <= second->getBox().max.y && first->getBox().max.y >= second->getBox().min.y);
    bool zAxis = (first->getBox().min.z <= second->getBox().max.z && first->getBox().max.z >= second->getBox().min.z);

    bool odp = xAxis && yAxis && zAxis;

    if(odp){
        printf("kolizja");
    }

    return odp;
}









