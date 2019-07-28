//
// Created by Roman Gaikov on 2019-07-12.
//

#include "GLTexture.h"
#include "GLUtils.h"
#include "TextureUtils.h"

GLTexture::GLTexture() :
		_glTexture(0),
		_width(1),
		_height(1)
{

}

GLTexture::~GLTexture()
{
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
	printf("...loading texture: %s\n", filePath);
	auto image = ilGenImage();
	IMAGE_CHECK("ilGenImage")
	ilBindImage(image);
	IMAGE_CHECK("ilBindimage")
	ilLoadImage(filePath);
	IMAGE_CHECK("ilLoadImage")

	auto w = ilGetInteger(IL_IMAGE_WIDTH);
	auto h = ilGetInteger(IL_IMAGE_HEIGHT);
	ilSetInteger(IL_IMAGE_FORMAT, IL_RGBA);
	IMAGE_CHECK("IL_IMAGE_FORMAT")

	auto data = ilGetData();
	IMAGE_CHECK("ilGetData")

	return CreateFromBytes(w, h, data);
}

bool GLTexture::CreateFromBytes(int width, int height, void *data)
{
	_width = width;
	_height = height;

	glGenTextures(1, &_glTexture);
	GL_CHECK("glGenTextures")

	glBindTexture(GL_TEXTURE_2D, _glTexture);
	GL_CHECK("glBindTexture")

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
	             width, height, 0,
	             GL_BGRA, GL_UNSIGNED_BYTE, data);
	GL_CHECK("glTexImage2D")

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	GL_CHECK("glTexParameteri")

	return true;
}

bool GLTexture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, _glTexture);
	GL_CHECK("glBindTexture")

	return true;
}

int GLTexture::GetWidth()
{
	return _width;
}

int GLTexture::GetHeight()
{
	return _height;
}
