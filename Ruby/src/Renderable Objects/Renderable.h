#pragma once

#include "Pointer.h"
#include "Shaders/ShaderProgram.h"
#include "Materials/MaterialData.h"
#include "Geometry/MeshData.h"
#include "Utility/Transform.h"

namespace Ruby {
	class Renderable { //TODO remove and replace with Tuple
	public:
		Renderable(MeshData& mesh, MaterialData& material, Malachite::Transform& transfrom);
		//Renderable(const Celestite::Ptr<MeshData>& mesh, const Celestite::Ptr<MaterialData>& material, const Celestite::Ptr<Malachite::Transform> transform = Celestite::CreatePtr<Malachite::Transform>());

		/*Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;*/

		//virtual void render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection);

		//void setMaterial(const Celestite::Ptr<MaterialData>& material);

		MeshData& mesh() { return m_Mesh; }
		MaterialData& material() { return m_Material; }
		Malachite::Transform& transform() { return m_Transform; }

	protected:
		MeshData& m_Mesh;
		MaterialData& m_Material;
		Malachite::Transform& m_Transform;

		/*Celestite::Ptr<MeshData> m_Mesh;
		Celestite::Ptr<MaterialData> m_Material;
		Celestite::Ptr<Malachite::Transform> m_Transform;*/
	};
}