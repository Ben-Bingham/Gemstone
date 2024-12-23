#pragma once
#include <unordered_map>
#include "Rendering/OpenGlContext.h"

namespace Gem {
	class Shader {
	public:
		Shader(const Path& vertexPath, const Path& fragmentPath);

		void Bind() const;

		void Upload(const std::string& variableName, int value);
		void Upload(const std::string& variableName, float value);
		void Upload(const std::string& variableName, const Matrix4f& value);
		void Upload(const std::string& variableName, const Vector3f& value);
		void Upload(const std::string& variableName, const Vector4f& value);

	private:
		ShaderProgramHandle m_Handle;

		std::unordered_map<std::string, UniformLocation> m_UniformLocationMap{};

		static std::string GetShaderSource(const Path& path);

		UniformLocation GetUniformLocation(const std::string& name);
	};
}