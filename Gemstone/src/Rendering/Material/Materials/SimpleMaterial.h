#pragma once
#include "Rendering/Material/IMaterial.h"

namespace Gem {
	class SimpleMaterial : public IMaterial {
		static Ptr<Shader> m_SimpleShader;
		static Ptr<Shader> m_SimpleInstancedShader;

	public:
		SimpleMaterial(const Colour& colour);
		SimpleMaterial(const SimpleMaterial& other) = default;
		SimpleMaterial(SimpleMaterial&& other) noexcept = default;
		SimpleMaterial& operator=(const SimpleMaterial& other) = default;
		SimpleMaterial& operator=(SimpleMaterial&& other) noexcept = default;
		~SimpleMaterial() override = default;

		void Apply() override;

		Colour colour;
	};
}