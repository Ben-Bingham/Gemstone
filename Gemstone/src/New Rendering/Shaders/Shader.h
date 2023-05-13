#pragma once
#include "New Rendering/OpenGlContext.h"

namespace Gem {
	class Shader {
	public:
		Shader(const std::string& vertexPath, const std::string& fragmentPath);

		void Bind();

	private:
		ShaderProgramHandle m_Handle;

		static std::string GetShaderSource(const std::string& path);
	};
}