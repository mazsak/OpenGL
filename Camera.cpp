//
// Created by Mateusz on 04.04.2019.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Camera.h"
#include "glm/glm/gtc/matrix_transform.hpp"

void Camera::setProjection(GLfloat angle, float width, float height, GLfloat min, GLfloat max) {
    Projection = glm::perspective(glm::radians(angle), width / height, min, max);
    mvp = Projection * View * Model;

}

void Camera::setView(const glm::vec3 &vec0, const glm::vec3 &vec1, const glm::vec3 &vec2) {
    View = glm::lookAt(
            vec0,
            vec1,
            vec2
    );
    mvp = Projection * View * Model;
}

void Camera::setModel(glm::mat4 model) {
    Model = model;
    mvp = Projection * View * Model;
}

Camera::Camera(float width, float height) {
    Projection = glm::perspective(glm::radians(45.0f), width / height, 0.1f, 100.0f);
    View = glm::lookAt(
            glm::vec3(4, 3, 4),
            glm::vec3(0, 0, 0),
            glm::vec3(0, 1, 0)
    );
    Model = glm::mat4(1.0f);
    mvp = Projection * View * Model;
}

const glm::mat4 &Camera::getMvp() const {
    return mvp;
}

void Camera::move(GLFWwindow **window) {
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();

    float deltaTime = float(currentTime - lastTime);

    float anglex = 3.14f, angley = 0.0f, anglez = 0.0f;

    glm::vec3 position = glm::vec3(0, 0, 0);
    float speed = 1.0f;

    int xpos = 0, ypos = 0, zpos = 0;

    anglex += speed * deltaTime * float(0 - xpos);
    angley += speed * deltaTime * float(0 - ypos);
    anglez += speed * deltaTime * float(0 - zpos);

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

    if (glfwGetKey(*window, GLFW_KEY_UP) == GLFW_PRESS) {
        position += direction * deltaTime * speed;
    }

    if (glfwGetKey(*window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        position -= direction * deltaTime * speed;
    }

    if (glfwGetKey(*window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        position += right * deltaTime * speed;
    }

    if (glfwGetKey(*window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        position -= right * deltaTime * speed;
    }

    glm::mat4 model = glm::translate(glm::mat4(1.0f), position);
    setModel(model);

    lastTime = currentTime;
}
