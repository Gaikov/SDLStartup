//
// Created by Raman Haikou on 2019-07-27.
//

#include "GLTexturesCache.h"
#include <IL/il.h>
#include "TextureUtils.h"

bool GLTexturesCache::Init()
{
	ilInit();
	IMAGE_CHECK("ilInit")
	return true;
}

void GLTexturesCache::Release()
{
	ilShutDown();
}
