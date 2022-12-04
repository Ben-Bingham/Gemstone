#include "Renderable.h"

#include "Geometry/GeometryInstances.h"

namespace Ruby {
	Renderable::Renderable(const Ptr<GeometryData>& geometryData, const Ptr<Material>& material)
		: m_GeometryInstance(GeometryInstances::get(geometryData, material->getLayout())), m_Material(material) {

	}

	Malachite::Matrix4f& Renderable::getModelMatrix() {
		return m_ModelMatrix;
	}

	void Renderable::setMaterial(const Ptr<Material>& material) {
		m_Material = material;
	}

	void Renderable::setGeometryData(const GeometryData& geometry) {
		// m_VAO.bind();
		//
		// m_VertexBuffer.bind();
		// std::vector<float> newVertexData = geometry.getVertices(m_Material->getLayout());
		// std::vector<unsigned int> newIndexData = geometry.getIndices();
		//
		// if (newVertexData.size() > 0 && newIndexData.size() > 0 && newIndexData.size() < m_IndexBuffer.getNumberOfIndices()) {
		// 	m_VertexBuffer.setPartialData(newVertexData, 0);
		// 	m_IndexBuffer.setPartialData(newIndexData, 0);
		// }
		// else {
		// 	// TODO
		// }
	}

	void Renderable::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const {
		m_GeometryInstance.use();

		m_Material->use(m_ModelMatrix, view, projection);
		glDrawElements(GL_TRIANGLES, (GLsizei)m_GeometryInstance.getIndexCount(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}
}