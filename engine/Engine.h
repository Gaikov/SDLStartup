//
// Created by Roman on 3/19/2024.
//

#ifndef SDLTEST_ENGINE_H
#define SDLTEST_ENGINE_H

#include "functional/FunctionalTestRunner.h"

class Engine {
public:
    static bool Init(float width, float height);
    static void Update(float deltaTime);
    static void Release();

private:
    static FunctionalTestRunner _testRunner;
};


#endif //SDLTEST_ENGINE_H
