#pragma once

#include <vector>

namespace Ruby {
	class GeometryObject {
	public:
		GeometryObject();

		virtual std::vector<float> getVerticies(bool normals, bool textureCordinates) const = 0;
		virtual std::vector<unsigned int> getIndicies() const = 0;
	};
}