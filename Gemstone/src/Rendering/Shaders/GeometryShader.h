#pragma once

#include "Shader.h"

#include "Rendering/Resources/TextFile.h"

namespace Gem {
	class GeometryShader : public Shader {
	public:
		GeometryShader(const TextFile& shaderSourceFile);
	};
}