#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_opengl.h>
#include "GLTexture.h"

int main(int argv, char **args)
{
	SDL_Window *window;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	window = SDL_CreateWindow("SDL2 Test",
	                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
	                          SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (!window)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (!glContext)
	{
		printf("Can't create gl context: %s\n", SDL_GetError());
		return 1;
	}

	GLTexture *t = GLTexture::LoadFromFile("text.png");
	if (!t) {
		return 1;
	}

	glClearColor(0.6, 0.6, 0.6, 1);

	bool running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);



		glBegin(GL_TRIANGLES);

		glColor3f(1, 0, 0);
		glVertex2f(0, 0.5);

		glColor3f(0, 1, 0);
		glVertex2f(0.5, -0.5);

		glColor3f(0, 0, 1);
		glVertex2f(-0.5, -0.5);
		glEnd();

		glFlush();
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}