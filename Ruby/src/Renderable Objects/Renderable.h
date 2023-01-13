#pragma once

#include "Pointer.h"
#include "Shaders/ShaderProgram.h"
#include "Materials/Material.h"
#include "Geometry/Mesh.h"
#include "Utility/Transform.h"

namespace Ruby {
	class Renderable {
	public:
		Renderable(Mesh& mesh, Material& material, Malachite::Transform& transfrom);
		//Renderable(const Celestite::Ptr<Mesh>& mesh, const Celestite::Ptr<Material>& material, const Celestite::Ptr<Malachite::Transform> transform = Celestite::createPtr<Malachite::Transform>());

		/*Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;*/

		//virtual void render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection);

		//void setMaterial(const Celestite::Ptr<Material>& material);

		Mesh& mesh() { return m_Mesh; }
		Material& material() { return m_Material; }
		Malachite::Transform& transform() { return m_Transform; }

	protected:
		Mesh& m_Mesh;
		Material& m_Material;
		Malachite::Transform& m_Transform;

		/*Celestite::Ptr<Mesh> m_Mesh;
		Celestite::Ptr<Material> m_Material;
		Celestite::Ptr<Malachite::Transform> m_Transform;*/
	};
}