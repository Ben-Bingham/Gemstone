#include "DebugRenderer.h"
#include "Renderer.h"
#include "OpenGlErrors.h"

#include "Geometry/GeometryData.h"
#include "Geometry/RawGeometryData.h"

namespace Ruby {
	DebugRenderer::DebugRenderer(Renderer* renderer) 
		: m_Material(createPtr<SolidMaterial>(Colour{ 221, 224, 18 })), m_Renderable(createPtr<RawGeometryData>(), m_Material), m_Renderer(renderer) {

		m_GeometryInstance->setData(createPtr<RawGeometryData>(GeometryData::DrawMode::LINES));

		m_Renderable.setGeometryInstance(m_GeometryInstance);
	}

	void DebugRenderer::queue(const std::vector<float>& points) {
#ifdef RUBY_DEBUG
		if (points.size() % 3 == 1) {
			LOG("Uneven number of values supplied, this may modify futre queue calls.", Lazuli::LogLevel::WARNING);
		}
#endif
		for (size_t i = 0; i < points.size(); i += 3) {
			m_Points.emplace_back(points[i]);
			m_Points.emplace_back(points[i + 1]);
			m_Points.emplace_back(points[i + 2]);
		}
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

	void DebugRenderer::queue(const Ptr<GeometryData>& geometryData, Malachite::Vector3f position, Malachite::Vector3f scale) {
		const std::vector<float> floatVertices = geometryData->getVertices(m_Material->getLayout());

		std::vector<Malachite::Vector3f> vec3Vertices{};
		for (size_t i = 0; i < floatVertices.size(); i += 3) {
			vec3Vertices.emplace_back(floatVertices[i]);
			vec3Vertices.emplace_back(floatVertices[i + 1]);
			vec3Vertices.emplace_back(floatVertices[i + 2]);
		}

		Malachite::Matrix4f transformMatrix{ 1.0f };
		transformMatrix.translate(position).scale(scale);

		for (Malachite::Vector3f& vector : vec3Vertices) {
			vector = Malachite::Vector3f{ Malachite::Vector4f{ vector, 1.0f } *transformMatrix };
		}

		const std::vector<unsigned int> indices = geometryData->getIndices();

		std::vector<Malachite::Vector3f> finalVertices{ };
		finalVertices.reserve(indices.size());
		for (const unsigned int i : indices) {
			finalVertices.emplace_back(vec3Vertices[i]);
		}

		queue(finalVertices);
	}

	void DebugRenderer::render() {
		const std::vector<float> pointsAsFloats = *(std::vector<float>*)(void*)&m_Points;

		const auto rawGeometricData = createPtr<RawGeometryData>(GeometryData::DrawMode::LINES);
		rawGeometricData->setData(pointsAsFloats);

		m_GeometryInstance->setData(rawGeometricData);

		m_Renderer->render(m_Renderable);

		m_Points.clear();
	}
}