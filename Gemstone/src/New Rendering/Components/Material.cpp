#include "pch.h"
#include "Material.h"
#include "Gem.h"

namespace Gem {
	Material::Material(const Image& diffuse, const Image& specular)
		: diffuse(CreatePtr<Texture>(diffuse)), specular(CreatePtr<Texture>(specular)) {

		if (!m_Shader) {
			m_Shader = CreatePtr<Shader>(GEM_ASSETS_PATH + "shaders\\Default.vert", GEM_ASSETS_PATH + "shaders\\Default.frag");
		}
	}

	void Material::Bind() {
		m_Shader->Bind();
	}
}