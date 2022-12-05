#pragma once
#include <vector>

#include "Vector.h"

namespace Ruby {
	using Index = unsigned int;

	struct Vertex {
		Malachite::Vector3f position;
		Malachite::Vector3f normal;
		Malachite::Vector2f textureCoordinate;
	};

	using Indices = std::vector<Index>;
	using Vertices = std::vector<Vertex>;

	class Mesh {
	public:
		enum class Shape {
			CUBE,
			SPHERE,
			PLANE
		};

		Mesh(Shape shape);
		Mesh();

	private:
		[[nodiscard]] Vertices initVertFromShape(Shape shape) const;
		[[nodiscard]] Indices initIndFromShape(Shape shape) const;

		Vertices m_Vertices;
		Indices m_Indices;
	};
}