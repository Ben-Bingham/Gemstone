#pragma once

#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class PhongRenderable : public Renderable {
	public:
		PhongRenderable(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, PhongMaterial& mat);

		void render() const override;

		Malachite::Matrix4f model{ 1.0f };
		PhongMaterial* material{ nullptr };
	};
}