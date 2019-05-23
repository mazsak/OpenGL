//
// Created by Mateusz on 23.05.2019.
//

#ifndef OPENGL_OBJECT_H
#define OPENGL_OBJECT_H


#include <GL/glew.h>
#include "Node.h"
#include "../mesh/Model.h"

class Object : public Node {
private:
    Model* model;

public:
    Object(unsigned int id, Node *parent, Model *model);

    void update();

    void render(Shader* shader);
};


#endif //OPENGL_OBJECT_H
