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

	static BitmapData *LoadFromFile(const char *filePath);
	static bool Init();
	static void Release();

	int GetWidth() const;
	int GetHeight() const;
	unsigned char *GetData() const;

private:
	int _width;
	int _height;
	unsigned char *_data;
};


#endif //SDLTEST_BITMAPDATA_H
