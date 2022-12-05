#pragma once

#include <vector>

#include "Shaders/VertexShader.h"

namespace Ruby {
	class GeometryData {
	public:
		enum class DrawMode {
			TRIANGLES,
			LINES
		};

		explicit GeometryData(DrawMode drawMode = DrawMode::TRIANGLES);

		[[nodiscard]] virtual std::vector<float> getVertices(VertexShader::LayoutData) const = 0;
		[[nodiscard]] virtual std::vector<unsigned int> getIndices() const = 0;
		[[nodiscard]] GLenum getDrawMode() const;

	private:
		static GLenum drawModeToGlDrawMode(DrawMode drawMode);

		DrawMode m_DrawMode;
	};
}