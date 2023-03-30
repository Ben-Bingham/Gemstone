#pragma once

#include "MaterialData.h"

#include "Rendering/Shaders/ShaderLibrary.h"
#include "Rendering/Shaders/Uniforms/Uniform.h"
#include "Utility/Colour.h"
#include "Rendering/Shaders/Uniforms/UniformSet.h"

namespace Gem {
	class SolidMaterial : public MaterialData {
	public:
		explicit SolidMaterial(const Colour& colour = Colour{ 224, 17, 95 })
			: MaterialData(ShaderLibrary::Get().solidShader), colour(colour) {
			
		}

		void use(const Matrix4f& model, const Matrix4f& view, const Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Matrix4f modelViewProjection = model * view * projection;

			ShaderProgram::upload("modelViewProjection", modelViewProjection);
		}

		Colour colour;


	private:
		UniformSet<Colour> m_Uniforms{ Uniform{"objectColour", colour} };
	};
}