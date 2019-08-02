//
// Created by Roman on 02/08/2019.
//

#ifndef SDLTEST_VERTEXCOLORTEST_H
#define SDLTEST_VERTEXCOLORTEST_H

#include "IFunctionalTest.h"
#include "GLVertexBuffer.h"

class VertexColorTest : public IFunctionalTest
{
public:
	bool Init() override;
	void Release() override;
	void Draw() override;
private:
	GLVertexBuffer *_vb;
};


#endif //SDLTEST_VERTEXCOLORTEST_H
