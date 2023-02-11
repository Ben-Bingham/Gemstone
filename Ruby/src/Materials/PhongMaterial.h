#pragma once

#include "MaterialData.h"

#include "Shaders/ShaderLibrary.h"
#include "Shaders/Uniforms/Uniform.h"
#include "Shaders/Uniforms/UniformSet.h"
#include "Lights.h"
#include "Pointer.h"

namespace Ruby {
	class PhongMaterial : public MaterialData {
	public:
		PhongMaterial(const Celestite::Ptr<Texture>& diffuseTexture, const Celestite::Ptr<Texture>& specularTexture, const float shininess = 32.0f)
			: MaterialData(ShaderLibrary::get().phongShader), diffuseTexture(diffuseTexture), specularTexture(specularTexture), shininess(shininess) {
			
		}

		PhongMaterial(const Celestite::Ptr<Image>& diffuseImage, const Celestite::Ptr<Image>& specularImage, const float shininess = 32.0f)
			: MaterialData(ShaderLibrary::get().phongShader)
			, diffuseTexture(Celestite::CreatePtr<Texture>(diffuseImage))
			, specularTexture(Celestite::CreatePtr<Texture>(specularImage))
			, shininess(shininess) {
			
		}

		void use(const Malachite::Matrix4f& model, const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Malachite::Matrix4f modelViewProjection = model * view * projection;

			ShaderProgram::upload("modelViewProjection", modelViewProjection);
			ShaderProgram::upload("model", model);
		}

		Malachite::Vector3f cameraPosition{ 0.0f };
		inline static std::vector<Celestite::Ptr<PointLight>> pointLights{ };
		inline static std::vector<Celestite::Ptr<DirectionalLight>> directionalLights{ }; // TODO should be a shared pointer not a raw pointer
		Celestite::Ptr<Texture> diffuseTexture;
		Celestite::Ptr<Texture> specularTexture;
		float shininess;

		friend bool operator==(const PhongMaterial& lhs, const PhongMaterial& rhs) {
			return lhs.diffuseTexture == rhs.diffuseTexture
				&& lhs.specularTexture == rhs.specularTexture
				&& lhs.shininess == rhs.shininess;
		}

		friend bool operator!=(const PhongMaterial& lhs, const PhongMaterial& rhs) { return !(lhs == rhs); }

	private:
		UniformSet<
			Malachite::Vector3f,
			std::vector<Ptr<PointLight>>,
			std::vector<Ptr<DirectionalLight>>,
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