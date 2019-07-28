//
// Created by Roman on 28/07/2019.
//

#include "BitmapData.h"
#include "headers.h"
#include "TextureUtils.h"

bool BitmapData::Init()
{
	ilInit();
	IMAGE_CHECK("ilInit", false)
	return true;
}

void BitmapData::Release()
{
	ilShutDown();
}

BitmapData::BitmapData(int w, int h) :
	_width(w),
	_height(h)
{
	_data = new unsigned char[w * h * 4];
}

BitmapData::~BitmapData()
{
	delete _data;
}

BitmapData *BitmapData::LoadFromFile(const char *filePath)
{
	printf("...loading texture: %s\n", filePath);
	auto image = ilGenImage();
	IMAGE_CHECK("ilGenImage", nullptr)
	ilBindImage(image);
	IMAGE_CHECK("ilBindimage", nullptr)
	ilLoadImage(filePath);
	IMAGE_CHECK("ilLoadImage", nullptr)

	auto w = (ILuint)ilGetInteger(IL_IMAGE_WIDTH);
	auto h = (ILuint)ilGetInteger(IL_IMAGE_HEIGHT);
	auto bmData = new BitmapData(w, h);
	ilCopyPixels(0, 0, 0, w, h, 1, IL_RGBA, IL_UNSIGNED_BYTE, bmData->_data);
	if (TextureUtils::hasError("ilCopyPixels"))
	{
		delete bmData;
		return nullptr;
	}
	return bmData;
}

int BitmapData::GetWidth() const
{
	return _width;
}

int BitmapData::GetHeight() const
{
	return _height;
}

unsigned char *BitmapData::GetData() const
{
	return _data;
}
