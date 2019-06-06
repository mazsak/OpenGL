//
// Created by Mateusz on 05.06.2019.
//

#include "Planet.h"


Planet::Planet(unsigned int id, Node *parent, char *nameFileModel, char *nameFileTexture, char *nameFileMtl) :
        Node(id, parent), nameFileModel(nameFileModel), nameFileTexture(nameFileTexture), nameFileMtl(nameFileMtl) {


}

void Planet::update(glm::vec3 positionCamera, glm::vec3 directionCamera) {

    float distance = glm::distance(positionCamera, glm::vec3(getAbsolutePosition()[3].x, getAbsolutePosition()[3].y, getAbsolutePosition()[3].z));
    float size = glm::distance(getScale()*model->getMax(), getScale()*model->getMin());

    float show = distance-size;

    setVisible(show <= 30);

    if(isVisible()){
        for (int i = 0; i < getChildren().size(); i++){
            getChildren()[i]->update(positionCamera, directionCamera);
        }
    }
}

void Planet::render(Shader * shader) {
    if (Planet::isVisible()) {
        model->drawModel(shader);

        glUniformMatrix4fv(shader->getModelMatrixId(), 1, GL_FALSE, &Planet::getAbsolutePosition()[0][0]);

        for(int i = 0; i < getChildren().size(); i++){
            getChildren()[i]->render(shader);
        }
    }
}

char *Planet::getNameFileModel() const {
    return nameFileModel;
}

void Planet::setNameFileModel(char *nameFileModel) {
    Planet::nameFileModel = nameFileModel;
}

char *Planet::getNameFileTexture() const {
    return nameFileTexture;
}

void Planet::setNameFileTexture(char *nameFileTexture) {
    Planet::nameFileTexture = nameFileTexture;
}

char *Planet::getNameFileMtl() const {
    return nameFileMtl;
}

void Planet::setNameFileMtl(char *nameFileMtl) {
    Planet::nameFileMtl = nameFileMtl;
}
