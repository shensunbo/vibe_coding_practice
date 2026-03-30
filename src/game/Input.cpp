// Input.cpp - Input handling system implementation for 2D fighting game

#include "Input.h"

Input::Input(GLFWwindow* window) : window(window) {
    // Initialize key states
    for (int i = 0; i <= GLFW_KEY_LAST; ++i) {
        keys[i] = false;
        keysPrevious[i] = false;
    }
}

Input::~Input() {
}

void Input::update() {
    // Save previous key states
    for (int i = 0; i <= GLFW_KEY_LAST; ++i) {
        keysPrevious[i] = keys[i];
    }

    // Update current key states
    for (int i = 0; i <= GLFW_KEY_LAST; ++i) {
        keys[i] = glfwGetKey(window, i) == GLFW_PRESS;
    }
}

bool Input::isKeyPressed(int key) {
    return keys[key] && !keysPrevious[key];
}

bool Input::isKeyReleased(int key) {
    return !keys[key] && keysPrevious[key];
}

bool Input::isKeyDown(int key) {
    return keys[key];
}
