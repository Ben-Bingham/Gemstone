#include <fstream>
#include "Rendering/Shaders/Shader.h"
#include "Utility/Log.h"

namespace Gem {
	Shader::Shader(const Path& vertexPath, const Path& fragmentPath)
		: m_Handle(0) {
		const VertexShaderHandle vsHandle = OpenGlContext::Get().CreateShader(OpenGlContext::ShaderType::VERTEX);
		OpenGlContext::Get().AttachShaderSource(vsHandle, GetShaderSource(vertexPath));
		OpenGlContext::Get().CompileShader(vsHandle);

		const FragmentShaderHandle fsHandle = OpenGlContext::Get().CreateShader(OpenGlContext::ShaderType::FRAGMENT);
		OpenGlContext::Get().AttachShaderSource(fsHandle, GetShaderSource(fragmentPath));
		OpenGlContext::Get().CompileShader(fsHandle);

		m_Handle = OpenGlContext::Get().CreateShaderProgram();
		OpenGlContext::Get().AttachShaderToProgram(m_Handle, vsHandle);
		OpenGlContext::Get().AttachShaderToProgram(m_Handle, fsHandle);

		OpenGlContext::Get().CompileShaderProgram(m_Handle);
	}

	void Shader::Bind() const {
		OpenGlContext::Get().BindShaderProgram(m_Handle);
	}

	void Shader::Upload(const std::string& variableName, const int value) {
		OpenGlContext::Get().UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const float value) {
		OpenGlContext::Get().UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const Matrix4f& value) {
		OpenGlContext::Get().UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const Vector3f& value) {
		OpenGlContext::Get().UploadUniform(GetUniformLocation(variableName), value);
	}

	void Shader::Upload(const std::string& variableName, const Vector4f& value) {
		OpenGlContext::Get().UploadUniform(GetUniformLocation(variableName), value);
	}

	std::string Shader::GetShaderSource(const Path& path) {
		std::ifstream inputFileStream;

		inputFileStream.open(path.path);
		if (!inputFileStream) {
			LOG("Unable to open text file: " + path.path, LogLevel::ERROR);
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
		/*const auto it = m_UniformLocationMap.find(name);
		if (it != m_UniformLocationMap.end()) {
			return it->second;
		}*/ 

		if (!m_UniformLocationMap.contains(name)) { // TODO test
			m_UniformLocationMap[name] = OpenGlContext::Get().GetUniformLocation(m_Handle, name);
		}

		return m_UniformLocationMap[name];
	}
}