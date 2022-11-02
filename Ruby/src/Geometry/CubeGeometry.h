#pragma once

#include <vector>

#include "GeometryObject.h"

namespace Ruby {
	class CubeGeometry : public GeometryObject {
	public:
		CubeGeometry();

		std::vector<float> getVerticies(bool normals = false, bool textureCordinates = false) const override;
		std::vector<unsigned int> getIndicies() const override;

	private:
		const static std::vector<float> positionalData;
		const static std::vector<float> normalData;
		const static std::vector<float> textureCordinateData;

		const static std::vector<unsigned int> indexData;
	};
}