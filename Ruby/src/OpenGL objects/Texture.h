#pragma once

#include "Pointer.h"

#include "Resources/Image.h"

namespace Ruby {
	class Texture {
	public:
		explicit Texture(const Ptr<Image>& image);
		Texture(Texture&) = delete;
		~Texture();

		Texture& operator=(Texture&) = delete;

		Texture(const Texture& other) = delete;

		Texture(Texture&& other) noexcept
			: m_Texture(other.m_Texture)
			, m_Image(std::move(other.m_Image)) {}

		Texture& operator=(const Texture& other) = delete;

		Texture& operator=(Texture&& other) noexcept {
			if (this == &other)
				return *this;
			m_Texture = other.m_Texture;
			m_Image = std::move(other.m_Image);
			return *this;
		}

		void bind() const;
		static void activateUnit(int unit);

		[[nodiscard]] unsigned int getTexture() const;
		void updateData();

	private:
		unsigned int m_Texture;
		Ptr<Image> m_Image;

		void setSubData(unsigned int posX, unsigned int posY, const Ptr<Image>& image);
	};
}