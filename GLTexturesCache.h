//
// Created by Raman Haikou on 2019-07-27.
//

#ifndef _GROM_GLTEXTURESCACHE_H_
#define _GROM_GLTEXTURESCACHE_H_

#include "headers.h"

class GLTexture;

class GLTexturesCache
{
public:
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


#endif //_GROM_GLTEXTURESCACHE_H_
