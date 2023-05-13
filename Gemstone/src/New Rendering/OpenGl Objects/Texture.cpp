#include "pch.h"
#include "Texture.h"
#include "imgui.h"

#include "Core/Engine.h"

namespace Gem {
	Texture::Texture(const Image& image)
		: Image(image), m_Handle(g_Engine.openGlContext.GenerateTexture()) {

		g_Engine.openGlContext.ConfigureTexture2D(m_Handle);
		g_Engine.openGlContext.AssignTextureData2D(m_Handle, image);
	}

	Texture::~Texture() {
		g_Engine.openGlContext.DeleteTexture(m_Handle);
	}

	void Texture::Bind() const {
		g_Engine.openGlContext.BindTexture2D(m_Handle);
	}

	const Texture Texture::MISSING_IMAGE_TEXTURE{};
}

namespace ImGui {
	void Image(const Gem::Texture& texture) {
		// if (texture == nullptr) {
		// 	Image((void*)Gem::Texture::MISSING_IMAGE_TEXTURE.m_Handle, ImVec2{ (float)Gem::Texture::MISSING_IMAGE_TEXTURE.dimensions.x * 100, (float)Gem::Texture::MISSING_IMAGE_TEXTURE.dimensions.y * 100 });
		// 	return;
		// }
		Image((void*)texture.m_Handle, ImVec2{ (float)texture.dimensions.x, (float)texture.dimensions.y });
	}
}

