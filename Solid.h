#ifndef OPENGL_SOLID_H
#define OPENGL_SOLID_H


#include <GL/gl.h>

static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
};

static GLfloat move[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
};

class Triangle {
private:
    GLuint VertexArrayID;
    GLuint vertexBuffer;

public:
    Triangle();

    void drawTriangle();
};


#endif
