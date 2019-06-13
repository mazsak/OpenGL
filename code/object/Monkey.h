//
// Created by Mateusz on 13.06.2019.
//

#ifndef OPENGL_MONKEY_H
#define OPENGL_MONKEY_H


#include "Object.h"

enum Direction {
    UP = 0, DOWN, RIGHT, LEFT
};

class Monkey : public Object {
private:
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    float speedMonkey = 5.0f;
    Direction direction = Direction(UP);

public :
    Monkey(unsigned int id, Node *parent, Model *model);

    void move(GLFWwindow **window);

};


#endif //OPENGL_MONKEY_H
