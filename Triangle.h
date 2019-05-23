//
// Created by Mateusz on 10.05.2019.
//

#ifndef OPENGL_TRIANGLE_H
#define OPENGL_TRIANGLE_H


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


#endif //OPENGL_TRIANGLE_H
