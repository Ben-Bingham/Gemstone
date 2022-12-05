#include "SphereGeometryData.h"

#include "Angles.h"

#include "Shaders/VertexShader.h"

namespace Ruby {
	SphereGeometryData::SphereGeometryData(unsigned int NumberOfStacks, unsigned int NumberOfSectors)
		: numberOfSectors(NumberOfSectors)
		, numberOfStacks(NumberOfStacks) { }

	std::vector<float> SphereGeometryData::getVertices() const {
		std::vector<float> verticies;

		Malachite::Radian sectorStep = 2 * Malachite::pi / numberOfSectors;
		Malachite::Radian stackStep = Malachite::pi / numberOfStacks;

		for (unsigned int i = 0; i <= numberOfStacks; i++) {
			Malachite::Radian stackAngle = Malachite::pi / 2 - i * stackStep; // goes from top to bottom

			for (unsigned int j = 0; j <= numberOfSectors; j++) {
				Malachite::Radian sectorAngle = j * sectorStep;

				// positions
				verticies.push_back(cosf(sectorAngle) * cosf(stackAngle));
				verticies.push_back(sinf(stackAngle));
				verticies.push_back(sinf(sectorAngle) * cosf(stackAngle));

				// normals
				verticies.push_back(cosf(sectorAngle) * cosf(stackAngle));
				verticies.push_back(sinf(stackAngle));
				verticies.push_back(sinf(sectorAngle) * cosf(stackAngle));
			

				// texture cordinates
				verticies.push_back(static_cast<float>(j) / numberOfSectors);
				verticies.push_back(static_cast<float>(i) / numberOfStacks);
				
			}
		}

		return verticies;
	}

	std::vector<unsigned int> SphereGeometryData::getIndices() const {
		std::vector<unsigned int> indicies;

		for (unsigned int i = 0; i < numberOfStacks; i++) {
			unsigned int k1 = i * (numberOfSectors + 1);
			unsigned int k2 = k1 + numberOfSectors + 1;

			for (unsigned int j = 0; j < numberOfSectors; j++, k1++, k2++) {
				if (i != 0) {
					indicies.push_back(k1);
					indicies.push_back(k2);
					indicies.push_back(k1 + 1);
				}

				if (i != (numberOfStacks - 1)) {
					indicies.push_back(k1 + 1);
					indicies.push_back(k2);
					indicies.push_back(k2 + 1);
				}
			}
		}

		return indicies;
	}
}