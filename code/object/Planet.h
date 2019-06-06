//
// Created by Mateusz on 05.06.2019.
//

#ifndef OPENGL_PLANET_H
#define OPENGL_PLANET_H


#include "Object.h"

class Planet : public Node {
private:
    char *nameFileModel;
    char *nameFileTexture;
    char *nameFileMtl;
    Model *model;
public:

    Planet(unsigned int id, Node *parent, char *nameFileModel, char *nameFileTexture, char *nameFileMtl);

    void update(glm::vec3 positionCamera, glm::vec3 directionCamera);

    void render(Shader* shader);

    char *getNameFileModel() const;

    void setNameFileModel(char *nameFileModel);

    char *getNameFileTexture() const;

    void setNameFileTexture(char *nameFileTexture);

    char *getNameFileMtl() const;

    void setNameFileMtl(char *nameFileMtl);

};


#endif //OPENGL_PLANET_H
