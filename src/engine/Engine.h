//
// Created by Roman on 3/19/2024.
//

#ifndef SDLTEST_ENGINE_H
#define SDLTEST_ENGINE_H

#include "functional/FunctionalTestRunner.h"

class Engine {
public:
    static bool Init();
    static void Update(float deltaTime);
    static void Release();
    static void OnResize(int width, int height);

private:
    static FunctionalTestRunner _testRunner;
};


#endif //SDLTEST_ENGINE_H
