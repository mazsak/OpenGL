//
// Created by Mateusz on 23.05.2019.
//

#include <GL/glew.h>
#include "Light.h"

void Light::render(Shader *shader) {
    if(isVisible()) {
        glUniform3f(shader->getLightPositionId(), Light::getTranslation().x, Light::getTranslation().y,
                    Light::getTranslation().z);
        glUniform3f(shader->getLightColorId(), Light::getColor().x, Light::getColor().y, Light::getColor().z);
        glUniform1f(shader->getLightPowerId(), Light::getPower());
    }

}

Light::Light(unsigned int id, Node *parent, float power, const glm::vec3 &color) : Node(id, parent), power(power),
                                                                                   color(color) {}

float Light::getPower() const {
    return power;
}

void Light::setPower(float power) {
    Light::power = power;
}

const glm::vec3 &Light::getColor() const {
    return color;
}

void Light::setColor(const glm::vec3 &color) {
    Light::color = color;
}

void Light::update(glm::vec3 positionCamera, glm::vec3 directionCamera){
    setVisible(true);
}
