//
// Created by Roman Gaikov on 2019-07-12.
//

#include "GLTexture.h"

GLTexture::GLTexture() :
		_surf(nullptr)
{

}

GLTexture::~GLTexture()
{
	if (_surf)
	{
		SDL_FreeSurface(_surf);
	}
}

GLTexture* GLTexture::LoadFromFile(const char *filePath)
{
	return new GLTexture();
}
