//
// Created by Raman Haikou on 2019-07-27.
//

#ifndef _GROM_GLTEXTURESCACHE_H_
#define _GROM_GLTEXTURESCACHE_H_

#include "headers.h"
#include "SimpleCache.h"

class GLTexture;

class GLTexturesCache
{
public:
	GLTexturesCache();

	GLTexture* GetTexture(const char *fileName);
	void FreeTexture(GLTexture *texture);

private:

	SimpleCache<GLTexture> _cache;
};


#endif //_GROM_GLTEXTURESCACHE_H_
