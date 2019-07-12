//
// Created by Roman Gaikov on 2019-07-12.
//

#ifndef SDLTEST_GLTEXTURE_H
#define SDLTEST_GLTEXTURE_H

#include <SDL2/SDL_image.h>

class GLTexture
{
public:
	GLTexture();

	virtual ~GLTexture();

	static GLTexture *LoadFromFile(const char *filePath);

private:
	SDL_Surface *_surf;

};


#endif //SDLTEST_GLTEXTURE_H
