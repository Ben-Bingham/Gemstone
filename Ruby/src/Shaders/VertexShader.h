#pragma once

#include <GL/glew.h>

#include "Shader.h"

namespace Ruby {
	class VertexShader : public Shader {
	public:
		VertexShader(const TextFile& shaderSourceFile);

		void dispose() override { glDeleteShader(getShader()); }
	};
}