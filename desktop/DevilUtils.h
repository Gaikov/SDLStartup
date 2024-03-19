//
// Created by Raman Haikou on 2019-07-21.
//

#ifndef _GROM_TEXTURE_UTILS_H_
#define _GROM_TEXTURE_UTILS_H_

#include <IL/il.h>

class DevilUtils
{
public:
	static const char *GetImageError(ILuint code);

	static bool hasError(const char *funcName);
};

#define IMAGE_CHECK(funcName, error) \
if (DevilUtils::hasError(funcName)) \
    return error;


#endif //_GROM_TEXTURE_UTILS_H_
