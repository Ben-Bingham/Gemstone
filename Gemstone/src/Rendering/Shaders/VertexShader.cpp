#include "pch.h"
#include "VertexShader.h"

namespace Gem {
	VertexShader::VertexShader(const TextFile& shaderSourceFile)
		: Shader(glCreateShader(GL_VERTEX_SHADER), shaderSourceFile) {

		std::string shaderSource = getShaderSourceFile().getContent();
		const char* charShaderSource = shaderSource.c_str();

		glShaderSource(getShader(), 1, &charShaderSource, NULL);
		glCompileShader(getShader());

		int success;
		char infoLog[512];
		glGetShaderiv(getShader(), GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(getShader(), 512, NULL, infoLog);
			LOG("Vertex shader failed to compile.\n" + std::string(infoLog), LogLevel::ERROR);
		}
	}
}