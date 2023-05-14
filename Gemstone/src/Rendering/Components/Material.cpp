#include "pch.h"
#include "Material.h"
#include "Gem.h"

namespace Gem {
	InternalMaterial::InternalMaterial(const Image& diffuse, const Image& specular)
		: diffuse(Texture{ diffuse })
		, specular(Texture{ specular })
		, shader(CreatePtr<Shader>(GEM_ASSETS_PATH + "shaders\\Default.vert", GEM_ASSETS_PATH + "shaders\\Default.frag")) {
	}

	Material::Material(const Image& diffuse, const Image& specular)
		: m_InternalMaterial(CreatePtr<InternalMaterial>(diffuse, specular)) { }

	Texture& Material::Diffuse() const {
		return m_InternalMaterial->diffuse;
	}

	Texture& Material::Specular() const {
		return m_InternalMaterial->specular;
	}
}