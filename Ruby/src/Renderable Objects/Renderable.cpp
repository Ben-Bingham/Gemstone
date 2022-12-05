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

	void Renderable::setGeometryData(const Ptr<GeometryData>& geometryData) {
		m_GeometryInstance = GeometryInstances::get(geometryData, m_Material->getLayout());
	}

	void Renderable::setGeometryInstance(const Ptr<GeometryInstance>& geometryInstance) {
		m_GeometryInstance = geometryInstance;
	}

	void Renderable::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const {
		m_GeometryInstance->use();

		m_Material->use(m_ModelMatrix, view, projection);
		glDrawElements(m_GeometryInstance->getGeometryData().getDrawMode(), (GLsizei)m_GeometryInstance->getIndexCount(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}
}