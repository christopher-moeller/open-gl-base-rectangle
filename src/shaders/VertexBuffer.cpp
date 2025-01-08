#include "VertexBuffer.h"
#include <iostream>

VertexBuffer::VertexBuffer() {
    
}

VertexBuffer::~VertexBuffer() {
    
}

void VertexBuffer::SetVertices(std::vector<float> vertices) {
    this->vertices = vertices;
}

void VertexBuffer::SetIndices(std::vector<unsigned int> indices) {
    this->indices = indices;
}

void VertexBuffer::apply() {
    

    float* verticesArray = new float[vertices.size()];
    for (size_t i = 0; i < vertices.size(); ++i) {
        verticesArray[i] = vertices[i];
    }
    
    unsigned int* indicesArray = new unsigned int[indices.size()];
    for(size_t i = 0; i < indices.size(); i++) {
        indicesArray[i] = indices[i];
    }
        
    // Generate and bind a Vertex Array Object (VAO)
    glGenVertexArrays(1, &(this->VAO));
    glBindVertexArray(this->VAO);

    // Generate and bind a Vertex Buffer Object (VBO)
    glGenBuffers(1, &(this->VBO));
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), verticesArray, GL_STATIC_DRAW);

    // Generate and bind an Element Buffer Object (EBO)
    glGenBuffers(1, &(this->EBO));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indicesArray, GL_STATIC_DRAW);

    for(size_t i = 0; i<this->attributePointers.size(); i++) {
        
        VertexAttributePointer attributerPointer =  this->attributePointers[i];
        
        glVertexAttribPointer(i, attributerPointer.attributeSizePerVertex, GL_FLOAT, GL_FALSE, attributerPointer.vertextSize * sizeof(float), (void*) (i * 3 * sizeof(float)));
        glEnableVertexAttribArray(i);
        
    }

    // Unbind the VBO (the VAO and EBO should remain bound)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    delete[] indicesArray;
    delete[] verticesArray;
}

void VertexBuffer::bind() {
    glBindVertexArray(this->VAO);
}

void VertexBuffer::AddAttributePointers(GLuint attributeSizePerVertex, GLuint vertextSize) {
    VertexAttributePointer attributePointer(attributeSizePerVertex, vertextSize);
    this->attributePointers.push_back(attributePointer);
}
