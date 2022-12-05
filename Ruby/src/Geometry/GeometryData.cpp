#include "GeometryData.h"

namespace Ruby {
	GeometryData::GeometryData(const DrawMode drawMode)
		: m_DrawMode(drawMode) {
		
	}

	GLenum GeometryData::getDrawMode() const {
		return drawModeToGlDrawMode(m_DrawMode);
	}

	GLenum GeometryData::drawModeToGlDrawMode(const DrawMode drawMode) {
		switch (drawMode) {
		case DrawMode::TRIANGLES:
			return GL_TRIANGLES;
		case DrawMode::LINES:
			return GL_LINES;
		}
		return 0;
	}
}