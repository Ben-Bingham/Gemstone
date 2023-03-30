#pragma once
#include "Material.h"
#include "MaterialData.h"

namespace Gem {

	class ShaderGenerator {
	public:
		// static ShaderGenerator& Get();

		// Ptr<ShaderProgram> GenerateShader(Material material);

	private:
		ShaderGenerator() = default;

		bool m_Initialized;
	};
}