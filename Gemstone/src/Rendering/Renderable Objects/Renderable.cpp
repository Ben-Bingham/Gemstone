#include "pch.h"
#include "Renderable.h"

namespace Gem {
	Renderable::Renderable(MeshData& mesh, MaterialData& material, Transform& transform) 
		: m_Mesh(mesh), m_Material(material), m_Transform(transform) {

	}

	/*Renderable::Renderable(const Ptr<MeshData>& mesh, const Ptr<MaterialData>& material, const Ptr<Transform> transform)
		: m_Mesh(mesh), m_Material(material), m_Transform(transform) {

	}*/

	/*void Renderable::setMaterial(const Ptr<MaterialData>& material) {
		m_Material = material;
	}*/

	/*void Renderable::render(const Matrix4f& view, const Matrix4f& projection) {
		m_Mesh->bind();

		m_Material->use(m_Transform->getModelMatrix(), view, projection);
		glDrawElements((GLenum)(int)m_Mesh->getDrawMode(), (GLsizei)m_Mesh->getIndexCount(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}*/
}