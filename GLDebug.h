//
// Created by Raman Haikou on 2019-07-22.
//

#ifndef SDLTEST_GLDEBUG_H
#define SDLTEST_GLDEBUG_H

#include "headers.h"

class GLTexture;
class GLVertexBuffer;

class GLDebug
{
public:
	static bool Init();
	static void Release();

	static void DrawSprite(GLTexture *t, float x, float y);
	static void DrawQuad(float x, float y, float width, float height);

private:
	static GLVertexBuffer *_quadBuffer;
};


#endif //SDLTEST_GLDEBUG_H
