#include <GL/glew.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Shader.h"

void Shader::load(char *nameFileVertex, char *nameFileFragment) {
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(nameFileVertex, std::ios::in);
    if (VertexShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    } else {
        printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n",
               nameFileVertex);
        getchar();
        return;
    }

    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(nameFileFragment, std::ios::in);
    if (FragmentShaderStream.is_open()) {
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Compile Vertex Shader
    printf("Compiling shader : %s\n", nameFileVertex);
    char const *VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    glCompileShader(VertexShaderID);

    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }

    // Compile Fragment Shader
    printf("Compiling shader : %s\n", nameFileFragment);
    char const *FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        printf("%s\n", &FragmentShaderErrorMessage[0]);
    }

    // Link the program
    printf("Linking program\n");
    programID = glCreateProgram();
    glAttachShader(programID, VertexShaderID);
    glAttachShader(programID, FragmentShaderID);
    glLinkProgram(programID);

    // Check the program
    glGetProgramiv(programID, GL_LINK_STATUS, &Result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(programID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }

    glDetachShader(programID, VertexShaderID);
    glDetachShader(programID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);


    Shader::ProjectionMatrixID = glGetUniformLocation(Shader::programID, "P");
    Shader::ViewMatrixID = glGetUniformLocation(Shader::programID, "V");
    Shader::ModelMatrixID = glGetUniformLocation(Shader::programID, "M");
    Shader::TextureID = glGetUniformLocation(Shader::programID, "myTextureSampler");
    Shader::LightPositionID = glGetUniformLocation(Shader::programID, "LightPosition_worldspace");
    Shader::DiffuseID = glGetUniformLocation(Shader::programID, "Diffuse");
    Shader::LightColorID = glGetUniformLocation(Shader::programID, "LightColor");
    Shader::LightPowerID = glGetUniformLocation(Shader::programID, "LightPower");
}

Shader::Shader(char *nameFileVertex, char *nameFileFragment) {
    Shader::load(nameFileVertex, nameFileFragment);
}

GLuint Shader::getProjectionMatrixId() const {
    return ProjectionMatrixID;
}

GLuint Shader::getViewMatrixId() const {
    return ViewMatrixID;
}

GLuint Shader::getModelMatrixId() const {
    return ModelMatrixID;
}

GLuint Shader::getLightPositionId() const {
    return LightPositionID;
}

GLuint Shader::getTextureId() const {
    return TextureID;
}

GLuint Shader::getDiffuseId() const {
    return DiffuseID;
}

GLuint Shader::getProgramId() const {
    return programID;
}

GLuint Shader::getLightColorId() const {
    return LightColorID;
}

GLuint Shader::getLightPowerId() const {
    return LightPowerID;
}

