#pragma once

#include <GL/glew.h>

#include "Resources/TextFile.h"

namespace Ruby {
	class Shader {
	public:
		Shader(unsigned int shaderID, TextFile sourceFile) : m_Shader(shaderID), m_ShaderSourceFile(sourceFile) {}
		Shader(Shader&) = delete;
		Shader& operator=(Shader&) = delete;
		virtual ~Shader() { glDeleteShader(m_Shader); }
		Shader(Shader&& other) noexcept
			: m_Shader(std::move(other.m_Shader)),
			  m_ShaderSourceFile(std::move(other.m_ShaderSourceFile)) {
			other.m_Shader = 0;
		}

		Shader& operator=(Shader&& other) noexcept {
			m_Shader = std::move(other.m_Shader);
			other.m_Shader = 0;

			m_ShaderSourceFile = std::move(other.m_ShaderSourceFile);
		}

		unsigned int getShader() const { return m_Shader; }

		TextFile getShaderSourceFile() const { return m_ShaderSourceFile; }

	private:
		unsigned int m_Shader;
		TextFile m_ShaderSourceFile;
	};
}