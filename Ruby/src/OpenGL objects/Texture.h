#pragma once

#include "Resources/Image.h"

namespace Ruby {
	class Texture {
	public:
		explicit Texture(const Image& image);
		Texture(Texture&) = delete;
		Texture(Texture&& other) noexcept;
		~Texture();

		Texture& operator=(Texture&) = delete;
		Texture& operator=(Texture&& other) noexcept;

		void bind() const;
		static void activateUnit(int unit);

		[[nodiscard]] unsigned int getTexture() const;
		void updateData();

	private:
		unsigned int m_Texture;
		const Image* m_Image;

		void setSubData(unsigned int posX, unsigned int posY, const Image& image);
	};
}