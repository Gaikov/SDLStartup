//
// Created by Roman on 02/08/2019.
//

#include "TexturesTest.h"
#include "../GLDebug.h"

bool TexturesTest::Init()
{
	textures.GetResource("test.png", 0);
	t = textures.GetResource("test.png", 0);
	if (!t) {
		return false;
	}

	t2 = textures.GetResource("test2.png", 0);
	return t2 != nullptr;
}

void TexturesTest::Release()
{
	textures.ReleaseResource(t2);
	textures.ReleaseAll();
}

void TexturesTest::Draw()
{
	GLDebug::DrawSprite(t, 10, 10);
	GLDebug::DrawSprite(t2, 300, 10);
}
