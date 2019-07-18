//
// Created by Roman Gaikov on 2019-07-18.
//

#ifndef SDLTEST_GLUTILS_H
#define SDLTEST_GLUTILS_H


class GLUtils
{
public:
	static bool hasError(const char *funcName);
};

#define GL_CHECK(funcName) \
if (GLUtils::hasError(funcName)) { \
	return false; \
}

#define GL_ERROR(funcName) GLUtils::hasError(funcName);


#endif //SDLTEST_GLUTILS_H
