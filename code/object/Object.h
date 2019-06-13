//
// Created by Mateusz on 23.05.2019.
//

#ifndef OPENGL_OBJECT_H
#define OPENGL_OBJECT_H


#include <GL/glew.h>
#include "Node.h"
#include "../mesh/Model.h"
#include "../animate/Animation.h"

struct Box {
    glm::vec3 min;
    glm::vec3 max;

    bool operator<(const Box that) const {
        return memcmp((void *) this, (void *) &that, sizeof(Box)) > 0;
    };
};

class Object : public Node {
private:
    Model *model;
    std::vector<Animation *> animations;
    float deltaTime= 0.0f;
    float speedChangeFrame = 0.001f;
    float lastFrame= 0.0f;
    Box box;
    bool collision = false;

public:
    Object(unsigned int id, Node *parent, Model *model);

    void update(glm::vec3 positionCamera, glm::vec3 directionCamera);

    void render(Shader *shader);

    void animate();

    void addAnimation(Animation * animation);

    float getSpeedChangeFrame() const;

    void setSpeedChangeFrame(float speedChangeFrame);

    void updateAbsolutePosition();

    const Box &getBox() const;

    void setCollision(bool collision);

    bool isCollision() const;

};


#endif //OPENGL_OBJECT_H
