#pragma once
#include <Windows.h>
#include "ShapeData.h"

#include "Shape.h"

#include "Rendering/OpenGL objects/GlBuffer.h"
#include "Rendering/OpenGL objects/VertexAttributeObject.h"

namespace Gem {
	class MeshData { //TODO bad name
	public:
		enum class DrawMode {
			TRIANGLES = GL_TRIANGLES,
			LINES = GL_LINES
		};

		MeshData(const Ptr<Shape>& shape);
		MeshData();

		void bind() const;
		void ForceBind() const;

		[[nodiscard]] DrawMode getDrawMode() const;
		void setDrawMode(DrawMode drawMode);

		[[nodiscard]] size_t getIndexCount() const;
		[[nodiscard]] Vertices getVertices() const;
		[[nodiscard]] Indices getIndices() const;
		// [[nodiscard]] MeshDescriptor GetDescription() const;
		[[nodiscard]] Ptr<Shape> GetShape();

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

		Ptr<Shape> m_Shape;
	};
}