//
// Created by Raman Haikou on 2019-07-27.
//

#ifndef SDLTEST_GLTEXTURESCACHE_H
#define SDLTEST_GLTEXTURESCACHE_H

#include "headers.h"

class GLTexture;

class GLTexturesCache
{
public:
	static void Init();
	static void Release();

	GLTexture* GetTexture(const char *fileName);
	void FreeTexture(GLTexture *texture);

private:
	struct TextureEntry
	{
		GLTexture *texture;
		int refCount;
	};

	typedef std::map<std::string, TextureEntry> tTexturesMap;

	tTexturesMap _cache;
};


#endif //SDLTEST_GLTEXTURESCACHE_H
