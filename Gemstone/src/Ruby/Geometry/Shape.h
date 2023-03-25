#pragma once
#include "ShapeData.h"
#include "Celestite/Pointer.h"

namespace Ruby {
	class Shape { //TODO can possibly be renamed
	public:
		Shape() = default;
		Shape(const Shape& other) = default;
		Shape(Shape&& other) noexcept = default;
		Shape& operator=(const Shape& other) = default;
		Shape& operator=(Shape&& other) noexcept = default;
		virtual ~Shape() = default;

		[[nodiscard]] virtual Vertices GetVertices() const = 0;
		[[nodiscard]] virtual Indices GetIndices() const = 0;
	};

	class Sphere final : public Shape {
	public:
		Sphere(unsigned int verticalSegments = 18, unsigned int horizontalSegments = 36);

		[[nodiscard]] Vertices GetVertices() const override;
		[[nodiscard]] Indices GetIndices() const override;

		friend bool operator==(const Sphere& lhs, const Sphere& rhs);
		friend bool operator!=(const Sphere& lhs, const Sphere& rhs);

	private:
		unsigned int m_VerticalSegments;
		unsigned int m_HorizontalSegments;
	};

	class Cube final : public Shape {
	public:
		Cube() = default;

		[[nodiscard]] Vertices GetVertices() const override;
		[[nodiscard]] Indices GetIndices() const override;

		friend bool operator==(const Cube& lhs, const Cube& rhs);
		friend bool operator!=(const Cube& lhs, const Cube& rhs);
	};

	class Plane final : public Shape {
	public:
		Plane() = default;

		[[nodiscard]] Vertices GetVertices() const override;
		[[nodiscard]] Indices GetIndices() const override;

		friend bool operator==(const Plane& lhs, const Plane& rhs);
		friend bool operator!=(const Plane& lhs, const Plane& rhs);
	};

	bool Equal(const Celestite::Ptr<Shape>& lhs, const Celestite::Ptr<Shape>& rhs);
}