#include "Shader.h"
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const char *objectId)
{
    std::string pathPrefix = "src/shaders/";
    std::string fullVertexShaderPath = pathPrefix + objectId + "-vert.glsl";
    std::string fullFragmentShaderPath = pathPrefix + objectId + "-frag.glsl";
    
    GLuint vertexShader = this->compileShader(this->loadShaderSource(fullVertexShaderPath.c_str()).c_str(), GL_VERTEX_SHADER);
    GLuint fragmentShader = this->compileShader(this->loadShaderSource(fullFragmentShaderPath.c_str()).c_str(), GL_FRAGMENT_SHADER);
    
    
    this->shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    // Check for linking errors
    GLint success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "ERROR: Shader Program Linking Failed\n" << infoLog << std::endl;
        return;
    }

    // Delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
}

Shader::~Shader()
{
    glDeleteProgram(this->shaderProgram);
}

std::string Shader::loadShaderSource(const char *filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

GLint Shader::compileShader(const char *source, GLint shaderType) {
    
    GLuint glShader = glCreateShader(shaderType);
    glShaderSource(glShader, 1, &source, nullptr);
    glCompileShader(glShader);
    
    // Check for compilation errors
    GLint success;
    char infoLog[512];
    glGetShaderiv(glShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(glShader, 512, nullptr, infoLog);
        std::cerr << "ERROR: Vertex Shader Compilation Failed\n" << infoLog << std::endl;
        return -1;
    }
    
    return glShader;
}

void Shader::UseShaderProgram() {
    glUseProgram(this->shaderProgram);
}

void Shader::setUniform4Vec(const char *varName, glm::vec4 vec) {
    int varPos = glGetUniformLocation(this->shaderProgram, varName);
    glUniform4fv(varPos, 1, glm::value_ptr(vec));
}

void Shader::setUniform4Mat(const char *varName, glm::mat4 mat) {
    int varPos = glGetUniformLocation(this->shaderProgram, varName);
    glUniformMatrix4fv(varPos, 1, GL_FALSE, glm::value_ptr(mat));
}
