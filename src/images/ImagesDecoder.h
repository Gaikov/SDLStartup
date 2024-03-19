//
// Created by Roman on 3/19/2024.
//

#ifndef _IMAGESDECODER_H_
#define _IMAGESDECODER_H_

#include "BitmapData.h"

class ImagesDecoder {
public:
    virtual bool Init() = 0;
    virtual void Release() = 0;
    virtual BitmapData* LoadFromFile(const char *fileName) const = 0;
};

#endif //_IMAGESDECODER_H_
