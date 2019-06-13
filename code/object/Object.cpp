//
// Created by Mateusz on 23.05.2019.
//

#include "Object.h"


void Object::update(glm::vec3 positionCamera, glm::vec3 directionCamera) {

    float distance = glm::distance(positionCamera, glm::vec3(getAbsolutePosition()[3].x, getAbsolutePosition()[3].y,
                                                             getAbsolutePosition()[3].z));
    float size = glm::distance(getScale() * model->getMax(), getScale() * model->getMin());

    float show = distance - size;

//    setVisible(show <= 30);

    if (isVisible()) {
        for (int i = 0; i < getChildren().size(); i++) {
            getChildren()[i]->update(positionCamera, directionCamera);
        }
    }
}

void Object::render(Shader *shader) {
    Object::animate();
    if (Object::isVisible()) {
        model->drawModel(shader);
        glUniformMatrix4fv(shader->getModelMatrixId(), 1, GL_FALSE, &Object::getAbsolutePosition()[0][0]);

        for (int i = 0; i < getChildren().size(); i++) {
            getChildren()[i]->render(shader);
        }
    }
}


void Object::animate() {

    std::cout << collision;
    if (!collision) {
        double currentTime = glfwGetTime();
        deltaTime = float(currentTime - lastFrame);

        if (deltaTime > speedChangeFrame) {
            for (int i = 0; i < animations.size(); ++i) {
                Frame frame = animations[i]->calculateFrame();

                setTranslation(frame.translation);
                setRotation(frame.rotation);
                setScale(frame.scale);
                updateAbsolutePosition();
            }

            lastFrame = currentTime;
        }
    }
}

Object::Object(unsigned int id, Node *parent, Model *model) : Node(id, parent), model(model) {
    box.min = model->getMin();
    box.max = model->getMax();
}

void Object::addAnimation(Animation *animation) {
    animations.emplace_back(animation);
}

float Object::getSpeedChangeFrame() const {
    return speedChangeFrame;
}

void Object::setSpeedChangeFrame(float speedChangeFrame) {
    Object::speedChangeFrame = speedChangeFrame;
}

void Object::updateAbsolutePosition() {
    if (getParent()) {
        setAbsolutePosition(getParent()->getAbsolutePosition() * Node::getRelativePosition());
    } else {
        setAbsolutePosition(Node::getRelativePosition());
    }

    box.max = model->getMax() + getTranslation();
    box.min = model->getMin() + getTranslation();

    glm::vec3 centerPoint = (box.max + box.min) / 2.0f;
    glm::vec3 shift = (box.max - centerPoint);

    box.max = centerPoint + shift * getScale();
    box.min = centerPoint - shift * getScale();

    for (int i = 0; i < getChildren().size(); ++i) {
        getChildren()[i]->updateAbsolutePosition();
    }
}

const Box &Object::getBox() const {
    return box;
}

void Object::setCollision(bool collision) {
    Object::collision = collision;
}

bool Object::isCollision() const {
    return collision;
}
