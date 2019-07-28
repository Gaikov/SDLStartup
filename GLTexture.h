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
	bool CreateFromBytes(int width, int height, ILbyte *data);

private:
	int _width;
	int _height;
	ILbyte * _data;

	GLuint  _glTexture;
};


#endif //SDLTEST_GLTEXTURE_H
