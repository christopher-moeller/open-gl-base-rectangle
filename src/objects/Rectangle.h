#include <GL/glew.h>

class Rectangle
{
private:
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    GLuint shaderProgram;
public:
    Rectangle(/* args */);
    ~Rectangle();
    int Setup();
    int CleanUp();
    void Draw();
};
