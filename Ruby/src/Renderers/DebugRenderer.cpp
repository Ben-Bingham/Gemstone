#include "DebugRenderer.h"
#include "Renderer.h"
#include "OpenGlErrors.h"

#include "Geometry/Mesh.h"

namespace Ruby {
	DebugRenderer::DebugRenderer(Renderer* renderer) 
		: m_Mesh(createPtr<Mesh>())
		, m_Material(createPtr<SolidMaterial>(Colour{ 221, 224, 18 }))
		, m_Renderable(m_Mesh, m_Material)
		, m_Renderer(renderer) {

		m_Mesh->setDrawMode(Mesh::DrawMode::LINES);
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

	void DebugRenderer::queue(const Ptr<Mesh>& mesh, const Malachite::Vector3f& position, const Malachite::Vector3f& scale) {
		const Vertices vertices = mesh->getVertices();

		if (vertices.empty()) {
			LOG("Empty mesh supplied, noting will be queued.", Lazuli::LogLevel::WARNING);
			return;
		}

		Malachite::Matrix4f transformMatrix{ 1.0f };
		transformMatrix.translate(position).scale(scale);

		std::vector<Malachite::Vector3f> points;
		for (const Vertex& vertex : vertices) {
			const Malachite::Vector3f vector = Malachite::Vector3f{ Malachite::Vector4f{vertex.position, 1.0f} *transformMatrix };
			points.push_back(vector);
		}

		queue(points);
	}

	void DebugRenderer::render() {
		const std::vector<float> pointsAsFloats = *(std::vector<float>*)(void*)&m_Points;
		Vertices vertices{};
		vertices.resize(pointsAsFloats.size() / 3);
		
		size_t j = 0;
		for (size_t i = 0; i < vertices.size(); i++) {
			vertices[i].position.x = pointsAsFloats[j];
			vertices[i].position.y = pointsAsFloats[j + 1];
			vertices[i].position.z = pointsAsFloats[j + 2];
			j += 3;
		}
		
		if (!vertices.empty() && m_Mesh->getVertices() != vertices) {
			m_Mesh->edit(vertices);
		}
		
		Indices indices{};
		
		for (unsigned int i = 0; i < vertices.size(); i++) {
			indices.emplace_back(i);
		}
		
		if (!indices.empty() && m_Mesh->getIndices() != indices) {
			m_Mesh->edit(indices);
		}
		
		m_Renderer->render(m_Renderable);
		
		m_Points.clear();
	}
}