#include "pch.h"
#include "Rendering/Material/Materials/DefaultMaterial.h"
#include "Gem.h"

namespace Gem {
	DefaultMaterial::DefaultMaterial(const Image& diffuse, const Image& specular)
		: IMaterial(m_DefaultShader, m_DefaultInstancedShader), diffuse(Texture{ diffuse }), specular(Texture{specular}) {
		
	}

	void DefaultMaterial::Apply() {
		shader->Bind();
		
		Texture::ActivateUnit(0);
		diffuse.Bind();
		shader->Upload("u_Diffuse", 0);
		
		Texture::ActivateUnit(1);
		specular.Bind();
		shader->Upload("u_Specular", 1);
	}

	void DefaultMaterial::InstancedApply() {
		instancedShader->Bind();

		Texture::ActivateUnit(0);
		diffuse.Bind();
		shader->Upload("u_Diffuse", 0);

		Texture::ActivateUnit(1);
		specular.Bind();
		shader->Upload("u_Specular", 1);
	}

	Ptr<Shader> DefaultMaterial::m_DefaultShader{ CreatePtr<Shader>(GEM_ASSETS_PATH + "shaders\\Default.vert", GEM_ASSETS_PATH + "shaders\\Default.frag") };
	Ptr<Shader> DefaultMaterial::m_DefaultInstancedShader{ CreatePtr<Shader>(GEM_ASSETS_PATH + "shaders\\DefaultInstanced.vert", GEM_ASSETS_PATH + "shaders\\DefaultInstanced.frag") };
}