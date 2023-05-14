#pragma once
#include "Rendering/Systems/RenderingSystem.h"
#include "Rendering/OpenGl Objects/Texture.h"
#include "Utility/Pointer.h"
#include "Rendering/Shaders/Shader.h"

namespace Gem {
	class InternalMaterial {
	public:
		InternalMaterial(const Image& diffuse, const Image& specular);

		Texture diffuse;
		Texture specular;
		Ptr<Shader> shader; //TODO make this different per material type
	};

	class Material {
	public:
		Material(const Image& diffuse = Image::MISSING_IMAGE, const Image& specular = Image::MISSING_IMAGE);

		friend void RenderingSystem::Step(EntityManager& entityManager, float dt);

		Texture& Diffuse() const;
		Texture& Specular() const;

	private:
		Ptr<InternalMaterial> m_InternalMaterial;
	};
}