#pragma once
#include "Celestite/Pointer.h"
#include "ShapeData.h"

#include "Ruby/OpenGL objects/GlBuffer.h"
#include "Ruby/OpenGL objects/VertexAttributeObject.h"
#include "Shape.h"

namespace Ruby {
	class MeshData { //TODO bad name
	public:
		enum class DrawMode {
			TRIANGLES = GL_TRIANGLES,
			LINES = GL_LINES
		};

		MeshData(const Celestite::Ptr<Shape>& shape);
		MeshData();

		void bind() const;
		void ForceBind() const;

		[[nodiscard]] DrawMode getDrawMode() const;
		void setDrawMode(DrawMode drawMode);

		[[nodiscard]] size_t getIndexCount() const;
		[[nodiscard]] Vertices getVertices() const;
		[[nodiscard]] Indices getIndices() const;
		// [[nodiscard]] MeshDescriptor GetDescription() const;
		[[nodiscard]] Celestite::Ptr<Shape> GetShape();

		void edit(const Vertices& newVertices, unsigned int offset);
		void edit(const Indices& newIndices, unsigned int offset);

		void edit(const Vertices& newVertices);
		void edit(const Indices& newIndices);

		void edit(const Vertices& newVertices, const Indices& newIndices);

	private:
		Vertices m_Vertices{ };
		Indices m_Indices{ };

		DrawMode m_DrawMode{ DrawMode::TRIANGLES };

		VertexAttributeObject m_VertexAttributes{ };
		VertexBuffer m_VertexBuffer{ };
		IndexBuffer m_IndexBuffer{ };

		Celestite::Ptr<Shape> m_Shape;
	};
}