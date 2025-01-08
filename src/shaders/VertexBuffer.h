#pragma once

#include <vector>
#include <GL/glew.h>

class VertexAttributePointer
{
public:
    GLuint attributeSizePerVertex;
    GLuint vertextSize;
    VertexAttributePointer(GLuint attributeSizePerVertex, GLuint vertextSize) {
        this->attributeSizePerVertex = attributeSizePerVertex;
        this-> vertextSize = vertextSize;
    }
    ~VertexAttributePointer() {};
};

class VertexBuffer
{
private:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<VertexAttributePointer> attributePointers;
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
public:
    VertexBuffer(/* args */);
    ~VertexBuffer();
    void SetVertices(std::vector<float> vertices);
    void SetIndices(std::vector<unsigned int> indices);
    void AddAttributePointers(GLuint attributeSizePerVertex, GLuint vertextSize);
    void apply();
    void bind();
    size_t GetIndicesCount() const;
};
