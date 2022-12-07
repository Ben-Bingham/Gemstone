#pragma once

#include "Shader.h"

namespace Ruby {
	class FragmentShader : public Shader {
	public:
		FragmentShader(const TextFile& shaderSourceFile);
	};
}