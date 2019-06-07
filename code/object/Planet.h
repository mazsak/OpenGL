//
// Created by Mateusz on 05.06.2019.
//

#ifndef OPENGL_PLANET_H
#define OPENGL_PLANET_H


#include "Object.h"

class Planet : public Object {
private:
    float distance = 0.0f;
    float rotation = 0.0f;
    float time = 64.0f;

    void generateAnimation();

public:
    Planet(unsigned int id, Node *parent, Model *model, float distance, float rotation);

    float getDistance() const;

    void setDistance(float distance);

    float getTime() const;

    void setTime(float time);
};


#endif //OPENGL_PLANET_H
