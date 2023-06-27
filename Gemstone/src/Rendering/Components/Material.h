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
		const static Ptr<Shader> shader;
	};

	class Material {
	public:
		friend class RenderingSystem;

		Material(const Image& diffuse = Image::MISSING_IMAGE, const Image& specular = Image::MISSING_IMAGE);
		Material(const Colour& colour);

		[[nodiscard]] Texture& Diffuse() const;
		[[nodiscard]] Texture& Specular() const;

	private:
		Ptr<InternalMaterial> m_InternalMaterial;
	};
}