//
// Created by Roman on 3/19/2024.
//

#include "DevilImagesDecoder.h"
#include "DevilUtils.h"

bool DevilImagesDecoder::Init() {
    ilInit();
    IMAGE_CHECK("ilInit", false)

    return true;
}

void DevilImagesDecoder::Release() {
    ilShutDown();
}

BitmapData *DevilImagesDecoder::LoadFromFile(const char *filePath) const {
    auto image = ilGenImage();
    IMAGE_CHECK("ilGenImage", nullptr)
    ilBindImage(image);
    IMAGE_CHECK("ilBindimage", nullptr)
    ilLoadImage(filePath);
    IMAGE_CHECK("ilLoadImage", nullptr)

    auto w = (ILuint)ilGetInteger(IL_IMAGE_WIDTH);
    auto h = (ILuint)ilGetInteger(IL_IMAGE_HEIGHT);
    auto bmData = new BitmapData((int)w, (int)h);
    ilCopyPixels(0, 0, 0, w, h, 1, IL_RGBA, IL_UNSIGNED_BYTE, bmData->GetData());
    if (DevilUtils::hasError("ilCopyPixels"))
    {
        delete bmData;
        return nullptr;
    }
    return bmData;
}
