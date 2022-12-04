#pragma once

#include "Material.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/Uniform.h"
#include "Shaders/Uniforms/UniformSet.h"

namespace Ruby {
	class PhongMaterial : public Material {
	public:
		PhongMaterial(const Ptr<Texture>& diffuseTexture, const Ptr<Texture>& specularTexture, const float shininess = 32.0f)
			: Material(ShaderLibrary::get().phongShader), diffuseTexture(diffuseTexture), specularTexture(specularTexture), shininess(shininess) {
			
		}

		void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Malachite::Matrix4f modelViewProjection = model * view * projection;

			ShaderProgram::upload("modelViewProjection", modelViewProjection);
			ShaderProgram::upload("model", model);
		}

		Malachite::Vector3f cameraPosition{ 0.0f };
		inline static std::vector<PointLight*> pointLights{ };
		inline static std::vector<DirectionalLight*> directionalLights{ };
		Ptr<Texture> diffuseTexture;
		Ptr<Texture> specularTexture;
		float shininess;

	private:
		UniformSet<
			Malachite::Vector3f,
			std::vector<PointLight*>,
			std::vector<DirectionalLight*>,
			Texture,
			Texture,
			float
		> m_Uniforms{
			Uniform{ "cameraPosition", cameraPosition },
			Uniform{ "pointLights", pointLights },
			Uniform{ "directionalLights", directionalLights },
			Uniform{ "material.diffuse", *diffuseTexture },
			Uniform{ "material.specular", *specularTexture },
			Uniform{ "material.shininess", shininess }
		};
	};
}