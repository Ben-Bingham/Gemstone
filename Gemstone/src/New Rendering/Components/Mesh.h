#pragma once
#include <vector>

#include "New Rendering/OpenGl Objects/GlBuffer.h"
#include "New Rendering/OpenGl Objects/VertexAttributeObject.h"

namespace Gem {
	constexpr size_t ELEMENTS_IN_VERTEX = 8;
	using Vertex = std::tuple<Vector3f, Vector3f, Vector2f>;
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

	// class Mesh {
	// public:
	// 	Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
	// 	Mesh(const std::vector<Vertex>& vertices = std::vector<Vertex>{}, const std::vector<Index>& indices = std::vector<Index>{});
	// 	Mesh(const Shape& shape);
	//
	// 	void Bind();
	//
	// 	size_t indexCount{ 0 };
	// private:
	// 	static std::vector<float> ReorganizeVertexData(const std::vector<Vertex>& vertices);
	//
	// 	VertexBuffer m_Vb;
	// 	IndexBuffer m_Ib;
	// 	VertexAttributeObject m_Vao;
	// };

	using MeshId = unsigned int;

	class Mesh {
	public:
		Mesh() = default;
		Mesh(const Shape& shape);

		std::vector<Vertex> vertices;
		std::vector<Index> indices;

		MeshId id{ s_MeshId++ };

	private:
		static inline MeshId s_MeshId{ 0 };
	};
}