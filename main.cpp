#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>

// Demonstrate simple function usage of GLEW, GLFW and GLM

int main() {
    // Init GLFW and create window first
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return 1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window) {
        std::cout << "Window or OpenGL context creation failed\n";
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Init GLEW after creating the OpenGL context
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW\n";
        return 1;
    }

    // Verify GLM functions are linked correctly
    glm::mat4 Projection = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);

    if (GLEW_VERSION_3_0) {
        std::cout << "GLEW version 3.0 is defined!\n";
    }

    GLuint m_programID = glCreateProgram();

    if (!m_programID) {
        std::cout << "Failed to create OpenGL program\n";
        return 1;
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "Success!\n";
    return 0;
}
