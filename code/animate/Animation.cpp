//
// Created by Mateusz on 06.06.2019.
//

#include <cstdio>
#include <iostream>
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

Frame Animation::calculateFrame() {
    Frame currentFrame;

    int nextNumberFrame = numberFrame + 1;
    if (frames.size() == nextNumberFrame) {
        nextNumberFrame = 0;
    }

    glm::vec3 differenceTranslation = frames[nextNumberFrame].translation - frames[numberFrame].translation;
    glm::vec3 differenceScale = frames[nextNumberFrame].rotation - frames[numberFrame].rotation;

    currentFrame.translation = frames[numberFrame].translation + differenceTranslation * (currentTime / time);
    currentFrame.rotation = frames[numberFrame].rotation * (numberFrame*time + currentTime);
    currentFrame.scale = frames[numberFrame].scale + differenceScale * (currentTime / time);

    if (currentTime == time) {
        numberFrame++;
        if (frames.size() == numberFrame) {
            numberFrame = 0;
        }
        currentTime = 1;
    } else
        currentTime++;

    return currentFrame;
}


