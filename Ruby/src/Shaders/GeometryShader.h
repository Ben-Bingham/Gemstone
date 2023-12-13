#pragma once

#include "Shader.h"

namespace Ruby {
	class GeometryShader : public Shader {
	public:
		GeometryShader(const TextFile& shaderSourceFile);
	};
}