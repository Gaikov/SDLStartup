#include "headers.h"
#include "engine/Engine.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argv, char **args)
{
	printf("...running\n");
    if (!glfwInit()) {
        printf("Failed to init GLFW!\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Test", nullptr, nullptr);
    if (!window)
    {
        printf("Could not create window!\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!Engine::Init(WIDTH, HEIGHT)) {
        return -1;
    }

    double prevTime = glfwGetTime();

	while (!glfwWindowShouldClose(window))
	{
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