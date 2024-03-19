//
// Created by Roman on 3/19/2024.
//

#ifndef SDLTEST_DEVILIMAGESDECODER_H
#define SDLTEST_DEVILIMAGESDECODER_H

#include "images/ImagesDecoder.h"

class DevilImagesDecoder : public ImagesDecoder {
    bool Init() override;

    void Release() override;

    BitmapData *LoadFromFile(const char *fileName) const override;
};


#endif //SDLTEST_DEVILIMAGESDECODER_H
