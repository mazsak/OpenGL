//
// Created by Mateusz on 04.04.2019.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Camera.h"
#include "glm/glm/gtx/transform.hpp"
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
    position = glm::vec3(0, 0, 0);
}

const glm::mat4 &Camera::getMvp() const {
    return mvp;
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

    anglexR += float(0 - xpos);
    angleyR += float(0 - ypos);
    anglezR += float(0 - zpos);

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

    if (glfwGetKey(*window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        position += up * deltaTime * speed;
    }

    if (glfwGetKey(*window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
        position -= up * deltaTime * speed;
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
        position = glm::vec3(0, 0, 0);
    }

    glm::mat4 translationModel = glm::translate(glm::mat4(1.0f), position);
    glm::mat4 rotationModelX = glm::mat4(1, 0, 0, 0, 0, glm::cos(anglexR), -glm::sin(anglexR), 0, 0, glm::sin(anglexR),
                                         glm::cos(anglexR), 0, 0,
                                         0, 0, 1);
    glm::mat4 rotationModelY = glm::mat4(glm::cos(angleyR), 0, glm::sin(angleyR), 0, 0, 1, 0, 0, -glm::sin(angleyR), 0,
                                         glm::cos(angleyR), 0, 0,
                                         0, 0, 1);
    glm::mat4 rotationModelZ = glm::mat4(glm::cos(anglezR), -glm::sin(anglezR), 0, 0, glm::sin(anglezR),
                                         glm::cos(anglezR),
                                         0, 0, 0, 0, 1, 0, 0,
                                         0, 0, 1);
    glm::mat4 rotationModel = rotationModelX * rotationModelY * rotationModelZ;
    glm::mat4 model = translationModel * rotationModel;
    Camera::setModel(model);

    lastTime = currentTime;
}
