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
	if (_glTexture)
	{
		glDeleteTextures(1, &_glTexture);
	}
}

GLTexture *GLTexture::Load(const char *filePath)
{
	printf("...loading texture: %s\n", filePath);
	auto t = new GLTexture();
	if (!t->CreateFromFile(filePath))
	{
		delete t;
		return nullptr;
	}
	t->_idInfo = filePath;
	return t;
}

void GLTexture::Free(GLTexture *t)
{
	printf("...releasing texture: %s\n", t->_idInfo.c_str());
	delete t;
}

bool GLTexture::CreateFromFile(const char *filePath)
{
	auto data = BitmapData::LoadFromFile(filePath);
	if (!data)
	{
		return false;
	}

	auto result = CreateFromBitmapData(data);
	delete data;
	return result;
}

bool GLTexture::CreateFromBitmapData(BitmapData *bmData)
{
	_width = bmData->GetWidth();
	_height = bmData->GetHeight();

	glGenTextures(1, &_glTexture);
	GL_CHECK("glGenTextures")

	glBindTexture(GL_TEXTURE_2D, _glTexture);
	GL_CHECK("glBindTexture")

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
	             bmData->GetWidth(), bmData->GetHeight(), 0,
	             GL_RGBA, GL_UNSIGNED_BYTE, bmData->GetData());
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
