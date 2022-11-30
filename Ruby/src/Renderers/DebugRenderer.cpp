#include "DebugRenderer.h"
#include "Renderer.h"

namespace Ruby {
	DebugRenderer::DebugRenderer() {
		m_VAO.bind();

		m_VBO.bind();
		m_VBO.setNoData(m_VBOSize, GL_DYNAMIC_DRAW);

		VertexShader::LayoutData layoutData {
			VertexShader::LayoutDataElement {
				VertexShader::LayoutDataElement::DataType::VECTOR_3F,
				VertexShader::LayoutDataElement::DataName::POSITION
			}
		};

		m_VAO.configureForLayout(layoutData);
	}

	void DebugRenderer::queue(const std::vector<Malachite::Vector3f>& points) {
#ifdef RUBY_DEBUG
		if (points.size() % 2 == 1) {
			LOG("Uneven number of points supplied, this may modify futre queue calls.", Lazuli::LogLevel::WARNING);
		}
#endif
		for (const Malachite::Vector3f& point : points) {
			m_Points.emplace_back(point);
		}
	}

	void DebugRenderer::render() {
		std::vector<float> pointsAsFloats;
		pointsAsFloats.reserve(m_Points.size() * 3);

		void* voidPoints = (void*)&m_Points;

		pointsAsFloats = *(std::vector<float>*)voidPoints;

		m_VBO.setPartialData(pointsAsFloats, 0);

		m_VAO.bind();
		glDrawArrays(GL_LINES, 0, (GLsizei)m_Points.size());

		m_Points.clear();
	}
}