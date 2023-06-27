#include "pch.h"
#include "Material.h"
#include "Gem.h"

namespace Gem {
	InternalMaterial::InternalMaterial(const Image& diffuse, const Image& specular)
		: diffuse(Texture{ diffuse })
		, specular(Texture{ specular }) { }

	const Ptr<Shader> InternalMaterial::shader{ CreatePtr<Shader>(GEM_ASSETS_PATH + "shaders\\Default.vert", GEM_ASSETS_PATH + "shaders\\Default.frag") };

	Material::Material(const Image& diffuse, const Image& specular)
		: m_InternalMaterial(CreatePtr<InternalMaterial>(diffuse, specular)) { }

	Material::Material(const Colour& colour)
		: m_InternalMaterial(CreatePtr<InternalMaterial>(Image::CreateImage(colour), Image::CreateImage(Colour::BLACK))) {}

	Texture& Material::Diffuse() const {
		return m_InternalMaterial->diffuse;
	}

	Texture& Material::Specular() const {
		return m_InternalMaterial->specular;
	}

}