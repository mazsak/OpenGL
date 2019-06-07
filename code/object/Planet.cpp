//
// Created by Mateusz on 05.06.2019.
//

#include "Planet.h"


void Planet::generateAnimation() {
    Animation *animation = new Animation(time);

    Frame frame4;
    frame4.translation = glm::vec3(0, 0, -distance);
    frame4.rotation = glm::vec3(0.0, rotation, 0.0);
    frame4.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame4);

    Frame frame44;
    frame44.translation = glm::vec3(distance * 0.75, 0, -distance * 0.75);
    frame44.rotation = glm::vec3(0.0, rotation, 0.0);
    frame44.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame44);

    Frame frame1;
    frame1.translation = glm::vec3(distance, 0, 0);
    frame1.rotation = glm::vec3(0.0, rotation, 0.0);
    frame1.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame1);

    Frame frame11;
    frame11.translation = glm::vec3(distance * 0.75, 0, distance * 0.75);
    frame11.rotation = glm::vec3(0.0, rotation, 0.0);
    frame11.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame11);

    Frame frame2;
    frame2.translation = glm::vec3(0, 0, distance);
    frame2.rotation = glm::vec3(0.0, rotation, 0.0);
    frame2.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame2);

    Frame frame22;
    frame22.translation = glm::vec3(-distance * 0.75, 0, distance * 0.75);
    frame22.rotation = glm::vec3(0.0, rotation, 0.0);
    frame22.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame22);

    Frame frame3;
    frame3.translation = glm::vec3(-distance, 0, 0);
    frame3.rotation = glm::vec3(0.0, rotation, 0.0);
    frame3.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame3);

    Frame frame33;
    frame33.translation = glm::vec3(-distance * 0.75, 0, -distance * 0.75);
    frame33.rotation = glm::vec3(0.0, rotation, 0.0);
    frame33.scale = glm::vec3(1.0, 1.0, 1.0);
    animation->addFrame(frame33);


    addAnimation(animation);
}

Planet::Planet(unsigned int id, Node *parent, Model *model, float distance, float rotation) : Object(id, parent, model),
                                                                                              distance(distance),
                                                                                              rotation(rotation) {
    generateAnimation();
}


float Planet::getTime() const {
    return time;
}

void Planet::setTime(float time) {
    Planet::time = time;
}

float Planet::getDistance() const {
    return distance;
}

void Planet::setDistance(float distance) {
    Planet::distance = distance;
}
