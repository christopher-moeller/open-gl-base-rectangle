#pragma once

#include <GLFW/glfw3.h>
#include "Camera.h"

class AppWindow
{
private:
    GLFWwindow* glfwWindow;
    Camera* camera;
public:
    AppWindow(Camera* camera);
    ~AppWindow();

    bool Init();
    int WindowShouldClose();
    void SwapBuffers();
    void PollEvents();
    void Close();
    void ProsessInput(float deltaTime);
    void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
};
