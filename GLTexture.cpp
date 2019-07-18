//
// Created by Roman Gaikov on 2019-07-12.
//

#include <SDL_image.h>
#include "GLTexture.h"
#include "GLUtils.h"

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
		printf("can't load image: %s (%s)\n", filePath, IMG_GetError());
		return false;
	}

	return CreateFromSurface(_surf);
}

bool GLTexture::CreateFromSurface(SDL_Surface *surf)
{
	glGenTextures(1, &_glTexture);
	GL_CHECK("glGenTextures")

	glBindTexture(GL_TEXTURE_2D, _glTexture);
	GL_CHECK("glBindTexture")

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
	             surf->w, surf->h, 0,
	             GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
	GL_CHECK("glTexImage2D")

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	GL_CHECK("glTexParameteri")

	return true;
}

bool GLTexture::Bind()
{
	glActiveTexture(GL_TEXTURE0);
	GL_CHECK("glActiveTexture")

	glBindTexture(GL_TEXTURE_2D, _glTexture);
	GL_CHECK("glBindTexture")

	return true;
}
