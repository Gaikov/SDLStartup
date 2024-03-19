//
// Created by Roman on 28/07/2019.
//

#ifndef SDLTEST_BITMAPDATA_H
#define SDLTEST_BITMAPDATA_H

class BitmapData
{
public:
	BitmapData(int w, int h);
	~BitmapData();

	int GetWidth() const;
	int GetHeight() const;
	unsigned char* GetData() const;
    unsigned char* GetData() { return _data;}

private:
	int _width;
	int _height;
	unsigned char *_data;
};


#endif //SDLTEST_BITMAPDATA_H
