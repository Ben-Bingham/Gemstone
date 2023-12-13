#pragma once
#include "Gem.h"

namespace Gem {
	constexpr size_t ELEMENTS_IN_VERTEX = 8;
	struct Vertex {
		Vertex(Vector3f position, Vector3f normal, Vector2f uv);

		Vector3f position;
		Vector3f normal;
		Vector2f uv;
	};

	using Index = unsigned int;

	class Shape {
	public:
		Shape() = default;
		Shape(const Shape& other) = default;
		Shape(Shape&& other) noexcept = default;
		Shape& operator=(const Shape& other) = default;
		Shape& operator=(Shape&& other) noexcept = default;
		virtual ~Shape() = default;

		[[nodiscard]] virtual std::vector<Vertex> Vertices() const = 0;
		[[nodiscard]] virtual std::vector<Index> Indices() const = 0;
	};

	class Cube final : public Shape {
	public:
		// TODO Dimensions do not currently work
		Cube(const Vector3f& dimensions = Vector3f{ 1.0f, 1.0f, 1.0f });
		Cube(const Cube& other) = default;
		Cube(Cube&& other) noexcept = default;
		Cube& operator=(const Cube& other) = default;
		Cube& operator=(Cube&& other) noexcept = default;
		~Cube() override = default;

		[[nodiscard]] std::vector<Vertex> Vertices() const override;
		[[nodiscard]] std::vector<Index> Indices() const override;

	private:
		Vector3f m_Dimensions;
	};
}