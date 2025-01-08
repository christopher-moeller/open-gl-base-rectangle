#pragma once

#include <GL/glew.h>
#include "../shaders/Shader.h"
#include "../window/Camera.h"
#include <glm/glm.hpp>
#include "../shaders/VertexBuffer.h"

class Checkerboard
{
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    Shader* shader;
    VertexBuffer vertexBuffer;
public:
    Checkerboard(/* args */);
    ~Checkerboard();
    int Setup();
    int CleanUp();
    void Draw(Camera* camera);
};
