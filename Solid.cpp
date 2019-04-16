#include <cmath>

#include <cmath>

#include <GL/glew.h>
#include <cstring>
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

Model::Model(char *nameFileModel, char *nameFileTexture) : nameFileModel(nameFileModel),
                                                           nameFileTexture(nameFileTexture) {}

bool Model::loadModel() {
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;


    FILE *file = fopen(nameFileModel, "r");
    if (file == NULL) {
        printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
        getchar();
        return false;
    }

    while (1) {

        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader

        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
        } else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
            uv.y = -uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
            temp_uvs.push_back(uv);
        } else if (strcmp(lineHeader, "vn") == 0) {
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
            temp_normals.push_back(normal);
        } else if (strcmp(lineHeader, "f") == 0) {
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2],
                                 &normalIndex[2]);
            if (matches != 9) {
                printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                fclose(file);
                return false;
            }
            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);
            uvIndices.push_back(uvIndex[0]);
            uvIndices.push_back(uvIndex[1]);
            uvIndices.push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        } else {
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000];
            fgets(stupidBuffer, 1000, file);
        }

    }

    // For each vertex of each triangle
    for (unsigned int i = 0; i < vertexIndices.size(); i++) {

        // Get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int uvIndex = uvIndices[i];
        unsigned int normalIndex = normalIndices[i];

        // Get the attributes thanks to the index
        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
        glm::vec2 uv = temp_uvs[uvIndex - 1];
        glm::vec3 normal = temp_normals[normalIndex - 1];

        // Put the attributes in buffers
        vertices.push_back(vertex);
        uvs.push_back(uv);
        normals.push_back(normal);

    }
    fclose(file);

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

    return true;

}

void Model::drawModel() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,                  // attribute
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void *) 0            // array buffer offset
    );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
            1,                                // attribute
            2,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void *) 0                          // array buffer offset
    );

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Model::setVertices(const std::vector<glm::vec3> &vertices) {
    Model::vertices = vertices;
}

void Model::setUvs(const std::vector<glm::vec2> &uvs) {
    Model::uvs = uvs;
}

void Model::setNormals(const std::vector<glm::vec3> &normals) {
    Model::normals = normals;
}

