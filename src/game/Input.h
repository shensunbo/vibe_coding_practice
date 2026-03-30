// Input.h - Input handling system for 2D fighting game

#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>

class Input {
public:
    Input(GLFWwindow* window);
    ~Input();

    void update();
    bool isKeyPressed(int key);
    bool isKeyReleased(int key);
    bool isKeyDown(int key);

private:
    GLFWwindow* window;
    bool keys[GLFW_KEY_LAST + 1];
    bool keysPrevious[GLFW_KEY_LAST + 1];
};

#endif // INPUT_H
