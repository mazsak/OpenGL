#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include "glm/glm/detail/type_mat4x4.hpp"

class Camera {
private:

    glm::mat4 Projection;
    glm::mat4 View;
    glm::mat4 Model;
    glm::mat4 mvp;

public:
    const glm::mat4 &getMvp() const;

    Camera(float width, float height);

    void setProjection(GLfloat angle, float width, float height, GLfloat min, GLfloat max);

    void setView(const glm::vec3 &vec0, const glm::vec3 &vec1, const glm::vec3 &vec2);

    void setModel(glm::mat4 model);

    void move(GLFWwindow **window);
};


#endif
