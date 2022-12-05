#include "Renderable.h"

namespace Ruby {
	Renderable::Renderable(const Ptr<Mesh>& mesh, const Ptr<Material>& material)
		: m_Mesh(mesh), m_Material(material) {

	}

	Malachite::Matrix4f& Renderable::getModelMatrix() {
		return m_ModelMatrix;
	}

	void Renderable::setMaterial(const Ptr<Material>& material) {
		m_Material = material;
	}

	void Renderable::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const {
		m_Mesh->bind();

		m_Material->use(m_ModelMatrix, view, projection);
		glDrawElements((GLenum)(int)m_Mesh->getDrawMode(), (GLsizei)m_Mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}
}