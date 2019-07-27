//
// Created by Raman Haikou on 2019-07-21.
//

#include "TextureUtils.h"

struct ilError
{
	const ILenum code;
	const char *info;
};

static ilError ilErrors[] = {
		{IL_NO_ERROR,             "IL_NO_ERROR"},
		{IL_INVALID_ENUM,         "IL_INVALID_ENUM"},
		{IL_OUT_OF_MEMORY,        "IL_OUT_OF_MEMORY"},
		{IL_FORMAT_NOT_SUPPORTED, "IL_FORMAT_NOT_SUPPORTED"},
		{IL_INTERNAL_ERROR,       "IL_INTERNAL_ERROR"},
		{IL_INVALID_VALUE,        "IL_INVALID_VALUE"},
		{IL_ILLEGAL_OPERATION,    "IL_ILLEGAL_OPERATION"},
		{IL_ILLEGAL_FILE_VALUE,   "IL_ILLEGAL_FILE_VALUE"},
		{IL_INVALID_FILE_HEADER,  "IL_INVALID_FILE_HEADER"},
		{IL_INVALID_PARAM,        "IL_INVALID_PARAM"},
		{IL_COULD_NOT_OPEN_FILE,  "IL_COULD_NOT_OPEN_FILE"},
		{IL_INVALID_EXTENSION,    "IL_INVALID_EXTENSION"},
		{IL_FILE_ALREADY_EXISTS,  "IL_FILE_ALREADY_EXISTS"},
		{IL_OUT_FORMAT_SAME,      "IL_OUT_FORMAT_SAME"},
		{IL_STACK_OVERFLOW,       "IL_STACK_OVERFLOW"},
		{IL_STACK_UNDERFLOW,      "IL_STACK_UNDERFLOW"},
		{IL_INVALID_CONVERSION,   "IL_INVALID_CONVERSION"},
		{IL_BAD_DIMENSIONS,       "IL_BAD_DIMENSIONS"},
		{IL_FILE_READ_ERROR,      "IL_FILE_READ_ERROR"},
		{IL_FILE_WRITE_ERROR,     "IL_FILE_WRITE_ERROR"},

		{IL_LIB_GIF_ERROR,        "IL_LIB_GIF_ERROR"},
		{IL_LIB_JPEG_ERROR,       "IL_LIB_JPEG_ERROR"},
		{IL_LIB_PNG_ERROR,        "IL_LIB_PNG_ERROR"},
		{IL_LIB_TIFF_ERROR,       "IL_LIB_TIFF_ERROR"},
		{IL_LIB_MNG_ERROR,        "IL_LIB_MNG_ERROR"},
		{IL_LIB_JP2_ERROR,        "IL_LIB_JP2_ERROR"},
		{IL_LIB_EXR_ERROR,        "IL_LIB_EXR_ERROR"},
		{IL_UNKNOWN_ERROR,        "IL_UNKNOWN_ERROR"}
};

const char *TextureUtils::GetImageError(ILuint code)
{
	for (auto error : ilErrors)
	{
		if (error.code == code)
		{
			return error.info;
		}
	}

	return "undefined error";
}

bool TextureUtils::hasError(const char *funcName)
{
	auto code = ilGetError();
	if (code)
	{
		printf("image error:%s: %s\n", funcName, GetImageError(code));
		return true;
	}
	return false;
}
