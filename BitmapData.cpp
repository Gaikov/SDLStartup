//
// Created by Roman on 28/07/2019.
//

#include "BitmapData.h"
#include "headers.h"

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
