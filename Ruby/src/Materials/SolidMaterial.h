#pragma once

#include "Colour.h"
#include "Material.h"
#include "Shaders/Uniforms/UniformSet.h"
#include "Shaders/Uniforms/Uniform.h"

namespace Ruby {
	class SolidMaterial : public Material {
	public:
		explicit SolidMaterial(const Colour& colour = Colour{ 224, 17, 95 }) //TODO split into .h and .cpp
			: Material(ShaderLibrary::get().solidShader), colour(colour) {
			
		}

		void use() override {
			m_Program->use();
			m_Uniforms.upload();
		}

		Colour colour;
	private:
		UniformSet<Colour> m_Uniforms{ Uniform{"objectColour", colour} };
	};
}