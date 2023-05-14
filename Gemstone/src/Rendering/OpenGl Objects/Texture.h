#pragma once
#include "Rendering/OpenGlContext.h"
#include "Rendering/Utility/Image.h"

namespace Gem {
	class Texture;
}

namespace ImGui {
	void Image(const Gem::Texture& texture);
}

namespace Gem {
	class Texture : Image {
	public:
		Texture(const Image& image = MISSING_IMAGE);
		Texture(const Texture& other) = delete;
		Texture(Texture&& other) noexcept = default;
		Texture& operator=(const Texture& other) = delete;
		Texture& operator=(Texture&& other) noexcept = default;
		~Texture();

		void Bind() const;
		static void ActivateUnit(size_t index);

		friend void ImGui::Image(const Gem::Texture& texture);

		const static Texture MISSING_IMAGE_TEXTURE;

	private:
		TextureHandle m_Handle{ 0 };
	};
}