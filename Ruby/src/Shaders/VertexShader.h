#pragma once

#include "Shader.h"

namespace Ruby {
	class VertexShader : public Shader {
	public:
		VertexShader(const TextFile& shaderSourceFile);
	};
}