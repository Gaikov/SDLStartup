//
// Created by Roman on 3/19/2024.
//

#include "Engine.h"
#include "GLDebug.h"
#include "BitmapData.h"
#include "linmath.h"

FunctionalTestRunner Engine::_testRunner;

bool Engine::Init(float width, float height) {

    GLDebug::Init();
    if (!BitmapData::Init())
    {
        return false;
    }

    if (!_testRunner.Init())
    {
        return false;
    }

    glClearColor(0.6, 0.6, 0.6, 1);
    mat4x4 proj;
    mat4x4_ortho(proj, 0, width, height, 0, -1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf((float*)proj);
    glMatrixMode(GL_MODELVIEW);

    return true;
}

void Engine::Update(float deltaTime) {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    glColor4f(1, 1, 1, 1);

    _testRunner.Draw();

    glFlush();
}

void Engine::Release() {
    _testRunner.Release();
    BitmapData::Release();
    GLDebug::Release();
}
