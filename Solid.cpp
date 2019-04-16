#include <cmath>

#include <cmath>

#include <GL/glew.h>
#include <iostream>
#include "Solid.h"
#include "Shader.h"

Triangle::Triangle() {
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void Triangle::drawTriangle() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) 0            // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
}

Prism::Prism(GLfloat *point, GLfloat radius, GLfloat height, int numberOfVerticesBasis) {
    Prism::numberOfVertices = numberOfVerticesBasis * 12;
    GLfloat matrix[numberOfVertices * 3];
    GLfloat matrixColor[numberOfVertices * 3];

    float angle = M_PI * 2 / (numberOfVerticesBasis);
    GLfloat vertices[numberOfVerticesBasis][2];

    for (int i = 0; i < numberOfVerticesBasis; i++) {
        vertices[i][0] = radius * glm::cos(angle * i);
        vertices[i][1] = radius * glm::sin(angle * i);
    }

    int counter = 0;
    //basis up
    for (int i = 0; i < numberOfVerticesBasis; i++) {
        matrixColor[counter] = 1.0f;
        matrix[counter++] = point[0];
        matrixColor[counter] = 0.0f;
        matrix[counter++] = point[1];
        matrixColor[counter] = 1.0f;
        matrix[counter++] = point[2];

        matrixColor[counter] = 1.0f;
        matrix[counter++] = vertices[i][0];
        matrixColor[counter] = 0.0f;
        matrix[counter++] = point[1];
        matrixColor[counter] = 1.0f;
        matrix[counter++] = vertices[i][1];

        if (i + 1 < numberOfVerticesBasis) {
            matrixColor[counter] = 1.0f;
            matrix[counter++] = vertices[i + 1][0];
            matrixColor[counter] = 0.0f;
            matrix[counter++] = point[1];
            matrixColor[counter] = 1.0f;
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrixColor[counter] = 1.0f;
            matrix[counter++] = vertices[0][0];
            matrixColor[counter] = 0.0f;
            matrix[counter++] = point[1];
            matrixColor[counter] = 1.0f;
            matrix[counter++] = vertices[0][1];
        }
    }

    //basis down
    for (int i = 0; i < numberOfVerticesBasis; i++) {
        matrixColor[counter] = 0.0f;
        matrix[counter++] = point[0];
        matrixColor[counter] = 1.0f;
        matrix[counter++] = point[1] - height;
        matrixColor[counter] = 0.0f;
        matrix[counter++] = point[2];

        matrixColor[counter] = 0.0f;
        matrix[counter++] = vertices[i][0];
        matrixColor[counter] = 1.0f;
        matrix[counter++] = point[1] - height;
        matrixColor[counter] = 0.0f;
        matrix[counter++] = vertices[i][1];

        if (i + 1 < numberOfVerticesBasis) {
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[i + 1][0];
            matrixColor[counter] = 1.0f;
            matrix[counter++] = point[1] - height;
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[0][0];
            matrixColor[counter] = 1.0f;
            matrix[counter++] = point[1] - height;
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[0][1];
        }
    }

    for (int i = 0; i < numberOfVerticesBasis; i++) {
        //up triangle
        matrixColor[counter] = 0.8f;
        matrix[counter++] = vertices[i][0];
        matrixColor[counter] = 0.5f;
        matrix[counter++] = point[1];
        matrixColor[counter] = 0.0f;
        matrix[counter++] = vertices[i][1];

        if (i + 1 < numberOfVerticesBasis) {
            matrixColor[counter] = 0.8f;
            matrix[counter++] = vertices[i + 1][0];
            matrixColor[counter] = 0.5f;
            matrix[counter++] = point[1];
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrixColor[counter] = 0.8f;
            matrix[counter++] = vertices[0][0];
            matrixColor[counter] = 0.5f;
            matrix[counter++] = point[1];
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[0][1];
        }

        matrixColor[counter] = 0.8f;
        matrix[counter++] = vertices[i][0];
        matrixColor[counter] = 0.5f;
        matrix[counter++] = point[1] - height;
        matrixColor[counter] = 0.0f;
        matrix[counter++] = vertices[i][1];

        //down triangle
        if (i + 1 < numberOfVerticesBasis) {
            matrixColor[counter] = 0.8f;
            matrix[counter++] = vertices[i + 1][0];
            matrixColor[counter] = 0.5f;
            matrix[counter++] = point[1];
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrixColor[counter] = 0.8f;
            matrix[counter++] = vertices[0][0];
            matrixColor[counter] = 0.5f;
            matrix[counter++] = point[1];
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[0][1];
        }

        if (i + 1 < numberOfVerticesBasis) {
            matrixColor[counter] = 0.8f;
            matrix[counter++] = vertices[i + 1][0];
            matrixColor[counter] = 0.5f;
            matrix[counter++] = point[1] - height;
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrixColor[counter] = 0.8f;
            matrix[counter++] = vertices[0][0];
            matrixColor[counter] = 0.5f;
            matrix[counter++] = point[1] - height;
            matrixColor[counter] = 0.0f;
            matrix[counter++] = vertices[0][1];
        }

        matrixColor[counter] = 0.8f;
        matrix[counter++] = vertices[i][0];
        matrixColor[counter] = 0.5f;
        matrix[counter++] = point[1] - height;
        matrixColor[counter] = 0.0f;
        matrix[counter++] = vertices[i][1];

    }

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(matrix), matrix, GL_STATIC_DRAW);
    Prism::loadBMP_custom("andzik_load.bmp");
}

void Prism::drawPrism() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) 0            // array buffer offset
    );

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );
    glDrawArrays(GL_TRIANGLES, 0, Prism::numberOfVertices * 3);
    glDisableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}

GLuint Prism::loadBMP_custom(const char *imagepath) {
    unsigned char header[54]; // Each BMP file begins by a 54-bytes header
    unsigned int dataPos;     // Position in the file where the actual data begins
    unsigned int width, height;
    unsigned int imageSize;   // = width*height*3
// Actual RGB data
    unsigned char *data;

    FILE *file = fopen(imagepath, "rb");
    if (!file) {
        printf("Image could not be opened\n");
        return 0;
    }

    if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
        return false;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        printf("Not a correct BMP file\n");
        return 0;
    }

    dataPos = *(int *) &(header[0x0A]);
    imageSize = *(int *) &(header[0x22]);
    width = *(int *) &(header[0x12]);
    height = *(int *) &(header[0x16]);

    if (imageSize == 0) imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos == 0) dataPos = 54; // The BMP header is done that way

    data = new unsigned char[imageSize];

// Read the actual data from the file into the buffer
    fread(data, 1, imageSize, file);

//Everything is in memory now, the file can be closed
    fclose(file);

    glGenTextures(1, &textureID);

// "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);

// Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}
