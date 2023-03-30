#include "pch.h"
#include "Shape.h"

namespace Gem {
	// Sphere
	Sphere::Sphere(const unsigned int verticalSegments, const unsigned int horizontalSegments)
		: m_VerticalSegments(verticalSegments), m_HorizontalSegments(horizontalSegments) {

	}

	[[nodiscard]] Vertices Sphere::GetVertices() const {
		return ShapeData::getSphereVertices(m_VerticalSegments, m_HorizontalSegments);
	}

	[[nodiscard]] Indices Sphere::GetIndices() const {
		return ShapeData::getSphereIndices(m_VerticalSegments, m_HorizontalSegments);
	}

	bool operator==(const Sphere& lhs, const Sphere& rhs) {
		return lhs.m_VerticalSegments == rhs.m_VerticalSegments
			&& lhs.m_HorizontalSegments == rhs.m_HorizontalSegments;
	}

	bool operator!=(const Sphere& lhs, const Sphere& rhs) { return !(lhs == rhs); }


	// Cube
	[[nodiscard]] Vertices Cube::GetVertices() const {
		return ShapeData::getCubeVertices();
	}

	[[nodiscard]] Indices Cube::GetIndices() const {
		return ShapeData::getCubeIndices();
	}

	bool operator==(const Cube& lhs, const Cube& rhs) { return true; }
	bool operator!=(const Cube& lhs, const Cube& rhs) { return !(lhs == rhs); }


	// Plane
	[[nodiscard]] Vertices Plane::GetVertices() const {
		return ShapeData::getPlaneVertices();
	}

	[[nodiscard]] Indices Plane::GetIndices() const {
		return ShapeData::getPlaneIndices();
	}

	bool operator==(const Plane& lhs, const Plane& rhs) { return true; }
	bool operator!=(const Plane& lhs, const Plane& rhs) { return !(lhs == rhs); }


	// General
	bool Equal(const Ptr<Shape>& lhs, const Ptr<Shape>& rhs) {
		const auto& lhsTypeId = typeid(*lhs);
		std::string lhsName= lhsTypeId.name();
		const auto& rhsTypeId = typeid(*rhs);
		std::string rhsName = rhsTypeId.name();
		if (typeid(*lhs) != typeid(*rhs)) {
			return false;
		}

		if (lhsTypeId == typeid(Sphere)) {
			Ptr<Sphere> lhsSphere = std::dynamic_pointer_cast<Sphere>(lhs);
			Ptr<Sphere> rhsSphere = std::dynamic_pointer_cast<Sphere>(rhs);

			return *lhsSphere == *rhsSphere;
		}
		if (lhsTypeId == typeid(Cube)) {
			Ptr<Cube> lhsCube = std::dynamic_pointer_cast<Cube>(lhs);
			Ptr<Cube> rhsCube = std::dynamic_pointer_cast<Cube>(rhs);

			return *lhsCube == *rhsCube;
		}
		if (lhsTypeId == typeid(Plane)) {
			Ptr<Plane> lhsPlane = std::dynamic_pointer_cast<Plane>(lhs);
			Ptr<Plane> rhsPlane = std::dynamic_pointer_cast<Plane>(rhs);

			return *lhsPlane == *rhsPlane;
		}

		LOG("Shape could not be identified", LogLevel::ERROR);
		return false;
	}
}