//
// Created by Roman Gaikov on 2019-07-12.
//

#ifndef SDLTEST_GLTEXTURE_H
#define SDLTEST_GLTEXTURE_H

#include <SDL2/SDL_image.h>

//https://community.khronos.org/t/loading-texture-using-sdl/68644

class GLTexture
{
public:
	static GLTexture *LoadFromFile(const char *filePath);
	static void Free(GLTexture *t);

private:
	GLTexture();

	virtual ~GLTexture();

private:
	SDL_Surface *_surf;
};


#endif //SDLTEST_GLTEXTURE_H
