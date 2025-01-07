#include "Rectangle.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Rectangle::Rectangle(/* args */)
{
}

Rectangle::~Rectangle()
{
}

int Rectangle::Setup() {
    
    this->shader = new Shader("rectangle");
    
    // Vertex data for a rectangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // Bottom-left
         0.5f, -0.5f, 0.0f, // Bottom-right
        -0.5f,  0.5f, 0.0f, // Top-left
         0.5f,  0.5f, 0.0f  // Top-right
    };

    // Index data for two triangles
    unsigned int indices[] = {
        0, 1, 2, // First triangle
        2, 1, 3  // Second triangle
    };

    // Generate and bind a Vertex Array Object (VAO)
    glGenVertexArrays(1, &(this->VAO));
    glBindVertexArray(this->VAO);

    // Generate and bind a Vertex Buffer Object (VBO)
    glGenBuffers(1, &(this->VBO));
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Generate and bind an Element Buffer Object (EBO)
    glGenBuffers(1, &(this->EBO));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Specify the layout of the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind the VBO (the VAO and EBO should remain bound)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    return 0;
}

int Rectangle::CleanUp() {
    
    glDeleteVertexArrays(1, &(this->VAO));
    glDeleteBuffers(1, &(this->VBO));
    glDeleteBuffers(1, &(this->EBO));
    
    delete this->shader;
    
    return 0;
    
}

void Rectangle::Draw() { // TODO pass camera as object
    this->shader->UseShaderProgram();
    this->shader->setUniform4Vec("rectangleColor", this->color);
    
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
    
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    
    this->shader->setUniform4Mat("model", model);
    this->shader->setUniform4Mat("view", view);
    this->shader->setUniform4Mat("projection", projection);
    
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Rectangle::SetColor(glm::vec4 color) {
    this->color = color;
}

