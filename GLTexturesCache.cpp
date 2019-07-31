//
// Created by Raman Haikou on 2019-07-27.
//

#include "GLTexturesCache.h"
#include "TextureUtils.h"
#include "GLTexture.h"

GLTexture *GLTexturesCache::AllocateResource(const char *id, int param)
{
	return GLTexture::Load(id);
}

void GLTexturesCache::FreeResource(GLTexture *item)
{
	GLTexture::Free(item);
}
