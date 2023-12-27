#pragma once
#include "Rendering/Meshes/RawMesh.h"
#include "Rendering/Utility/Index.h"
#include "Rendering/Utility/Vertex.h"

namespace Gem {
	class Shape {
	public:
		Shape() = default;
		Shape(const Shape& other) = default;
		Shape(Shape&& other) noexcept = default;
		Shape& operator=(const Shape& other) = default;
		Shape& operator=(Shape&& other) noexcept = default;
		virtual ~Shape() = default;

		[[nodiscard]] virtual RawMesh GetRawMesh() const = 0; // TODO This can be implemented by this class, its always the same

	private:
		[[nodiscard]] virtual std::vector<Vertex> Vertices() const = 0;
		[[nodiscard]] virtual std::vector<Index> Indices() const = 0;
	};
}