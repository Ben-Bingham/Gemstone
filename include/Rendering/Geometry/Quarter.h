#pragma once
#include "Shapes.h"

namespace Gem {
	class Quarter : public Shape {
	public:
		Quarter() = default;
		Quarter(const Quarter& other) = default;
		Quarter(Quarter&& other) noexcept = default;
		Quarter& operator=(const Quarter& other) = default;
		Quarter& operator=(Quarter&& other) noexcept = default;
		~Quarter() override = default;

		[[nodiscard]] RawMesh GetRawMesh() const override;

	private:
		[[nodiscard]] std::vector<Vertex> Vertices() const override;
		[[nodiscard]] std::vector<Index> Indices() const override;
	};
}