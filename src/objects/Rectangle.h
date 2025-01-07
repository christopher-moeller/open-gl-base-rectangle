#pragma once

#include <GL/glew.h>
#include "../shaders/Shader.h"
#include <glm/glm.hpp>

class Rectangle
{
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    Shader* shader;
    glm::vec4 color;
public:
    Rectangle(/* args */);
    ~Rectangle();
    int Setup();
    int CleanUp();
    void Draw();
    void SetColor(glm::vec4 color);
};
