#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H

#include "../../glm/glm/detail/type_mat4x4.hpp"
#include "../../glm/glm/vec3.hpp"
#include "Node.h"

class Camera : public Node{
private:

    glm::mat4 Projection;
    glm::mat4 View;
    float xpos = 0.0f, ypos = 0.0f, zpos = -4.0f;

public:

    void render(Shader * shader);

    Camera(unsigned int id, Node *parent, float width, float height);

    void setProjection(GLfloat angle, float width, float height, GLfloat min, GLfloat max);

    void setView(const glm::vec3 &vec0, const glm::vec3 &vec1, const glm::vec3 &vec2);

    void move(GLFWwindow **window);

    const glm::mat4 &getView() const;

};


#endif
