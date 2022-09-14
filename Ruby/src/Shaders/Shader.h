#pragma once

#include "TextFile.h"

namespace Ruby {
	class Shader {
	public:
		Shader(unsigned int shaderID, TextFile sourceFile) : m_Shader(shaderID), m_ShaderSourceFile(sourceFile) {}

		virtual void dispose() = 0;

		unsigned int getShader() const { return m_Shader; };

		TextFile getShaderSourceFile() const { return m_ShaderSourceFile; }

	private:
		unsigned int m_Shader;
		TextFile m_ShaderSourceFile;
	};
}