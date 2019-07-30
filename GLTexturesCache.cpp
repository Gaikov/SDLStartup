//
// Created by Raman Haikou on 2019-07-27.
//

#include "GLTexturesCache.h"
#include "TextureUtils.h"
#include "GLTexture.h"

GLTexturesCache::GLTexturesCache() :
		_cache([this](const char *fileName) -> GLTexture *
		       {
			       return GLTexture::Load(fileName);
		       })
{

}

GLTexture *GLTexturesCache::GetTexture(const char *fileName)
{
	return _cache.GetEntry(fileName);
}

void GLTexturesCache::FreeTexture(GLTexture *texture)
{
	if (_cache.ReleaseEntry(texture, false))
	{
		GLTexture::Free(texture);
	}
}

