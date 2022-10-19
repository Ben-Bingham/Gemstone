#pragma once

#include "Renderable Objects/Solid/SolidRenderable.h"
#include "Colour.h"

namespace Ruby {
	class DebugRenderable : public SolidRenderable {
	public:
		DebugRenderable(const std::vector<float>& verticies, Colour Colour);

		void render() const override;

	private:
		std::vector<unsigned int> generateIndicies(unsigned int numberOfVerticies);
	};

	class DebugLine : public DebugRenderable {
	public:
		DebugLine(const Malachite::Vector3f& point1, const Malachite::Vector3f& point2, Colour colour = Colour{ 184, 199, 22 });

	private:
		std::vector<float> generateVerticies(const Malachite::Vector3f& point1, const Malachite::Vector3f& point2);
	};
}