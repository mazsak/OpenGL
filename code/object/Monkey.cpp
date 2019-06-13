//
// Created by Mateusz on 13.06.2019.
//

#include "Monkey.h"

Monkey::Monkey(unsigned int id, Node *parent, Model *model) : Object(id, parent, model) {}

void Monkey::move(GLFWwindow **window) {
    double currentTime = glfwGetTime();
    deltaTime = float(currentTime - lastFrame);

    float speed = speedMonkey * deltaTime;

    if (glfwGetKey(*window, GLFW_KEY_KP_0) == GLFW_PRESS)
        speed *= 2;

    if (glfwGetKey(*window, GLFW_KEY_UP) == GLFW_PRESS) {
        if (isCollision() && direction != Direction(DOWN))
            setTranslation(getTranslation() - glm::vec3(speed * 2, 0,0));
        else {
            setTranslation(getTranslation() + glm::vec3(speed, 0,0));
            direction = Direction(UP);
        }
    }
    if (glfwGetKey(*window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        if (isCollision() && direction != Direction(UP))
            setTranslation(getTranslation() + glm::vec3(speed * 2, 0,0));
        else {
            setTranslation(getTranslation() - glm::vec3(speed, 0,0));
            direction = Direction(DOWN);
        }
    }
    if (glfwGetKey(*window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        if (isCollision() && direction != Direction(LEFT))
            setTranslation(getTranslation() - glm::vec3(0, 0,speed * 2));
        else {
            setTranslation(getTranslation() + glm::vec3(0, 0,speed));
            direction = Direction(RIGHT);
        }
    }
    if (glfwGetKey(*window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        if (isCollision() && direction != Direction(RIGHT))
            setTranslation(getTranslation() + glm::vec3(0, 0,speed * 2));
        else {
            setTranslation(getTranslation() - glm::vec3(0, 0,speed));
            direction = Direction(LEFT);
        }
    }

    updateAbsolutePosition();

    lastFrame = currentTime;
}