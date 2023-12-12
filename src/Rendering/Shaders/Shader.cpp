#include "pch.h"
#include "Shader.h"

#include <fstream>

#include "Core/Engine.h"

namespace Gem {
	Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
		//VertexShaderHandle vsHandle = g_Engine.openGlContext.CreateShader(OpenGlContext::ShaderType::VERTEX);
		//g_Engine.openGlContext.AttachShaderSource(vsHandle, GetShaderSource(vertexPath));
		//g_Engine.openGlContext.CompileShader(vsHandle);

		//FragmentShaderHandle fsHandle = g_Engine.openGlContext.CreateShader(OpenGlContext::ShaderType::FRAGMENT);
		//g_Engine.openGlContext.AttachShaderSource(fsHandle, GetShaderSource(fragmentPath));
		//g_Engine.openGlContext.CompileShader(fsHandle);

		//m_Handle = g_Engine.openGlContext.CreateShaderProgram();
		//g_Engine.openGlContext.AttachShaderToProgram(m_Handle, vsHandle);
		//g_Engine.openGlContext.AttachShaderToProgram(m_Handle, fsHandle);

		//g_Engine.openGlContext.CompileShaderProgram(m_Handle);
	}

	void Shader::Bind() const {
		//g_Engine.openGlContext.BindShaderProgram(m_Handle);
	}

	void Shader::Upload(const std::string& variableName, const int value) {
		//g_Engine.openGlContext.UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const float value) {
		//g_Engine.openGlContext.UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const Matrix4f& value) {
		//g_Engine.openGlContext.UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const Vector3f& value) {
		//g_Engine.openGlContext.UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const Vector4f& value) {
		//g_Engine.openGlContext.UploadUniform(GetUniformLocation(variableName), value);
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

	UniformLocation Shader::GetUniformLocation(const std::string& name) {
		auto it = m_UniformLocationMap.find(name);
		if (it != m_UniformLocationMap.end()) {
			return it->second;
		}

		//m_UniformLocationMap[name] = g_Engine.openGlContext.GetUniformLocation(m_Handle, name);

		return m_UniformLocationMap[name];
	}
}