#include "pch.h"
#include "SimpleMaterial.h"
#include "Gem.h"

namespace Gem {
	SimpleMaterial::SimpleMaterial(const Colour& colour)
		: IMaterial(m_SimpleShader, m_SimpleInstancedShader), colour(colour) { }

	void SimpleMaterial::Apply() {
		shader->Bind();

		shader->Upload("u_Colour", colour.ToVec4f());
	}

	Ptr<Shader> SimpleMaterial::m_SimpleShader{ CreatePtr<Shader>(GEM_ASSETS_PATH + "shaders\\Simple.vert", GEM_ASSETS_PATH + "shaders\\Simple.frag") };
	Ptr<Shader> SimpleMaterial::m_SimpleInstancedShader{ CreatePtr<Shader>(GEM_ASSETS_PATH + "shaders\\SimpleInstanced.vert", GEM_ASSETS_PATH + "shaders\\SimpleInstanced.frag") };

}