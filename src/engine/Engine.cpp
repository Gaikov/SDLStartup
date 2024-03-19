//
// Created by Roman on 3/19/2024.
//

#include "Engine.h"
#include "GLDebug.h"
#include "BitmapData.h"
#include "linmath.h"
#include "GameApp.h"

FunctionalTestRunner Engine::_testRunner;

bool Engine::Init() {

    GLDebug::Init();

    if (!GameApp::GetApp()->GetImageDecoder()->Init()) {
        return false;
    }

    if (!_testRunner.Init()) {
        return false;
    }

    glClearColor(0.6, 0.6, 0.6, 1);

    return true;
}

void Engine::Update(float deltaTime) {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);

    glColor4f(1, 1, 1, 1);

    _testRunner.Update(deltaTime);

    glFlush();
}

void Engine::Release() {
    _testRunner.Release();
    GameApp::GetApp()->GetImageDecoder()->Release();
    GLDebug::Release();
}

void Engine::OnResize(int width, int height) {
    printf("on resize %ix%i\n", width, height);
    glViewport(0, 0, width, height);
    mat4x4 proj;
    mat4x4_ortho(proj, 0, (float) width, (float) height, 0, -1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf((float *) proj);
    glMatrixMode(GL_MODELVIEW);
}
