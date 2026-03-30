// Renderer.cpp - OpenGL renderer implementation for 2D fighting game

#include "Renderer.h"

Renderer::Renderer() : window(nullptr), width(0), height(0) {
}

Renderer::~Renderer() {
    shutdown();
}

bool Renderer::initialize(int width, int height, const char* title) {
    this->width = width;
    this->height = height;

    // Initialize GLFW
    if (!glfwInit()) {
        return false;
    }

    // Create window
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return false;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return false;
    }

    // Set up orthographic projection for 2D
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);

    return true;
}

void Renderer::shutdown() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Renderer::swapBuffers() {
    glfwSwapBuffers(window);
}

bool Renderer::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Renderer::processInput() {
    glfwPollEvents();
}

GLFWwindow* Renderer::getWindow() const {
    return window;
}
