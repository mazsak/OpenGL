//
// Created by Mateusz on 04.04.2019.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Camera.h"
#include "../../glm/glm/gtx/transform.hpp"
#include "../../glm/glm/gtc/matrix_transform.hpp"

void Camera::setProjection(GLfloat angle, float width, float height, GLfloat min, GLfloat max) {
    Projection = glm::perspective(glm::radians(angle), width / height, min, max);
}

void Camera::setView(const glm::vec3 &vec0, const glm::vec3 &vec1, const glm::vec3 &vec2) {
    View = glm::lookAt(
            vec0,
            vec1,
            vec2
    );
}

Camera::Camera(unsigned int id, Node *parent, float width, float height) : Node(id, parent) {
    Projection = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
    View = glm::lookAt(
            glm::vec3(0, 0, 0),
            glm::vec3(0, 0, 0),
            glm::vec3(0, 1, 0)
    );
    setTranslation(glm::vec3(0, 0, 0));
}

void Camera::move(GLFWwindow **window) {
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();

    float deltaTime = float(currentTime - lastTime);

    float anglex = 3.14f, angley = 0.0f;
    float anglexR = 3.14f, angleyR = 0.0f, anglezR = 0.0f;

    float speed = 3.0f;
    float speedRotation = speed * 2;

    anglex += speed * deltaTime * float(0 - xpos);
    angley += speed * deltaTime * float(0 - ypos);

    setRotation(glm::vec3( float(0 - xpos), float(0 - ypos), float(0 - zpos)));

    glm::vec3 direction(
            cos(angley) * sin(anglex),
            sin(angley),
            cos(angley) * cos(anglex)
    );

    glm::vec3 right = glm::vec3(
            sin(anglex - 3.14f / 2.0f),
            0,
            cos(anglex - 3.14f / 2.0f)
    );

    glm::vec3 up = glm::cross(right, direction);

    //run
    if (glfwGetKey(*window, GLFW_KEY_UP) == GLFW_PRESS) {
        setTranslation(getTranslation() + direction * deltaTime * speed);
    }

    if (glfwGetKey(*window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        setTranslation(getTranslation() - direction * deltaTime * speed);
    }

    if (glfwGetKey(*window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        setTranslation(getTranslation() + right * deltaTime * speed);
    }

    if (glfwGetKey(*window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        setTranslation(getTranslation() - right * deltaTime * speed);
    }

    if (glfwGetKey(*window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        setTranslation(getTranslation() + up * deltaTime * speed);
    }

    if (glfwGetKey(*window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        setTranslation(getTranslation() - up * deltaTime * speed);
    }


    //rotation
    if (glfwGetKey(*window, GLFW_KEY_KP_8) == GLFW_PRESS) {
        xpos += speedRotation * deltaTime;
    }

    if (glfwGetKey(*window, GLFW_KEY_KP_2) == GLFW_PRESS) {
        xpos -= speedRotation * deltaTime;
    }

    if (glfwGetKey(*window, GLFW_KEY_KP_6) == GLFW_PRESS) {
        ypos += speedRotation * deltaTime;
    }

    if (glfwGetKey(*window, GLFW_KEY_KP_4) == GLFW_PRESS) {
        ypos -= speedRotation * deltaTime;
    }

    if (glfwGetKey(*window, GLFW_KEY_KP_7) == GLFW_PRESS) {
        zpos += speedRotation * deltaTime;
    }

    if (glfwGetKey(*window, GLFW_KEY_KP_9) == GLFW_PRESS) {
        zpos -= speedRotation * deltaTime;
    }

    if (glfwGetKey(*window, GLFW_KEY_Q) == GLFW_PRESS) {
        xpos = 0;
        ypos = 0;
        zpos = 0;
        setTranslation(glm::vec3(0, 0, 0));
    }

    Camera::setView(getTranslation(), getTranslation() + getRotation(), glm::vec3(0, 1, 0));

    lastTime = currentTime;
}

const glm::mat4 &Camera::getView() const {
    return View;
}

void Camera::render(Shader *shader) {
    glUniformMatrix4fv(shader->getProjectionMatrixId(), 1, GL_FALSE, &Camera::Projection[0][0]);
    glUniformMatrix4fv(shader->getViewMatrixId(), 1, GL_FALSE, &Camera::View[0][0]);
}
