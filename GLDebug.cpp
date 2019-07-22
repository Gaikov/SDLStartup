//
// Created by Raman Haikou on 2019-07-22.
//

#include "GLDebug.h"

void GLDebug::DrawQuad(float x, float y, float width, float height)
{
	glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2f(x, y);

	glTexCoord2f(0, 1);
	glVertex2f(x, y + height);

	glTexCoord2f(1, 1);
	glVertex2f(x + width, y + height);

	glTexCoord2f(1, 0);
	glVertex2f(x + width, y);

	glEnd();
}
