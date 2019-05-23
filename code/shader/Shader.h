//
// Created by Mateusz on 03.04.2019.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include "../../glm/glm/glm.hpp"
#include <GLFW/glfw3.h>

class Shader{
private:
    GLuint programID;
    GLuint ProjectionMatrixID;
    GLuint ViewMatrixID;
    GLuint ModelMatrixID;
    GLuint LightID;
    GLuint TextureID;
    GLuint DiffuseID;

    void load(char *nameFileVertex, char *nameFileFragment);

public:

    Shader(char *nameFileVertex, char *nameFileFragment);

    GLuint getProgramId() const;

    GLuint getProjectionMatrixId() const;

    GLuint getViewMatrixId() const;

    GLuint getModelMatrixId() const;

    GLuint getLightId() const;

    GLuint getTextureId() const;

    GLuint getDiffuseId() const;

};

#endif //OPENGL_SHADER_H
