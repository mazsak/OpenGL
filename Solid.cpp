#include <map>
#include <cmath>

#include <GL/glew.h>
#include <cstring>
#include "Solid.h"
#include "Shader.h"

#define SIZE 128

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

Model::Model(char *nameFileModel, char *nameFileTexture) : nameFileModel(nameFileModel),
                                                           nameFileTexture(nameFileTexture) {
    loadModel();
    loadTexture();
}

struct PackedIndex {
    unsigned int v;
    unsigned int u;
    unsigned int n;

    bool operator<(const PackedIndex that) const {
        return memcmp((void *) this, (void *) &that, sizeof(PackedIndex)) > 0;
    };
};

bool Model::loadModel() {
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;
    char pathMtl[SIZE];


    FILE *file = fopen(nameFileModel, "r");
    if (file == NULL) {
        printf("Impossible to open the file ! Are you in the right path ? See Tutorial 1 for details\n");
        getchar();
        return false;
    }

    while (1) {

        char lineHeader[SIZE];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;


        if (strcmp(lineHeader, "v") == 0) {
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            temp_vertices.push_back(vertex);
        } else if (strcmp(lineHeader, "vt") == 0) {
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y);
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
        } else if (strcmp(lineHeader, "mtllib") == 0) {
            fscanf(file, "%s\n", pathMtl);
        } else {
            char stupidBuffer[1000];
            fgets(stupidBuffer, 1000, file);
        }

    }

    std::map<PackedIndex, unsigned short> mapIndexs;
    unsigned short index = 0;
    for (unsigned int i = 0; i < vertexIndices.size(); i++) {
        PackedIndex suspected = {vertexIndices[i], uvIndices[i], normalIndices[i]};
        std::map<PackedIndex, unsigned short>::iterator it = mapIndexs.find(suspected);

        if (it != mapIndexs.end()) {
            indexs.push_back(it->second);
        } else {
            indexs.push_back(index);
            mapIndexs[suspected] = index;
            vertices.push_back(temp_vertices[suspected.v - 1]);
            uvs.push_back(temp_uvs[suspected.u - 1]);
            normals.push_back(temp_normals[suspected.n - 1]);
            index++;
        }
    }
    fclose(file);

    loadMaterials(pathMtl);

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

    glGenBuffers(1, &normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

    glGenBuffers(1, &elementbuffor);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffor);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexs.size() * sizeof(unsigned short), &indexs[0], GL_STATIC_DRAW);

    return true;

}

void Model::loadMaterials(char *pathMtl) {
    FILE *file = fopen(pathMtl, "r");
    if (file == NULL) {
        printf("Impossible to open the file !\n");
        getchar();
        return;
    }

    while (1) {

        char lineHeader[SIZE];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;

        if (strcmp(lineHeader, "Ka") == 0) {
            fscanf(file, "%f %f %f\n", &ambient.x, &ambient.y, &ambient.z);
        } else if (strcmp(lineHeader, "Kd") == 0) {
            fscanf(file, "%f %f %f\n", &diffuse.x, &diffuse.y, &diffuse.z);
        } else if (strcmp(lineHeader, "Ks") == 0) {
            fscanf(file, "%f %f %f\n", &spectacular.x, &spectacular.y, &spectacular.z);
        } else {
            char stupidBuffer[1000];
            fgets(stupidBuffer, 1000, file);
        }

    }
    fclose(file);
}

const glm::vec3 &Model::getAmbient() const {
    return ambient;
}

const glm::vec3 &Model::getDiffuse() const {
    return diffuse;
}

const glm::vec3 &Model::getSpectacular() const {
    return spectacular;
}

void Model::drawModel() {
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void *) 0
    );

    // 2nd attribute buffer : UVs
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(
            1,
            2,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void *) 0
    );

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glVertexAttribPointer(
            2,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void *) 0
    );

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffor);

    // Draw the triangle !
    glDrawElements(GL_TRIANGLES, indexs.size(), GL_UNSIGNED_SHORT, (void *) 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
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

void Model::loadTexture() {
    unsigned char header[54];
    unsigned int dataPos;
    unsigned int width, height;
    unsigned int imageSize;
    unsigned char *data;

    FILE *file = fopen(nameFileTexture, "rb");
    if (!file) {
        printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n",
               nameFileTexture);
        getchar();
        return;
    }

    if (fread(header, 1, 54, file) != 54) {
        printf("Not a correct BMP file\n");
        fclose(file);
        return;
    }
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Not a correct BMP file\n");
        fclose(file);
        return;
    }

    if (*(int *) &(header[0x1E]) != 0) {
        printf("Not a correct BMP file\n");
        fclose(file);
        return;
    }
    if (*(int *) &(header[0x1C]) != 24) {
        printf("Not a correct BMP file\n");
        fclose(file);
        return;
    }

    dataPos = *(int *) &(header[0x0A]);
    imageSize = *(int *) &(header[0x22]);
    width = *(int *) &(header[0x12]);
    height = *(int *) &(header[0x16]);

    if (imageSize == 0)
        imageSize = width * height * 3;
    if (dataPos == 0)
        dataPos = 54;

    data = new unsigned char[imageSize];

    fread(data, 1, imageSize, file);

    fclose(file);

    glGenTextures(1, &Texture);

    glBindTexture(GL_TEXTURE_2D, Texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

    delete[] data;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);
}

GLuint Model::getTexture() const {
    return Texture;
}

void Model::clear() {
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteTextures(1, &Texture);

}

