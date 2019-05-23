//
// Created by Mateusz on 17.05.2019.
//

#include "Node.h"

Node::Node(unsigned int id, Node *parent) : ID(id), parent(parent) {
    parent->addChildren(this);
    translation = glm::vec3(1.0, 1.0, 1.0);
    rotation = glm::vec3(1.0, 1.0, 1.0);
    scale = glm::vec3(1.0, 1.0, 1.0);
    visible = true;
    update();
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

void Node::update() {

}

void Node::render() {

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

}

glm::mat4 Node::getRelativePosition() {
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), Node::translation);
    glm::mat4 rotationX = glm::mat4(1, 0, 0, 0, 0, glm::cos(Node::rotation.x), -glm::sin(Node::rotation.x), 0, 0,
                                    glm::sin(Node::rotation.x),
                                    glm::cos(Node::rotation.x), 0, 0,
                                    0, 0, 1);
    glm::mat4 rotationY = glm::mat4(glm::cos(Node::rotation.y), 0, glm::sin(Node::rotation.y), 0, 0, 1, 0, 0,
                                    -glm::sin(Node::rotation.y), 0,
                                    glm::cos(Node::rotation.y), 0, 0,
                                    0, 0, 1);
    glm::mat4 rotationZ = glm::mat4(glm::cos(Node::rotation.z), -glm::sin(Node::rotation.z), 0, 0,
                                    glm::sin(Node::rotation.z),
                                    glm::cos(Node::rotation.z),
                                    0, 0, 0, 0, 1, 0, 0,
                                    0, 0, 1);
    glm::mat4 rotationMatrix = rotationX * rotationY * rotationZ;
    glm::mat4 scaleMatrix = glm::scale(Node::scale);
    return translationMatrix * rotationMatrix * scaleMatrix;
}
