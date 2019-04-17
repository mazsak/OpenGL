#ifndef OPENGL_SOLID_H
#define OPENGL_SOLID_H

#include <GL/gl.h>
#include "glm/glm/glm.hpp"
#include <iostream>
#include <vector>


class Triangle {
private:
    GLuint VertexArrayID;
    GLuint vertexBuffer;
    GLfloat g_vertex_buffer_data[9] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
    };
public:
    Triangle();

    void drawTriangle();
};


class Prism {
private:
    GLuint VertexArrayID;
    GLuint vertexBuffer;
    GLuint colorBuffer;
    GLuint textureID;
    int numberOfVertices;

public:
    Prism(GLfloat point[3], GLfloat radius, GLfloat height, int numberOfVerticesBasis);

    void drawPrism();

};

class Model {
private:
    char *nameFileModel;
    char *nameFileTexture;
    GLuint vertexbuffer;
    GLuint uvbuffer;
    GLuint normalbuffer;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    GLuint Texture;

    bool loadModel();

    void loadTexture();

public:
    Model(char *nameFileModel, char *nameFileTexture);

    void drawModel();

    void clear();

    void setVertices(const std::vector<glm::vec3> &vertices);

    void setUvs(const std::vector<glm::vec2> &uvs);

    void setNormals(const std::vector<glm::vec3> &normals);

    GLuint getTexture() const;

};


#endif
