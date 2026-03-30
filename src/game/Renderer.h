// Renderer.h - OpenGL renderer for 2D fighting game

#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool initialize(int width, int height, const char* title);
    void shutdown();
    void clear();
    void swapBuffers();
    bool shouldClose();
    void processInput();

    GLFWwindow* getWindow() const;

private:
    GLFWwindow* window;
    int width;
    int height;
};

#endif // RENDERER_H
