#pragma once

#include "Shader.h"

#include "Rendering/Resources/TextFile.h"

namespace Gem {
	class VertexShader : public Shader {
	public:
		VertexShader(const TextFile& shaderSourceFile);
	};
}