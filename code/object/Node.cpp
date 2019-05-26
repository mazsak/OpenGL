//
// Created by Mateusz on 17.05.2019.
//

#include "Node.h"

Node::Node(unsigned int id, Node *parent) : ID(id), parent(parent) {
    if (parent) {
        parent->addChildren(this);
    }
    translation = glm::vec3(0.0, 0.0, 0.0);
    rotation = glm::vec3(0.0, 0.0, 0.0);
    scale = glm::vec3(1.0, 1.0, 1.0);
    visible = true;
    updateAbsolutePosition();
}

unsigned int Node::getId() const {
    return ID;
}

void Node::setId(unsigned int id) {
    ID = id;
}

Node *Node::getParent() const {
    return parent;
}

void Node::setParent(Node *parent) {
    Node::parent = parent;
}

const std::vector<Node *> &Node::getChildren() const {
    return children;
}

void Node::setChildren(const std::vector<Node *> &children) {
    Node::children = children;
}

const glm::vec3 &Node::getTranslation() const {
    return translation;
}

void Node::setTranslation(const glm::vec3 &translation) {
    Node::translation = translation;
}

const glm::vec3 &Node::getRotation() const {
    return rotation;
}

void Node::setRotation(const glm::vec3 &rotation) {
    Node::rotation = rotation;
}

const glm::vec3 &Node::getScale() const {
    return scale;
}

void Node::setScale(const glm::vec3 &scale) {
    Node::scale = scale;
}

bool Node::isVisible() const {
    return visible;
}

void Node::setVisible(bool visible) {
    Node::visible = visible;
}

void Node::update(glm::vec3 positionCamera, glm::vec3 directionCamera) {

    float distance = glm::distance(positionCamera, glm::vec3(getAbsolutePosition()[3].x, getAbsolutePosition()[3].y,
                                                             getAbsolutePosition()[3].z));

    setVisible(distance <= size * 3);

    if (isVisible()) {
        for (int i = 0; i < getChildren().size(); i++) {
            getChildren()[i]->update(positionCamera, directionCamera);
        }
    }
}

void Node::render(Shader *shader) {
    if (isVisible()) {
        for (int i = 0; i < getChildren().size(); i++) {
            getChildren()[i]->render(shader);
        }
    }
}

void Node::addChildren(Node *children) {
    Node::children.push_back(children);
}

void Node::animate() {

}

const glm::mat4 &Node::getAbsolutePosition() const {
    return absolutePosition;
}

void Node::setAbsolutePosition(const glm::mat4 &absolutePosition) {
    Node::absolutePosition = absolutePosition;
}

void Node::updateAbsolutePosition() {
    if (Node::parent) {
        Node::absolutePosition = Node::parent->getAbsolutePosition() * Node::getRelativePosition();
    } else {
        Node::absolutePosition = Node::getRelativePosition();
    }
}

glm::mat4 Node::getRelativePosition() {

    glm::mat4 modelMatrix = glm::mat4(1.0f);

    modelMatrix = glm::translate(modelMatrix, Node::translation);

    modelMatrix = glm::rotate(modelMatrix, Node::rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, Node::rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, Node::rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    modelMatrix = glm::scale(modelMatrix, Node::scale);

    return modelMatrix;
}

float Node::getSize() const {
    return size;
}

void Node::setSize(float size) {
    Node::size = size;
}
