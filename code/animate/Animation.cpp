//
// Created by Mateusz on 06.06.2019.
//

#include <cstdio>
#include "Animation.h"

Animation::Animation(int time) : time(time) {}

const std::vector<Frame> &Animation::getFrames() const {
    return frames;
}

void Animation::setFrames(const std::vector<Frame> &frames) {
    Animation::frames = frames;
}

int Animation::getTime() const {
    return time;
}

void Animation::setTime(int time) {
    Animation::time = time;
}

void Animation::addFrame(Frame frame) {
    frames.emplace_back(frame);
}

Frame Animation::animate() {
    Frame currentFrame;

    int nextNumberFrame = numberFrame + 1;
    if (frames.size() == numberFrame + 1) {
        nextNumberFrame = 0;
    }

    glm::vec3 difference = frames[nextNumberFrame].translation - frames[numberFrame].translation;

    currentFrame.translation = frames[numberFrame].translation +
                               difference * (currentTime / time);
    currentFrame.rotation = frames[numberFrame].rotation +
                            (frames[nextNumberFrame].rotation) - (frames[numberFrame].rotation) * (currentTime / time);
    currentFrame.scale =
            frames[numberFrame].scale + (frames[nextNumberFrame].scale) -
            (frames[numberFrame].scale) * (currentTime / time);

    printf(" x= %f y= %f, z= %f, currentTime= %f, time= %f, numberFrame = %d, nextNumberFrame = %d \n",
           currentFrame.translation.x,
           currentFrame.translation.y, currentFrame.translation.z, currentTime, time, numberFrame, nextNumberFrame);

    printf("difference.x= %f difference.y = %f difference.z = %f\n",difference.x,difference.y,difference.z);
    currentTime++;

    if (currentFrame.translation == frames[nextNumberFrame].translation &&
        currentFrame.rotation == frames[nextNumberFrame].rotation &&
        currentFrame.scale == frames[nextNumberFrame].scale) {
        numberFrame++;
        if (frames.size() == numberFrame) {
            numberFrame = 0;
        }
        currentTime = 1;
    }

    return currentFrame;
}


