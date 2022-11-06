#pragma once
#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class ScreenQuad : public Renderable {
	public:
		ScreenQuad(const Texture* texture);

		void render() const override;

	private:
		const Texture* m_Texture;
		const static std::vector<float> verticies;
		const static std::vector<unsigned int> indicies;
	};
}