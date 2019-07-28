//
// Created by Raman Haikou on 2019-07-22.
//

#ifndef SDLTEST_GLDEBUG_H
#define SDLTEST_GLDEBUG_H

#include "headers.h"
#include "GLTexture.h"

class GLDebug
{
public:
	static void DrawSprite(GLTexture *t, float x, float y);
	static void DrawQuad(float x, float y, float width, float height);
};


#endif //SDLTEST_GLDEBUG_H
