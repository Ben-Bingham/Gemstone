#pragma once

#include <vector>

namespace Ruby {
	class GeometryData {
	public:
		GeometryData();

		virtual std::vector<float> getVerticies(bool normals, bool textureCordinates) const = 0;
		virtual std::vector<unsigned int> getIndicies() const = 0;
	};
}