#include "pch.h"
#include "Shader.h"

#include <fstream>

#include "Core/Engine.h"

namespace Gem {
	Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
		VertexShaderHandle vsHandle = g_Engine.openGlContext.CreateShader(OpenGlContext::ShaderType::VERTEX);
		g_Engine.openGlContext.AttachShaderSource(vsHandle, GetShaderSource(vertexPath));
		g_Engine.openGlContext.CompileShader(vsHandle);

		FragmentShaderHandle fsHandle = g_Engine.openGlContext.CreateShader(OpenGlContext::ShaderType::FRAGMENT);
		g_Engine.openGlContext.AttachShaderSource(fsHandle, GetShaderSource(fragmentPath));
		g_Engine.openGlContext.CompileShader(fsHandle);

		m_Handle = g_Engine.openGlContext.CreateShaderProgram();
		g_Engine.openGlContext.AttachShaderToProgram(m_Handle, vsHandle);
		g_Engine.openGlContext.AttachShaderToProgram(m_Handle, fsHandle);

		g_Engine.openGlContext.CompileShaderProgram(m_Handle);
	}

	void Shader::Bind() {
		g_Engine.openGlContext.BindShaderProgram(m_Handle);
	}

	std::string Shader::GetShaderSource(const std::string& path) {
		std::ifstream inputFileStream;

		inputFileStream.open(path);
		if (!inputFileStream) {
			LOG("Unable to open text file: " + path, LogLevel::ERROR);
		}

		std::string shaderSource;
		char character;
		while (inputFileStream >> std::noskipws >> character) {
			shaderSource += character;
		}

		inputFileStream.close();

		return shaderSource;
	}
}