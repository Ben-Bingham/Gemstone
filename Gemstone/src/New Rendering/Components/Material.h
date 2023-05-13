#pragma once
#include "New Rendering/OpenGl Objects/Texture.h"
#include "Utility/Pointer.h"
#include "New Rendering/Shaders/Shader.h"

namespace Gem {
	class Material {
	public:
		Material(const Image& diffuse = Image::MISSING_IMAGE, const Image& specular = Image::MISSING_IMAGE);

		Ptr<Texture> diffuse;
		Ptr<Texture> specular;

		void Bind();

	private:
		static inline Ptr<Shader> m_Shader{};
	};
}