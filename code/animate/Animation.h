//
// Created by Mateusz on 06.06.2019.
//

#ifndef OPENGL_ANIMATION_H
#define OPENGL_ANIMATION_H

#include <vector>
#include <cstring>
#include "../../glm/glm/vec3.hpp"

struct Frame {
    glm::vec3 translation;
    glm::vec3 rotation;
    glm::vec3 scale;

    bool operator<(const Frame that) const {
        return memcmp((void *) this, (void *) &that, sizeof(Frame)) > 0;
    };
};

class Animation {
private:
    std::vector<Frame> frames;
    float time = 60;
    int numberFrame = 0;
    float currentTime = 1;

public:
    Animation(int time);

    void addFrame(Frame frame);

    Frame animate();

    const std::vector<Frame> &getFrames() const;

    void setFrames(const std::vector<Frame> &frames);

    int getTime() const;

    void setTime(int time);
};


#endif //OPENGL_ANIMATION_H
