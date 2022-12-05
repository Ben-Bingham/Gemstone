#pragma once

#include <vector>

#include "Vector.h"

namespace Ruby {
	using Index = unsigned int;

	struct Vertex {
		Vertex(const Malachite::Vector3f& positionData, const Malachite::Vector3f& normalData, const Malachite::Vector2f& textureCoordinateData);
		Vertex(
			const float& posX,
			const float& posY,
			const float& posZ,
			const float& normX,
			const float& normY,
			const float& normZ,
			const float& texCordX,
			const float& texCordY
		);

		Malachite::Vector3f position;
		Malachite::Vector3f normal;
		Malachite::Vector2f textureCoordinate;
	};

	using Indices = std::vector<Index>;
	using Vertices = std::vector<Vertex>;

	struct ShapeData {
		static Vertices getCubeVertices();
		static Indices getCubeIndices();

		static Vertices getSphereVertices(unsigned int horizontalResolution, unsigned int verticalResolution);
		static Indices getSphereIndices(unsigned int horizontalResolution, unsigned int verticalResolution);

		static Vertices getPlaneVertices();
		static Indices getPlaneIndices();
	};
}