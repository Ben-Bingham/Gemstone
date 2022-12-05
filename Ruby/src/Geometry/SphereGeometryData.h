#pragma once

#include <vector>

#include "GeometryData.h"

namespace Ruby {
	class SphereGeometryData : public GeometryData {
	public:
		SphereGeometryData(unsigned int numberOfStacks = 18u, unsigned int numberOfSectors = 36u);

		[[nodiscard]] std::vector<float> getVertices() const override;
		[[nodiscard]] std::vector<unsigned int> getIndices() const override;

	private:
		unsigned int numberOfSectors; // Number of faces that wrap around horizontally
		unsigned int numberOfStacks; // Number of faces that go from top to bottom vertically
	};
}