#include "headers.h"
#include "GLTexture.h"
#include "GLDebug.h"
#include "linmath.h"
#include "BitmapData.h"
#include "functional/FunctionalTestRunner.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argv, char **args)
{
	printf("...running\n");
    if (!glfwInit()) {
        printf("Failed to init GLFW!\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GLFW Test", NULL, NULL);
    if (!window)
    {
        printf("Could not create window!\n");
        return -1;
    }

    glfwMakeContextCurrent(window);

	GLDebug::Init();
	if (!BitmapData::Init())
	{
		return 1;
	}
	FunctionalTestRunner testRunner;
	if (!testRunner.Init())
	{
		return 1;
	}

	glClearColor(0.6, 0.6, 0.6, 1);
	mat4x4 proj;
	mat4x4_ortho(proj, 0, WIDTH, HEIGHT, 0, -1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((float*)proj);
	glMatrixMode(GL_MODELVIEW);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_TEXTURE_2D);

		glColor3f(1, 1, 1);

		testRunner.Draw();

		glFlush();
		glfwSwapBuffers(window);
        glfwPollEvents();
	}

	testRunner.Release();
	BitmapData::Release();
	GLDebug::Release();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}