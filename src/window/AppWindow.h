#pragma once

#include <GLFW/glfw3.h>

class AppWindow
{
private:
    GLFWwindow* glfwWindow;
public:
    AppWindow(/* args */);
    ~AppWindow();

    bool Init();
    int WindowShouldClose();
    void SwapBuffers();
    void PollEvents();
    void Close();
};
