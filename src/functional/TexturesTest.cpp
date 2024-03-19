//
// Created by Roman on 02/08/2019.
//

#include "TexturesTest.h"
#include "GLDebug.h"
#include "GLTexture.h"

TexturesTest::TexturesTest() : _angle(0), t(nullptr), t2(nullptr) {

}

bool TexturesTest::Init() {
    textures.GetResource("test.png", 0);
    t = textures.GetResource("test.png", 0);
    if (!t) {
        return false;
    }

    t2 = textures.GetResource("test2.png", 0);
    return t2 != nullptr;
}

void TexturesTest::Release() {
    textures.ReleaseResource(t2);
    textures.ReleaseAll();
}

void TexturesTest::Update(float deltaTime) {

    glLoadIdentity();
    GLDebug::DrawSprite(t, 10, 10);

    _angle += deltaTime * 50;

    auto hw = float(t2->GetWidth()) / 2;
    auto hh = float(t2->GetHeight()) / 2;

    glTranslatef(300 + hw, 10 + hh, 0);
    glRotatef(_angle, 0, 0, 1);

    GLDebug::DrawSprite(t2,-hw, -hh);
}

