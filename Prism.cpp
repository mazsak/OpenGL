//
// Created by Mateusz on 10.05.2019.
//

#include <GL/glew.h>
#include <math.h>
#include "Prism.h"
#include "glm/glm/glm.hpp"


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

}

void Prism::drawPrism() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void *) 0
    );

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(
            1,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void *) 0
    );
    glDrawArrays(GL_TRIANGLES, 0, Prism::numberOfVertices * 3);
    glDisableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}