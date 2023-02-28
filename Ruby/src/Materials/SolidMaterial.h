#pragma once

#include "Utility/Colour.h"
#include "MaterialData.h"
#include "Shaders/Uniforms/UniformSet.h"
#include "Shaders/Uniforms/Uniform.h"
#include "Shaders/ShaderLibrary.h"

namespace Ruby {
	class SolidMaterial : public MaterialData {
	public:
		explicit SolidMaterial(const Colour& colour = Colour{ 224, 17, 95 })
			: MaterialData(ShaderLibrary::Get().solidShader), colour(colour) {
			
		}

		void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Malachite::Matrix4f modelViewProjection = model * view * projection;

			ShaderProgram::upload("modelViewProjection", modelViewProjection);
		}

		Colour colour;


	private:
		UniformSet<Colour> m_Uniforms{ Uniform{"objectColour", colour} };
	};
}