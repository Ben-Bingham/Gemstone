#pragma once

#include <vector>
#include "Math/Vector.h"

namespace Gem {
	using Index = unsigned int;

	struct Vertex {
		Vertex() = default;
		Vertex(const Vector3f& positionData, const Vector3f& normalData, const Vector2f& textureCoordinateData);
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

		Vector3f position;
		Vector3f normal;
		Vector2f textureCoordinate;

		friend bool operator==(const Vertex& lhs, const Vertex& rhs) {
			return lhs.position == rhs.position
				&& lhs.normal == rhs.normal
				&& lhs.textureCoordinate == rhs.textureCoordinate;
		}

		friend bool operator!=(const Vertex& lhs, const Vertex& rhs) { return !(lhs == rhs); }
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