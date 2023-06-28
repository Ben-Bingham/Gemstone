#pragma once
#include "Rendering/Material/IMaterial.h"
#include "Rendering/OpenGl Objects/Texture.h"

namespace Gem {
	class DefaultMaterial : public IMaterial {
		static Ptr<Shader> m_DefaultShader;

	public:
		DefaultMaterial(const Image& diffuse = Image::MISSING_IMAGE, const Image& specular = Image::MISSING_IMAGE);
		DefaultMaterial(const DefaultMaterial& other) = default;
		DefaultMaterial(DefaultMaterial&& other) noexcept = default;
		DefaultMaterial& operator=(const DefaultMaterial& other) = default;
		DefaultMaterial& operator=(DefaultMaterial&& other) noexcept = default;
		~DefaultMaterial() override = default;

		void Apply() override;

		Texture diffuse;
		Texture specular;
	};
}