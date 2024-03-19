//
// Created by Roman on 02/08/2019.
//

#include "VertexColorTest.h"
#include "headers.h"

bool VertexColorTest::Init()
{
	_vb = new GLVertexBuffer(3, 3, true);
	_vb->SetMaxDrawIndexes(3);
	_vb->SetMaxDrawVertices(3);
	_vb->SetPos(0, 10, 10, 0);
	_vb->SetPos(1, 10, 400, 0);
	_vb->SetPos(2, 400, 10, 0);
	_vb->SetIndex(0, 0);
	_vb->SetIndex(1, 1);
	_vb->SetIndex(2, 2);

	_vb->SetColor(0, 0xff0000ff);
	_vb->SetColor(1, 0xff00ff00);
	_vb->SetColor(2, 0xffff0000);

	return true;
}

void VertexColorTest::Release()
{
	delete _vb;
}

void VertexColorTest::Update(float deltaTime)
{
	_vb->Draw(GL_TRIANGLES);
}
