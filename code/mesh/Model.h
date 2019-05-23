#ifndef OPENGL_MODEL_H
#define OPENGL_MODEL_H

#include <GL/gl.h>
#include "../../glm/glm/glm.hpp"
#include "../shader/Shader.h"
#include <iostream>
#include <vector>

class Model {
private:
    GLuint vertexbuffer;
    GLuint uvbuffer;
    GLuint normalbuffer;
    GLuint elementbuffor;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    std::vector<unsigned short> indexs;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    GLuint texture;

    bool loadModel(char *nameFileModel);

    void loadTexture(char *nameFileTexture);

    void loadMaterials(char *pathMtl);

public:
    Model(char *nameFileModel, char *nameFileTexture, char* nameFileMtl);

    void drawModel(Shader * shader);

    void clear();

    const glm::vec3 &getAmbient() const;

    const glm::vec3 &getDiffuse() const;

    const glm::vec3 &getSpecular() const;

    void setVertices(const std::vector<glm::vec3> &vertices);

    void setUvs(const std::vector<glm::vec2> &uvs);

    void setNormals(const std::vector<glm::vec3> &normals);

    GLuint getTexture() const;

};


#endif
