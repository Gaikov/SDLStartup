#include "headers.h"
#include "GLTexture.h"
#include "GLUtils.h"
#include "GLDebug.h"
#include "linmath.h"
#include "GLTexturesCache.h"

#define WIDTH 640
#define HEIGHT 480

int main(int argv, char **args)
{
	printf("...running\n");
	SDL_Window *window;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 0);

	window = SDL_CreateWindow("SDL2 Test",
	                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
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

	if (!GLTexturesCache::Init())
	{
		return 1;
	}


	GLTexture *t = GLTexture::Load("test.png");
	if (!t) {
		return 1;
	}

	GLTexture *t2 = GLTexture::Load("test2.png");
	if (!t2) {
		return 1;
	}

	glClearColor(0.6, 0.6, 0.6, 1);
	mat4x4 proj;
	mat4x4_ortho(proj, 0, WIDTH, HEIGHT, 0, -1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf((float*)proj);
	glMatrixMode(GL_MODELVIEW);

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

		glEnable(GL_TEXTURE_2D);
		t->Bind();
		//t2->Bind();

		glColor3f(1, 1, 1);

		GLDebug::DrawQuad(100, 100, t2->GetWidth(), t2->GetHeight());

		glFlush();
		SDL_GL_SwapWindow(window);
	}

	GLTexture::Free(t);

	GLTexturesCache::Release();
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}