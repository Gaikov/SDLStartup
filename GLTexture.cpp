//
// Created by Roman Gaikov on 2019-07-12.
//

#include <SDL_image.h>
#include "GLTexture.h"

GLTexture::GLTexture() :
		_surf(nullptr),
		_glTexture(0)
{

}

GLTexture::~GLTexture()
{
	if (_surf)
	{
		SDL_FreeSurface(_surf);
	}
}

GLTexture *GLTexture::Load(const char *filePath)
{
	auto t = new GLTexture();
	if (!t->CreateFromFile(filePath))
	{
		delete t;
		return nullptr;
	}
	return t;
}

void GLTexture::Free(GLTexture *t)
{
	delete t;
}

bool GLTexture::CreateFromFile(const char *filePath)
{
	_surf = IMG_Load(filePath);
	if (!_surf)
	{
		printf("can't load image: %s\n", filePath);
		return false;
	}

	return true;
}

bool GLTexture::CreateFromSurface(SDL_Surface *surf)
{


	/* Create The Texture */
	glGenTextures(1, &_glTexture);

	/* Typical Texture Generation Using Data From The Bitmap */
	glBindTexture(GL_TEXTURE_2D, _glTexture);

	/* Generate The Texture */
	glTexImage2D(GL_TEXTURE_2D, 0, 3, _surf->w,
	             surf->h, 0, GL_RGB,
	             GL_UNSIGNED_BYTE, TextureImage[0]->pixels);
	glGetError();

	/* Linear Filtering */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;
}

return false;
}
