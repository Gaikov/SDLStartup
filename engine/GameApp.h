//
// Created by Roman on 3/19/2024.
//

#ifndef SDLTEST_GAMEAPP_H
#define SDLTEST_GAMEAPP_H

#include "images/ImagesDecoder.h"

class GameApp {
public:
    static GameApp* GetApp();

    virtual ImagesDecoder* GetImageDecoder() = 0;
};



#endif //SDLTEST_GAMEAPP_H
