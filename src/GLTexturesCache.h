//
// Created by Raman Haikou on 2019-07-27.
//

#ifndef _GROM_GLTEXTURESCACHE_H_
#define _GROM_GLTEXTURESCACHE_H_

#include "headers.h"
#include "ResourcesCache.h"

class GLTexture;

class GLTexturesCache : public ResourcesCache<GLTexture, int>
{
private:
protected:
	GLTexture *AllocateResource(const char *id, int param) override;
	void FreeResource(GLTexture *item) override;
};


#endif //_GROM_GLTEXTURESCACHE_H_
