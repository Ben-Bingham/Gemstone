#pragma once

#include <vector>

#include "GeometryData.h"

namespace Ruby {
	class SphereGeometry : public GeometryData {
	public:
		SphereGeometry(unsigned int numberOfStacks = 18u, unsigned int numberOfSectors = 36u);

		std::vector<float> getVerticies(bool normals = true, bool textureCordinates = true) const override;
		std::vector<unsigned int> getIndicies() const override;

	private:
		unsigned int numberOfSectors; // Number of faces that wrap around horizontaly
		unsigned int numberOfStacks; // Number of faces that go from top to bottom vertically
	};
}