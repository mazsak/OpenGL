//
// Created by Mateusz on 23.05.2019.
//

#include "Object.h"


void Object::update() {

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
