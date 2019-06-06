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
    setTranslation(glm::vec3(0, 4, 0));
}

void Camera::move(GLFWwindow **window) {

    double currentTime = glfwGetTime();
    deltaTime = float(currentTime - lastFrame);

    float speed = speedCamera * deltaTime;

    double x, y;
    glfwGetCursorPos(*window, &x, &y);

    if (first) {
        lastMousePosition.x = x;
        lastMousePosition.y = y;
        first = false;
    }

    glm::vec2 offset = glm::vec2((x - lastMousePosition.x) * sensitivity,
                                 (lastMousePosition.y - y) * sensitivity);

    lastMousePosition.x = x;
    lastMousePosition.y = y;

    yaw += offset.x;
    pitch += offset.y;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    setRotation(glm::normalize(glm::vec3(cos(glm::radians(yaw)) * cos(glm::radians(pitch)), sin(glm::radians(pitch)),
                                         sin(glm::radians(yaw)) * cos(glm::radians(pitch)))));

    if (glfwGetKey(*window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        speed *= 12;

    if (glfwGetKey(*window, GLFW_KEY_W) == GLFW_PRESS)
        setTranslation(getTranslation() + getRotation() * speed);
    if (glfwGetKey(*window, GLFW_KEY_S) == GLFW_PRESS)
        setTranslation(getTranslation() - getRotation() * speed);
    if (glfwGetKey(*window, GLFW_KEY_D) == GLFW_PRESS)
        setTranslation(getTranslation() + glm::normalize(glm::cross(getRotation(), cameraUp)) * speed);
    if (glfwGetKey(*window, GLFW_KEY_A) == GLFW_PRESS)
        setTranslation(getTranslation() - glm::normalize(glm::cross(getRotation(), cameraUp)) * speed);


    Camera::setView(getTranslation(), getTranslation() + getRotation(), cameraUp);

    lastFrame = currentTime;
}

const glm::mat4 &Camera::getView() const {
    return View;
}

void Camera::render(Shader *shader) {
    glUniformMatrix4fv(shader->getProjectionMatrixId(), 1, GL_FALSE, &Camera::Projection[0][0]);
    glUniformMatrix4fv(shader->getViewMatrixId(), 1, GL_FALSE, &Camera::View[0][0]);
}

float Camera::getSpeedCamera() const {
    return speedCamera;
}

void Camera::setSpeedCamera(float speedCamera) {
    Camera::speedCamera = speedCamera;
}

float Camera::getSensitivity() const {
    return sensitivity;
}

void Camera::setSensitivity(float sensitivity) {
    Camera::sensitivity = sensitivity;
}
