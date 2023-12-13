#include "GeometryShader.h"
#include "Log.h"

namespace Ruby {
	GeometryShader::GeometryShader(const TextFile& shaderSourceFile)
		: Shader(glCreateShader(GL_GEOMETRY_SHADER), shaderSourceFile) {

		std::string shaderSource = getShaderSourceFile().getContent();
		const char* charShaderSource = shaderSource.c_str();

		glShaderSource(getShader(), 1, &charShaderSource, NULL);
		glCompileShader(getShader());

		int success;
		char infoLog[512];
		glGetShaderiv(getShader(), GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(getShader(), 512, NULL, infoLog);
			LOG("Geometry shader failed to compile.\n" + std::string(infoLog), Lazuli::LogLevel::ERROR);
		}
	}
}