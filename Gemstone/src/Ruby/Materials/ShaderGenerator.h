#pragma once
#include "Material.h"
#include "MaterialData.h"

namespace Ruby {
	using namespace Celestite;

	class ShaderGenerator {
	public:
		// static ShaderGenerator& Get();

		// Ptr<ShaderProgram> GenerateShader(Material material);

	private:
		ShaderGenerator() = default;

		bool m_Initialized;
	};
}