#pragma once

#include "TextFile.h"

namespace Ruby {
	class Shader {
	public:
		Shader(unsigned int shaderID, TextFile sourceFile) : m_Shader(shaderID) {}

		virtual void dispose() = 0;

		unsigned int getShader() const { return m_Shader; };

	private:
		unsigned int m_Shader;
	};
}