#pragma once

#include "Shader.h"

namespace Gem {
	class FragmentShader : public Shader {
	public:
		FragmentShader(const TextFile& shaderSourceFile);
	};
}