#include "headers.h"
#include "engine/Engine.h"

#define WIDTH 800
#define HEIGHT 600

double prevTime = 0;

int main(int argv, char **args) {
    printf("...running\n");
    if (!glfwInit()) {
        printf("Failed to init GLFW!\n");
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Test", nullptr, nullptr);
    if (!window) {
        printf("Could not create window!\n");
        return -1;
    }
    glfwMakeContextCurrent(window);

    prevTime = glfwGetTime();

    glfwSetWindowSizeCallback(window, [](GLFWwindow *win, int width, int height) -> void {
        prevTime = glfwGetTime();
        Engine::OnResize(width, height);
    });
    glfwSetWindowPosCallback(window, [](GLFWwindow *win, int width, int height) -> void {
        prevTime = glfwGetTime();
    });

    if (!Engine::Init()) {
        return -1;
    }
    Engine::OnResize(WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        double currTime = glfwGetTime();
        Engine::Update(float(currTime - prevTime));
        prevTime = currTime;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Engine::Release();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}