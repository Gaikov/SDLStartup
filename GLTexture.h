//
// Created by Roman Gaikov on 2019-07-12.
//

#ifndef SDLTEST_GLTEXTURE_H
#define SDLTEST_GLTEXTURE_H

#include "headers.h"

//https://community.khronos.org/t/loading-texture-using-sdl/68644

class GLTexture
{
public:
	static GLTexture *Load(const char *filePath);
	static void Free(GLTexture *t);
	bool Bind();

	int GetWidth();
	int GetHeight();

private:
	GLTexture();
	virtual ~GLTexture();

	bool CreateFromFile(const char* filePath);
	bool CreateFromBytes(int width, int height, void *data);

private:
	ILint _width;
	ILint _height;

	GLuint  _glTexture;
};


#endif //SDLTEST_GLTEXTURE_H
