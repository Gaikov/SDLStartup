/*
 * GLVertexBuffer.h
 *
 *  Created on: 12.09.2011
 *      Author: roman
 */

#ifndef VERTEXBUFFER_H_
#define VERTEXBUFFER_H_

class GLVertexBuffer
{
public:
	GLVertexBuffer(int numVertices, int numIndexes, bool useColor);
	~GLVertexBuffer();

	void SetMaxDrawVertices(int value);
	void SetMaxDrawIndexes(int value);

	void SetPos(int vertexIndex, float x, float y, float z);
	void SetPosTex(int vertexIndex, float x, float y, float z, float tu,
			float tv);
	void SetTex(int vertexIndex, float tu, float tv);
	void SetColor(int vertexIndex, float r, float g, float b, float a);
	void SetIndex(int index, unsigned short vertexIndex);

	void Draw(unsigned int primitivesMode);

private:
	struct Vertex
	{
		float x, y, z;
		float tu, tv;
		float r, g, b, a;
	};

	Vertex *m_verts;
	unsigned short *m_indexes;

	int m_numVertices;
	int m_numIndexes;
	bool m_useColor;

	int m_maxDrawVertices;
	int m_maxDrawIndexes;
};

#endif /* VERTEXBUFFER_H_ */
