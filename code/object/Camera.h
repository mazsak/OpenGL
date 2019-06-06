#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include "../../glm/glm/detail/type_mat4x4.hpp"
#include "../../glm/glm/vec3.hpp"
#include "Node.h"

class Camera : public Node{
private:

    glm::mat4 Projection;
    glm::mat4 View;
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
    float deltaTime= 0.0f;
    float lastFrame= 0.0f;
    float speedCamera = 5.0f;
    glm::vec2 lastMousePosition;
    bool first = true;
    float sensitivity = 0.1f;
    float yaw = -90.0f;
    float pitch = 0.0f;


public:

    void render(Shader * shader);

    Camera(unsigned int id, Node *parent, float width, float height);

    void setProjection(GLfloat angle, float width, float height, GLfloat min, GLfloat max);

    void setView(const glm::vec3 &vec0, const glm::vec3 &vec1, const glm::vec3 &vec2);

    void move(GLFWwindow **window);

    const glm::mat4 &getView() const;

    float getSpeedCamera() const;

    void setSpeedCamera(float speedCamera);

    float getSensitivity() const;

    void setSensitivity(float sensitivity);

};


#endif
