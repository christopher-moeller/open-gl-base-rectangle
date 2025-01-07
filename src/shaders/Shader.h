#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader
{
private:
    GLuint shaderProgram;
    std::string loadShaderSource(const char* filepath);
    GLint compileShader(const char* source, GLint shaderType);
public:
    Shader(const char *objectId);
    ~Shader();
    void UseShaderProgram();
    void setUniform4Vec(const char* varName, glm::vec4 vec);
    void setUniform4Mat(const char* varName, glm::mat4 mat);
};
