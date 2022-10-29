#pragma once

#include <vector>

namespace Ruby {
	class SphereGeometry {
	public:
		SphereGeometry(unsigned int numberOfStacks = 18u, unsigned int numberOfSectors = 36u);

		std::vector<float> getVerticies(bool normals = true, bool textureCordinates = true);
		std::vector<unsigned int> getIndicies();

	private:
		unsigned int numberOfSectors; // Number of faces that wrap around horizontaly
		unsigned int numberOfStacks; // Number of faces that go from top to bottom vertically
	};
}