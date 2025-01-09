#include "AppWindow.h"
#include <iostream>
#include <GLFW/glfw3.h>


Camera* cachedCamera;

AppWindow::AppWindow(Camera* camera)
{
    std::cout << "App Window called" << std::endl;
    this->camera = camera;
    cachedCamera = camera;
}

AppWindow::~AppWindow()
{
}

// Callback to adjust viewport when the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    if(cachedCamera) {
        cachedCamera->UpdateWindowSize(width, height);
    }
    glViewport(0, 0, width, height);
}

void AppWindow::ProsessInput(float deltaTime) {
    if (glfwGetKey(this->glfwWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->glfwWindow, true);
        return;
    }
    
    if(glfwGetKey(this->glfwWindow, GLFW_KEY_UP) == GLFW_PRESS) {
        this->camera->ProcessKeyboard(FORWARD, deltaTime);
    }
    
    if(glfwGetKey(this->glfwWindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
        this->camera->ProcessKeyboard(BACKWARD, deltaTime);
    }
    
    if(glfwGetKey(this->glfwWindow, GLFW_KEY_LEFT) == GLFW_PRESS) {
        this->camera->ProcessKeyboard(LEFT, deltaTime);
    }
    
    if(glfwGetKey(this->glfwWindow, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        this->camera->ProcessKeyboard(RIGHT, deltaTime);
    }
    
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
