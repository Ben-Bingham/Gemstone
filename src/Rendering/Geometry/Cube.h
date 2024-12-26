#pragma once
#include "Shapes.h"

namespace Gem {
	class Cube final : public Shape {
	public:
		// TODO Dimensions do not currently work
		Cube(const glm::vec3& dimensions = glm::vec3{ 1.0f, 1.0f, 1.0f });

		Cube(const Cube& other) = default;
		Cube(Cube&& other) noexcept = default;
		Cube& operator=(const Cube& other) = default;
		Cube& operator=(Cube&& other) noexcept = default;
		~Cube() override = default;

		[[nodiscard]] RawMesh GetRawMesh() const override;

	private:
		[[nodiscard]] std::vector<Vertex> Vertices() const override;
		[[nodiscard]] std::vector<Index> Indices() const override;

		glm::vec3 m_Dimensions;
	};
}