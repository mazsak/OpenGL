//
// Created by Mateusz on 23.05.2019.
//

#include "Object.h"


void Object::update(glm::vec3 positionCamera, glm::vec3 directionCamera) {

    float distance = glm::distance(positionCamera, glm::vec3(getAbsolutePosition()[3].x, getAbsolutePosition()[3].y, getAbsolutePosition()[3].z));

    setVisible(distance <= 10);

    if(isVisible()){
        for (int i = 0; i < getChildren().size(); i++){
            getChildren()[i]->update(positionCamera, directionCamera);
        }
    }
}

void Object::render(Shader * shader) {
    if (Object::isVisible()) {
        model->drawModel(shader);

        glUniformMatrix4fv(shader->getModelMatrixId(), 1, GL_FALSE, &Object::getAbsolutePosition()[0][0]);

        for(int i = 0; i < getChildren().size(); i++){
            getChildren()[i]->render(shader);
        }
    }
}

Object::Object(unsigned int id, Node *parent, Model *model) : Node(id, parent), model(model) {

}
