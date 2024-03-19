/*
 * GLVertexBuffer.cpp
 *
 *  Created on: 12.09.2011
 *      Author: roman
 */

#include "GLVertexBuffer.h"
#include "headers.h"

GLVertexBuffer::GLVertexBuffer(int numVertices, int numIndexes, bool useColor) :
	m_numVertices(numVertices),
	m_numIndexes(numIndexes),
	m_useColor(useColor),
	m_maxDrawVertices(0),
	m_maxDrawIndexes(0)
{
	m_verts = new Vertex[m_numVertices];
	m_indexes = new unsigned short[m_numIndexes];
}

GLVertexBuffer::~GLVertexBuffer()
{
	delete [] m_verts;
	delete [] m_indexes;
}

void GLVertexBuffer::SetPos(int vertexIndex, float x, float y, float z)
{
	Vertex	*v = &m_verts[vertexIndex];
	v->x = x;
	v->y = y;
	v->z = z;
}

void GLVertexBuffer::SetColor(int vertexIndex, unsigned int color)
{
	Vertex	*v = &m_verts[vertexIndex];

	unsigned char r, g, b, a;

	a = (unsigned char)((color & 0xff000000) >> 24);

	r = (unsigned char)((color & 0x00ff0000) >> 16);
	g = (unsigned char)((color & 0x0000ff00) >> 8);
	b = (unsigned char)((color & 0x000000ff));

	v->color = r | g << 8 | b << 16 | a << 24;
}

void GLVertexBuffer::SetTex(int vertexIndex, float tu, float tv)
{
	Vertex	*v = &m_verts[vertexIndex];
	v->tu = tu;
	v->tv = tv;
}

void GLVertexBuffer::SetPosTex(int vertexIndex, float x, float y, float z, float tu, float tv)
{
	Vertex	*v = &m_verts[vertexIndex];
	v->x = x;
	v->y = y;
	v->z = z;
	v->tu = tu;
	v->tv = tv;
}

void GLVertexBuffer::SetIndex(int index, unsigned short  vertexIndex)
{
	m_indexes[index] = vertexIndex;
}

void GLVertexBuffer::SetMaxDrawIndexes(int value)
{
	m_maxDrawIndexes = value;
}

void GLVertexBuffer::SetMaxDrawVertices(int value)
{
	m_maxDrawVertices = value;
}

void GLVertexBuffer::Draw(unsigned int primitivesMode)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), m_verts);
	glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), &m_verts->tu);

	if (m_useColor)
	{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(Vertex), &m_verts->color);
	}
	else
	{
		glDisableClientState(GL_COLOR_ARRAY);
	}

	glDrawElements(primitivesMode, m_maxDrawIndexes, GL_UNSIGNED_SHORT, m_indexes);
}

