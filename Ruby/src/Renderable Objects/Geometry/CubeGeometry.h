#pragma once

#include <vector>

namespace Ruby {
	class CubeGeometry {
	public:
		CubeGeometry();

		std::vector<float> getVerticies(bool normals = false, bool textureCordinates = false);
		std::vector<unsigned int> getIndicies();

	private:
		const static std::vector<float> positionalData;
		const static std::vector<float> normalData;
		const static std::vector<float> textureCordinateData;

		const static std::vector<unsigned int> indexData;
	};
}