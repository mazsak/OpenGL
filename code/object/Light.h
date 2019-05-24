//
// Created by Mateusz on 23.05.2019.
//

#ifndef OPENGL_LIGHT_H
#define OPENGL_LIGHT_H


#include "Node.h"

class Light : public Node{
private:
    float power;
    glm::vec3 color;

public:
    Light(unsigned int id, Node *parent, float power, const glm::vec3 &color);

    void render(Shader * shader);

    float getPower() const;

    void setPower(float power);

    const glm::vec3 &getColor() const;

    void setColor(const glm::vec3 &color);

    void update(glm::vec3 positionCamera, glm::vec3 directionCamera);

};


#endif //OPENGL_LIGHT_H
