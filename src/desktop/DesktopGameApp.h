//
// Created by Roman on 3/19/2024.
//

#ifndef SDLTEST_DESKTOPGAMEAPP_H
#define SDLTEST_DESKTOPGAMEAPP_H

#include "engine/GameApp.h"
#include "DevilImagesDecoder.h"

class DesktopGameApp : public GameApp {
public:
    ImagesDecoder *GetImageDecoder() override;

private:
    DevilImagesDecoder _imgDecoder;
};


#endif //SDLTEST_DESKTOPGAMEAPP_H
