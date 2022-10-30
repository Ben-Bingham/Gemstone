#include "SphereGeometry.h"

#include "Angles.h"

namespace Ruby {
	SphereGeometry::SphereGeometry(unsigned int NumberOfStacks, unsigned int NumberOfSectors)
		: numberOfStacks(NumberOfStacks), numberOfSectors(NumberOfSectors) {

	}

	std::vector<float> SphereGeometry::getVerticies(bool normals, bool textureCordinates) {
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

				if (normals) {
					// normals
					verticies.push_back(cosf(sectorAngle) * cosf(stackAngle));
					verticies.push_back(sinf(stackAngle));
					verticies.push_back(sinf(sectorAngle) * cosf(stackAngle));
				}
				
				if (textureCordinates) {
					// texture cordinates
					verticies.push_back((float)j / numberOfSectors);
					verticies.push_back((float)i / numberOfStacks);
				}
			}
		}

		return verticies;
	}

	std::vector<unsigned int> SphereGeometry::getIndicies() {
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