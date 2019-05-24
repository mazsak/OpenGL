//
// Created by Mateusz on 17.05.2019.
//

#ifndef OPENGL_NODE_H
#define OPENGL_NODE_H

#include <vector>
#include "../../glm/glm/glm.hpp"
#include "../../glm/glm/gtx/transform.hpp"
#include "../../glm/glm/gtc/matrix_transform.hpp"
#include "../shader/Shader.h"
#include <iostream>

class Node {
private:
    unsigned int ID;
    Node * parent;
    std::vector<Node*> children;
    glm::mat4 absolutePosition;
    glm::vec3 translation;
    glm::vec3 rotation;
    glm::vec3 scale;
    bool visible;
public:
    Node(unsigned int id, Node *parent);

    const glm::mat4 &getAbsolutePosition() const;

    void setAbsolutePosition(const glm::mat4 &absolutePosition);

    unsigned int getId() const;

    void setId(unsigned int id);

    Node *getParent() const;

    void setParent(Node *parent);

    const std::vector<Node *> &getChildren() const;

    void setChildren(const std::vector<Node *> &children);

    const glm::vec3 &getTranslation() const;

    void setTranslation(const glm::vec3 &translation);

    const glm::vec3 &getRotation() const;

    void setRotation(const glm::vec3 &rotation);

    const glm::vec3 &getScale() const;

    void setScale(const glm::vec3 &scale);

    bool isVisible() const;

    void setVisible(bool visible);

    virtual void update(glm::vec3 positionCamera, glm::vec3 directionCamera);

    virtual void render(Shader * shader);

    void addChildren(Node * children);

    void animate();

    void updateAbsolutePosition();

    glm::mat4 getRelativePosition();
};


#endif //OPENGL_NODE_H
