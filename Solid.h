#ifndef OPENGL_SOLID_H
#define OPENGL_SOLID_H

#include <GL/gl.h>
#include "glm/glm/glm.hpp"


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

    GLuint loadBMP_custom(const char * imagepath);
};


#endif
