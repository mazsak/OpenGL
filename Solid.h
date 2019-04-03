#ifndef OPENGL_SOLID_H
#define OPENGL_SOLID_H

#include <GL/gl.h>

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


#endif
