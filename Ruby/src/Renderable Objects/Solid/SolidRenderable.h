#pragma once

#include "Colour.h"
#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class SolidRenderable : public Renderable {
	public:
		SolidRenderable(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const Colour& colour);

		void render() const override;

		Malachite::Matrix4f model{ 1.0f };
		Colour colour;
	};
}