#include "ShapeData.h"

#include "Angles.h"

namespace Ruby {
	Vertices ShapeData::getCubeVertices() {
		return Vertices{
			Vertex{ -0.5f, -0.5f,  0.5f,	 0.0f,  0.0f,  1.0f,	 0.0f,  0.0f },
			Vertex{ -0.5f,  0.5f,  0.5f,	 0.0f,  0.0f,  1.0f,	 0.0f,  1.0f },
			Vertex{  0.5f, -0.5f,  0.5f,	 0.0f,  0.0f,  1.0f,	 1.0f,  0.0f },
			Vertex{  0.5f,  0.5f,  0.5f,	 0.0f,  0.0f,  1.0f,	 1.0f,  1.0f },
				    						 						 	   		 
			Vertex{  0.5f, -0.5f,  0.5f,	 1.0f,  0.0f,  0.0f,	 0.0f,  0.0f },
			Vertex{  0.5f,  0.5f,  0.5f,	 1.0f,  0.0f,  0.0f,	 0.0f,  1.0f },
			Vertex{  0.5f, -0.5f, -0.5f,	 1.0f,  0.0f,  0.0f,	 1.0f,  0.0f },
			Vertex{  0.5f,  0.5f, -0.5f,	 1.0f,  0.0f,  0.0f,	 1.0f,  1.0f },
				    												 	   		 
			Vertex{ -0.5f, -0.5f, -0.5f,	-1.0f,  0.0f,  0.0f,	 0.0f,  0.0f },
			Vertex{ -0.5f,  0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,	 0.0f,  1.0f },
			Vertex{ -0.5f, -0.5f,  0.5f,	-1.0f,  0.0f,  0.0f,	 1.0f,  0.0f },
			Vertex{ -0.5f,  0.5f,  0.5f,	-1.0f,  0.0f,  0.0f,	 1.0f,  1.0f },
				    												 	   		 
			Vertex{ -0.5f,  0.5f,  0.5f,	 0.0f,  1.0f,  0.0f,	 0.0f,  0.0f },
			Vertex{ -0.5f,  0.5f, -0.5f,	 0.0f,  1.0f,  0.0f,	 0.0f,  1.0f },
			Vertex{  0.5f,  0.5f,  0.5f,	 0.0f,  1.0f,  0.0f,	 1.0f,  0.0f },
			Vertex{  0.5f,  0.5f, -0.5f,	 0.0f,  1.0f,  0.0f,	 1.0f,  1.0f },
				    												 	   		 
			Vertex{  0.5f, -0.5f, -0.5f,	 0.0f,  0.0f, -1.0f,	 0.0f,  0.0f },
			Vertex{  0.5f,  0.5f, -0.5f,	 0.0f,  0.0f, -1.0f,	 0.0f,  1.0f },
			Vertex{ -0.5f, -0.5f, -0.5f,	 0.0f,  0.0f, -1.0f,	 1.0f,  0.0f },
			Vertex{ -0.5f,  0.5f, -0.5f,	 0.0f,  0.0f, -1.0f,	 1.0f,  1.0f },
				    												 	   		 
			Vertex{ -0.5f, -0.5f, -0.5f,	 0.0f, -1.0f,  0.0f,	 0.0f,  0.0f },
			Vertex{ -0.5f, -0.5f,  0.5f,	 0.0f, -1.0f,  0.0f,	 0.0f,  1.0f },
			Vertex{  0.5f, -0.5f, -0.5f,	 0.0f, -1.0f,  0.0f,	 1.0f,  0.0f },
			Vertex{  0.5f, -0.5f,  0.5f,	 0.0f, -1.0f,  0.0f,	 1.0f,  1.0f }
		};
	}

	Indices ShapeData::getCubeIndices() {
		return Indices{
			 0,   1,   2,
			 1,   3,   2,
			 4,   5,   6,
			 5,   7,   6,
			 8,   9,  10,
			 9,  11,  10,
			12,  13,  14,
			13,  15,  14,
			16,  17,  18,
			17,  19,  18,
			20,  21,  22,
			21,  23,  22
		};
	}

	Vertices ShapeData::getSphereVertices(const unsigned horizontalResolution, const unsigned verticalResolution) {
		Vertices vertices;

		const Malachite::Radian sectorStep = 2 * Malachite::pi / (float)horizontalResolution;
		const Malachite::Radian stackStep = Malachite::pi / (float)verticalResolution;

		for (unsigned int i = 0; i <= verticalResolution; i++) {
			const Malachite::Radian stackAngle = Malachite::pi / 2 - i * stackStep; // goes from top to bottom

			for (unsigned int j = 0; j <= horizontalResolution; j++) {
				const Malachite::Radian sectorAngle = j * sectorStep;

				vertices.emplace_back(Vertex{ 
					cosf(sectorAngle) * cosf(stackAngle),
					sinf(stackAngle),
					sinf(sectorAngle) * cosf(stackAngle),

					cosf(sectorAngle) * cosf(stackAngle),
					sinf(stackAngle),
					sinf(sectorAngle) * cosf(stackAngle),

					(float)(j) / (float)horizontalResolution,
					(float)(i) / (float)verticalResolution
				});
			}
		}

		return vertices;
	}

	Indices ShapeData::getSphereIndices(const unsigned horizontalResolution, const unsigned verticalResolution) {
		Indices indices{ };

		for (unsigned int i = 0; i < verticalResolution; i++) {
			unsigned int k1 = i * (horizontalResolution + 1);
			unsigned int k2 = k1 + horizontalResolution + 1;

			for (unsigned int j = 0; j < horizontalResolution; j++, k1++, k2++) {
				if (i != 0) {
					indices.push_back(k1);
					indices.push_back(k2);
					indices.push_back(k1 + 1);
				}

				if (i != (verticalResolution - 1)) {
					indices.push_back(k1 + 1);
					indices.push_back(k2);
					indices.push_back(k2 + 1);
				}
			}
		}

		return indices;
	}

	Vertices ShapeData::getPlaneVertices() {
		return Vertices{
			Vertex{ -1.0f,  1.0f,  0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 1.0f },
			Vertex{ -1.0f, -1.0f,  0.0f,	0.0f, 0.0f, 1.0f,	0.0f, 0.0f },
			Vertex{  1.0f, -1.0f,  0.0f,    0.0f, 0.0f, 1.0f,	1.0f, 0.0f },
			Vertex{  1.0f,  1.0f,  0.0f,    0.0f, 0.0f, 1.0f,	1.0f, 1.0f }
		};
	}

	Indices ShapeData::getPlaneIndices() {
		return Indices{
			2,  1,  0,
			3,  2,  0
		};
	}
}