#include "pch.h"
#include "Renderable.h"

namespace Ruby {
	Renderable::Renderable(MeshData& mesh, MaterialData& material, Malachite::Transform& transform) 
		: m_Mesh(mesh), m_Material(material), m_Transform(transform) {

	}

	/*Renderable::Renderable(const Celestite::Ptr<MeshData>& mesh, const Celestite::Ptr<MaterialData>& material, const Celestite::Ptr<Malachite::Transform> transform)
		: m_Mesh(mesh), m_Material(material), m_Transform(transform) {

	}*/

	/*void Renderable::setMaterial(const Celestite::Ptr<MaterialData>& material) {
		m_Material = material;
	}*/

	/*void Renderable::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) {
		m_Mesh->bind();

		m_Material->use(m_Transform->getModelMatrix(), view, projection);
		glDrawElements((GLenum)(int)m_Mesh->getDrawMode(), (GLsizei)m_Mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}*/
}