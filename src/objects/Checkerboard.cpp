#include "Checkerboard.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

Checkerboard::Checkerboard(/* args */)
{
}

Checkerboard::~Checkerboard()
{
}

int Checkerboard::Setup() {
    
    this->shader = new Shader("rectangle");
    
    int countRows = 80;
    int countColumns = 80;
    
    std::vector<float> verticies;
    std::vector<unsigned int> indices;
    
    int normalizeBy = countRows > countColumns ? countRows : countColumns;
    
    int rectangleCount = 0;
    for (int row=0; row<countRows; row++) {
        
        for (int column=0; column<countColumns; column++) {
            
            float r1 = (static_cast<float>(row) / normalizeBy) - 0.5f;
            float r2 = (static_cast<float>(row + 1) / normalizeBy) - 0.5f;
            
            float c1 = (static_cast<float>(column) / normalizeBy) - 0.5f;
            float c2 = (static_cast<float>(column + 1) / normalizeBy) - 0.5f;
            
            float colorValue = static_cast<float>((row + column) % 2);
            
            float rectangleVertices[] = {
                c1,  r1, 0.0f, colorValue, colorValue, colorValue, // Bottom-left
                c2,  r1, 0.0f, colorValue, colorValue, colorValue, // Bottom-right
                c1,  r2, 0.0f, colorValue, colorValue, colorValue, // Top-left
                c2,  r2, 0.0f, colorValue, colorValue, colorValue, // Top-right
            };
            
            for(size_t i = 0; i < 4 * 6; i++) {
                verticies.push_back(rectangleVertices[i]);
            }
            
            unsigned int startIndex = rectangleCount * 4;
            unsigned int rectangleIndices[] = {
                startIndex, startIndex + 1, startIndex + 2,
                startIndex + 2, startIndex + 1, startIndex + 3,
            };
            
            for(size_t i = 0; i < 2 * 3; i++) {
                indices.push_back(rectangleIndices[i]);
            }
            
            rectangleCount++;
            
        }
        
        
    }
    
    
    this->vertexBuffer.SetVertices(verticies);
    this->vertexBuffer.SetIndices(indices);
    
    this->vertexBuffer.AddAttributePointers(3, 6);
    this->vertexBuffer.AddAttributePointers(3, 6);
    
    this->vertexBuffer.apply();
    
    return 0;
}

int Checkerboard::CleanUp() {
    
    glDeleteVertexArrays(1, &(this->VAO));
    glDeleteBuffers(1, &(this->VBO));
    glDeleteBuffers(1, &(this->EBO));
    
    delete this->shader;
    
    return 0;
    
}

void Checkerboard::Draw(Camera* camera) {
    this->shader->UseShaderProgram();
    this->vertexBuffer.bind();
    
    glm::mat4 view = camera->GetViewMatrix();
    glm::mat4 projection = camera->GetProjectionMatrix();
    this->shader->setUniform4Mat("view", view);
    this->shader->setUniform4Mat("projection", projection);
    
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::degrees(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    this->shader->setUniform4Mat("model", model);
    
    glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(this->vertexBuffer.GetIndicesCount()), GL_UNSIGNED_INT, 0);
}

