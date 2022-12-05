#pragma once
#include "ShapeData.h"

#include "OpenGL objects/GlBuffer.h"
#include "OpenGL objects/VertexAttributeObject.h"

namespace Ruby {
	class Mesh {
	public:
		enum class Shape {
			CUBE,
			SPHERE,
			PLANE
		};

		enum class DrawMode {
			TRIANGLES = GL_TRIANGLES,
			LINES = GL_LINES
		};

		Mesh(Shape shape);
		Mesh();

		void bind() const;

		[[nodiscard]] DrawMode getDrawMode() const;
		void setDrawMode(DrawMode drawMode);

		[[nodiscard]] size_t getIndexCount() const;
		[[nodiscard]] Vertices getVertices() const;
		[[nodiscard]] Indices getIndices() const;
	

		void edit(const Vertices& newVertices, unsigned int offset);
		void edit(const Indices& newIndices, unsigned int offset);

		void edit(const Vertices& newVertices);
		void edit(const Indices& newIndices);

		void edit(const Vertices& newVertices, const Indices& newIndices);

	private:
		static [[nodiscard]] Vertices getVerticesFromShape(Shape shape);
		static [[nodiscard]] Indices getIndicesFromShape(Shape shape);

		Vertices m_Vertices{ };
		Indices m_Indices{ };

		DrawMode m_DrawMode{ DrawMode::TRIANGLES };

		VertexAttributeObject m_VertexAttributes{ };
		VertexBuffer m_VertexBuffer{ };
		IndexBuffer m_IndexBuffer{ };
	};
}