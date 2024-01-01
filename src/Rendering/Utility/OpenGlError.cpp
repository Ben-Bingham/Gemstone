#include "Rendering/Utility/OpenGlError.h"

namespace Gem {
	//void APIENTRY GlErrorCallback(GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char* message, const void* userParam) {
	//	// ignore non-significant error/warning codes
	//	if (id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

	//	LogLevel level;

	//	switch (severity) {
	//	default:
	//	case GL_DEBUG_SEVERITY_HIGH:			level = LogLevel::ERROR; break;
	//	case GL_DEBUG_SEVERITY_MEDIUM:
	//	case GL_DEBUG_SEVERITY_LOW:				level = LogLevel::WARNING; break;
	//	case GL_DEBUG_SEVERITY_NOTIFICATION:	level = LogLevel::INFO; break;
	//	}

	//	std::string string = "Debug message (";
	//	string += std::to_string(id);
	//	string += "): ";
	//	string += message;

	//	string += ", ";

	//	switch (source) {
	//	case GL_DEBUG_SOURCE_API:             string += "Source: API"; break;
	//	case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   string += "Source: Window System"; break;
	//	case GL_DEBUG_SOURCE_SHADER_COMPILER: string += "Source: Shader Compiler"; break;
	//	case GL_DEBUG_SOURCE_THIRD_PARTY:     string += "Source: Third Party"; break;
	//	case GL_DEBUG_SOURCE_APPLICATION:     string += "Source: Application"; break;
	//	case GL_DEBUG_SOURCE_OTHER:           string += "Source: Other"; break;
	//	}

	//	string += ", ";

	//	switch (type) {
	//	case GL_DEBUG_TYPE_ERROR:               string += "Type: Error"; break;
	//	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: string += "Type: Deprecated Behaviour"; break;
	//	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  string += "Type: Undefined Behaviour"; break;
	//	case GL_DEBUG_TYPE_PORTABILITY:         string += "Type: Portability"; break;
	//	case GL_DEBUG_TYPE_PERFORMANCE:         string += "Type: Performance"; break;
	//	case GL_DEBUG_TYPE_MARKER:              string += "Type: Marker"; break;
	//	case GL_DEBUG_TYPE_PUSH_GROUP:          string += "Type: Push Group"; break;
	//	case GL_DEBUG_TYPE_POP_GROUP:           string += "Type: Pop Group"; break;
	//	case GL_DEBUG_TYPE_OTHER:               string += "Type: Other"; break;
	//	}

	//	LOG(string, level);
	//}
}