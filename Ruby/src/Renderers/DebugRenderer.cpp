#include "DebugRenderer.h"
#include "Renderer.h"
#include "OpenGlErrors.h"
#include "Geometry/RawGeometryData.h"

namespace Ruby {
	DebugRenderer::DebugRenderer(Renderer* renderer) 
		: m_Material(Colour{ 221, 224, 18 })/*, m_Renderable(RawGeometryData{}, m_Material)*/, m_Renderer(renderer) {

		/*m_VAO.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setNoData(m_VBOSize, GL_DYNAMIC_DRAW);

		VertexShader::LayoutData layoutData {
			VertexShader::LayoutDataElement {
				VertexShader::LayoutDataElement::DataType::VECTOR_3F,
				VertexShader::LayoutDataElement::DataName::POSITION
			}
		};

		m_VAO.configureForLayout(layoutData);*/
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

		for (Malachite::Vector3f& point : m_Points) {
			pointsAsFloats.push_back(point.x);
			pointsAsFloats.push_back(point.y);
			pointsAsFloats.push_back(point.z);
		}

		RawGeometryData geoData{};
		geoData.setData(pointsAsFloats);

		//m_Renderable.setGeometryData(geoData);

		//m_Renderer->render(m_Renderable);

		m_Points.clear();
		/*if (pointsAsFloats.size() > 0) {
			m_VAO.bind();
			m_VertexBuffer.setPartialData(pointsAsFloats, 0);

			m_VertexBuffer.bind();
			ShaderLibrary::get().solidShader.use();
			ShaderProgramUploads::upload("objectColour", Colour{ 221, 224, 18 });
			glDrawArrays(GL_LINES, 0, (GLsizei)m_Points.size());

			glCheckError();
			m_Points.clear();
		}*/
	}
}