//
// Created by Raman Haikou on 2019-07-27.
//

#include "GLTexturesCache.h"
#include <IL/il.h>

void GLTexturesCache::Init()
{
	ilInit();
}

void GLTexturesCache::Release()
{
	ilShutDown();
}
