#pragma once
#include <glm/glm.hpp>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera
{
private:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
public:
    Camera(/* args */);
    ~Camera();
    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
};
