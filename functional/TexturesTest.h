//
// Created by Roman on 02/08/2019.
//

#ifndef SDLTEST_TEXTURESTEST_H
#define SDLTEST_TEXTURESTEST_H

#include "IFunctionalTest.h"
#include "../GLTexturesCache.h"

class TexturesTest : public IFunctionalTest
{
public:
	bool Init() override;
	void Release() override;
	void Draw() override;

private:
	GLTexturesCache textures;
	GLTexture       *t, *t2;
};


#endif //SDLTEST_TEXTURESTEST_H
