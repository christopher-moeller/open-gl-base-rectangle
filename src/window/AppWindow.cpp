#include "AppWindow.h"
#include <iostream>
#include <GLFW/glfw3.h>

AppWindow::AppWindow(/* args */)
{
    std::cout << "App Window called" << std::endl;
}

AppWindow::~AppWindow()
{
}

// Callback to adjust viewport when the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

bool AppWindow::Init() {

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    this->glfwWindow = glfwCreateWindow(800, 600, "OpenGLApp", nullptr, nullptr);
    if (!this->glfwWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(this->glfwWindow);
    glfwSetFramebufferSizeCallback(this->glfwWindow, framebuffer_size_callback);

    return true;
}

int AppWindow::WindowShouldClose() {
    return glfwWindowShouldClose(this->glfwWindow);
}

void AppWindow::SwapBuffers() {
    glfwSwapBuffers(this->glfwWindow);
}

void AppWindow::PollEvents() {
    glfwPollEvents();
}

void AppWindow::Close() {
    glfwDestroyWindow(this->glfwWindow);
    glfwTerminate();
}
