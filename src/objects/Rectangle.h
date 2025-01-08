#pragma once

#include <GL/glew.h>
#include "../shaders/Shader.h"
#include "../window/Camera.h"
#include <glm/glm.hpp>
#include "../shaders/VertexBuffer.h"

class Rectangle
{
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    Shader* shader;
    VertexBuffer vertexBuffer;
public:
    Rectangle(/* args */);
    ~Rectangle();
    int Setup();
    int CleanUp();
    void Draw(Camera* camera);
};
