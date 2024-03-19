//
// Created by Roman Gaikov on 2019-07-12.
//

#ifndef SDLTEST_GLTEXTURE_H
#define SDLTEST_GLTEXTURE_H

#include "headers.h"
#include "BitmapData.h"

//https://community.khronos.org/t/loading-texture-using-sdl/68644

class GLTexture
{
public:
	static GLTexture *Load(const char *filePath);
	static void Free(GLTexture *t);

	bool Bind() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	GLTexture();
	virtual ~GLTexture();

	bool CreateFromFile(const char *filePath);
	bool CreateFromBitmapData(BitmapData *bmData);

private:
	std::string _idInfo;
	int _width;
	int _height;
	GLuint _glTexture;
};


#endif //SDLTEST_GLTEXTURE_H
