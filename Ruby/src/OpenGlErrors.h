#pragma once

#include <GL/glew.h>
#include <iostream>
#include <string>

#include "Log.h"

inline GLenum glCheckError_(const char* file, int line) {
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR) {
		std::string error;
		switch (errorCode) {
		case GL_INVALID_ENUM:				   error = "INVALID_ENUM"; break;
		case GL_INVALID_VALUE:				   error = "INVALID_VALUE"; break;
		case GL_INVALID_OPERATION:			   error = "INVALID_OPERATION"; break;
		case GL_STACK_OVERFLOW:				   error = "STACK_OVERFLOW"; break;
		case GL_STACK_UNDERFLOW:			   error = "STACK_UNDERFLOW"; break;
		case GL_OUT_OF_MEMORY:				   error = "OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
		}
		LOG(error + " | " + file + " (" + std::to_string(line) + ")", Lazuli::LogLevel::ERROR);
	}
	return errorCode;
}

#ifdef RUBY_DEBUG
#define glCheckError() glCheckError_(__FILE__, __LINE__)
#else
#define glCheckError()
#endif // RUBY_DEBUG

