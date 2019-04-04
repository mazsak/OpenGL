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

    float angle = 360 / (numberOfVerticesBasis * 2);
    GLfloat vertices[6][2];

    for (int i = 0; i < numberOfVerticesBasis; i++) {
        vertices[i][0] = radius * (GLfloat) std::cos(angle * i);
        vertices[i][1] = radius * (GLfloat) std::sin(angle * i);
    }

    int counter = 0;
    //basis up
    for (int i = 0; i < numberOfVerticesBasis; i++) {
        matrix[counter++] = vertices[i][0];
        matrix[counter++] = point[1];
        matrix[counter++] = vertices[i][1];
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        if (i + 1 < numberOfVerticesBasis) {
            matrix[counter++] = vertices[i + 1][0];
            matrix[counter++] = point[1];
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrix[counter++] = vertices[0][0];
            matrix[counter++] = point[1];
            matrix[counter++] = vertices[0][1];
        }
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        matrix[counter++] = point[0];
        matrix[counter++] = point[1];
        matrix[counter++] = point[2];
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
    }

    //basis down
    for (int i = 0; i < numberOfVerticesBasis; i++) {
        matrix[counter++] = vertices[i][0];
        matrix[counter++] = point[1] - height;
        matrix[counter++] = vertices[i][1];
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        if (i + 1 < numberOfVerticesBasis) {
            matrix[counter++] = vertices[i + 1][0];
            matrix[counter++] = point[1] - height;
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrix[counter++] = vertices[0][0];
            matrix[counter++] = point[1] - height;
            matrix[counter++] = vertices[0][1];
        }
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        matrix[counter++] = point[0];
        matrix[counter++] = point[1] - height;
        matrix[counter++] = point[2];
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
    }

    for (int i = 0; i < numberOfVerticesBasis; i++) {
        //up triangle
        matrix[counter++] = vertices[i][0];
        matrix[counter++] = point[1];
        matrix[counter++] = vertices[i][1];
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        if (i + 1 < numberOfVerticesBasis) {
            matrix[counter++] = vertices[i + 1][0];
            matrix[counter++] = point[1];
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrix[counter++] = vertices[0][0];
            matrix[counter++] = point[1];
            matrix[counter++] = vertices[0][1];
        }
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        matrix[counter++] = vertices[i][0];
        matrix[counter++] = point[1] - height;
        matrix[counter++] = vertices[i][1];
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        //down triangle
        matrix[counter++] = vertices[i][0];
        matrix[counter++] = point[1] - height;
        matrix[counter++] = vertices[i][1];
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        if (i + 1 < numberOfVerticesBasis) {
            matrix[counter++] = vertices[i + 1][0];
            matrix[counter++] = point[1] - height;
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrix[counter++] = vertices[0][0];
            matrix[counter++] = point[1] - height;
            matrix[counter++] = vertices[0][1];
        }
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
        if (i + 1 < numberOfVerticesBasis) {
            matrix[counter++] = vertices[i + 1][0];
            matrix[counter++] = point[1];
            matrix[counter++] = vertices[i + 1][1];
        } else {
            matrix[counter++] = vertices[0][0];
            matrix[counter++] = point[1];
            matrix[counter++] = vertices[0][1];
        }
        std::cout << matrix[counter - 3] << ", " << matrix[counter - 2] << ", " << matrix[counter - 1] << std::endl;
    }

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(matrix), matrix, GL_STATIC_DRAW);
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
    glDrawArrays(GL_TRIANGLES, 0, Prism::numberOfVertices * 3);
    glDisableVertexAttribArray(0);
}
