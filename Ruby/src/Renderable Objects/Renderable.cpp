#include "Renderable.h"

namespace Ruby {
	Renderable::Renderable(const Celestite::Ptr<Mesh>& mesh, const Celestite::Ptr<Material>& material)
		: m_Mesh(mesh), m_Material(material) {

	}

	void Renderable::setMaterial(const Celestite::Ptr<Material>& material) {
		m_Material = material;
	}

	void Renderable::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) {
		m_Mesh->bind();

		m_Material->use(transform().getModelMatrix(), view, projection);
		glDrawElements((GLenum)(int)m_Mesh->getDrawMode(), (GLsizei)m_Mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}
}