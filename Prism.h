//
// Created by Mateusz on 10.05.2019.
//

#ifndef OPENGL_PRISM_H
#define OPENGL_PRISM_H


#include <GL/gl.h>

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


#endif //OPENGL_PRISM_H
