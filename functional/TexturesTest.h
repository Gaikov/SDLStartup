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
    TexturesTest();
	bool Init() override;
	void Release() override;
	void Update(float d) override;

private:
	GLTexturesCache textures;
	GLTexture       *t, *t2;
    float _angle;
};


#endif //SDLTEST_TEXTURESTEST_H
