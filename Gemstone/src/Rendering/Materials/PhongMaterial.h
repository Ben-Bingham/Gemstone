#pragma once

#include "MaterialData.h"

#include "Ruby/Shaders/ShaderLibrary.h"
#include "Ruby/Shaders/Uniforms/Uniform.h"
#include "Ruby/Shaders/Uniforms/UniformSet.h"
#include "Ruby/Lights.h"
#include "Celestite/Pointer.h"

namespace Gem {
	class PhongMaterial : public MaterialData {
	public:
		PhongMaterial(const Ptr<Texture>& diffuseTexture, const Ptr<Texture>& specularTexture, const float shininess = 32.0f)
			: MaterialData(ShaderLibrary::Get().phongShader), diffuseTexture(diffuseTexture), specularTexture(specularTexture), shininess(shininess) {
			
		}

		PhongMaterial(const Ptr<Image>& diffuseImage, const Ptr<Image>& specularImage, const float shininess = 32.0f)
			: MaterialData(ShaderLibrary::Get().phongShader)
			, diffuseTexture(CreatePtr<Texture>(diffuseImage))
			, specularTexture(CreatePtr<Texture>(specularImage))
			, shininess(shininess) {
			
		}

		void use(const Matrix4f& model, const Matrix4f& view, const Matrix4f& projection) override {
			m_Program->use();
			m_Uniforms.upload();

			const Matrix4f modelViewProjection = model * view * projection;

			ShaderProgram::upload("modelViewProjection", modelViewProjection);
			ShaderProgram::upload("model", model);
		}

		Vector3f cameraPosition{ 0.0f };
		inline static std::vector<Ptr<PointLight>> pointLights{ };
		inline static std::vector<Ptr<DirectionalLight>> directionalLights{ };
		Ptr<Texture> diffuseTexture;
		Ptr<Texture> specularTexture;
		float shininess;

		friend bool operator==(const PhongMaterial& lhs, const PhongMaterial& rhs) {
			return lhs.diffuseTexture == rhs.diffuseTexture
				&& lhs.specularTexture == rhs.specularTexture
				&& lhs.shininess == rhs.shininess;
		}

		friend bool operator!=(const PhongMaterial& lhs, const PhongMaterial& rhs) { return !(lhs == rhs); }

	private:
		UniformSet<
			Vector3f,
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