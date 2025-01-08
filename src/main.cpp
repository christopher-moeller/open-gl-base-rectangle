#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "window/AppWindow.h"
#include "objects/Rectangle.h"
#include <glm/glm.hpp>
#include "window/Camera.h"

bool initGlew() {
    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    return true;
}

int main() {
    
    Camera camera;
    AppWindow appWindow(&camera);
    
    if(!appWindow.Init()) {
        return -1;
    }

    if (!initGlew()) {
        appWindow.Close();
        return -1;
    }

    Rectangle rectangle;
    rectangle.Setup();
    
    float deltaTime = 0.0f;    // time between current frame and last frame
    float lastFrame = 0.0f;

    // Render loop
    while (!appWindow.WindowShouldClose()) {
        
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        appWindow.ProsessInput(deltaTime);
        
        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        rectangle.Draw(&camera);
        // Swap buffers and poll events
        appWindow.SwapBuffers();
        appWindow.PollEvents();
    }
    
    rectangle.CleanUp();
    appWindow.Close();
    return 0;
}
