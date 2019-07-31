//
// Created by Raman Haikou on 2019-07-22.
//

#include "GLDebug.h"
#include "GLTexture.h"
#include "GLVertexBuffer.h"

GLVertexBuffer *GLDebug::_quadBuffer = nullptr;

void GLDebug::DrawQuad(float x, float y, float width, float height)
{
	/*glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2f(x, y);

	glTexCoord2f(0, 1);
	glVertex2f(x, y + height);

	glTexCoord2f(1, 1);
	glVertex2f(x + width, y + height);

	glTexCoord2f(1, 0);
	glVertex2f(x + width, y);

	glEnd();*/

	_quadBuffer->SetPos(0, x, y, 0);
	_quadBuffer->SetPos(1, x, y + height, 0);
	_quadBuffer->SetPos(2, x + width, y + height, 0);
	_quadBuffer->SetPos(3, x + width, y, 0);
	_quadBuffer->Draw(GL_TRIANGLES);
}

void GLDebug::DrawSprite(GLTexture *t, float x, float y)
{
	t->Bind();
	DrawQuad(x, y, t->GetWidth(), t->GetHeight());
}

/*
 * 0    3
 *
 * 1    2
 *
 * triangle 1: 0 1 2
 * triangle 2: 0 2 3
 * */

bool GLDebug::Init()
{
	_quadBuffer = new GLVertexBuffer(4, 6, false);
	_quadBuffer->SetMaxDrawVertices(4);
	_quadBuffer->SetMaxDrawIndexes(6);
	_quadBuffer->SetTex(0, 0, 0);
	_quadBuffer->SetTex(1, 0, 1);
	_quadBuffer->SetTex(2, 1, 1);
	_quadBuffer->SetTex(3, 1, 0);

	_quadBuffer->SetIndex(0, 0);
	_quadBuffer->SetIndex(1, 1);
	_quadBuffer->SetIndex(2, 2);

	_quadBuffer->SetIndex(3, 0);
	_quadBuffer->SetIndex(4, 2);
	_quadBuffer->SetIndex(5, 3);

}

void GLDebug::Release()
{
	delete _quadBuffer;
}

