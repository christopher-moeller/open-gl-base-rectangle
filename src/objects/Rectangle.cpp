#include "Rectangle.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Rectangle::Rectangle(/* args */)
{
}

Rectangle::~Rectangle()
{
}

int Rectangle::Setup() {
    
    this->shader = new Shader("rectangle");
    
    this->vertexBuffer.SetVertices({
        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, // Bottom-left
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom-right
        -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // Top-left
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f // Top-right
    });
    
    this->vertexBuffer.SetIndices({
        0, 1, 2, // First triangle
        2, 1, 3  // Second triangle
    });
    
    this->vertexBuffer.AddAttributePointers(3, 6);
    this->vertexBuffer.AddAttributePointers(3, 6);
    
    this->vertexBuffer.apply();
    
    return 0;
}

int Rectangle::CleanUp() {
    
    glDeleteVertexArrays(1, &(this->VAO));
    glDeleteBuffers(1, &(this->VBO));
    glDeleteBuffers(1, &(this->EBO));
    
    delete this->shader;
    
    return 0;
    
}

void Rectangle::Draw(Camera* camera) {
    this->shader->UseShaderProgram();
    
    glm::mat4 view = camera->GetViewMatrix();
    glm::mat4 projection = camera->GetProjectionMatrix();
    
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::degrees(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    this->shader->setUniform4Mat("model", model);
    this->shader->setUniform4Mat("view", view);
    this->shader->setUniform4Mat("projection", projection);
    
    this->vertexBuffer.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

