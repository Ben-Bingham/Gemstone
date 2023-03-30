#pragma once
#include "Rendering/Geometry/MeshData.h"
#include "Rendering/Materials/MaterialData.h"

#include "Utility/Transform.h"

namespace Gem {
	class Renderable { //TODO remove and replace with Tuple
	public:
		Renderable(MeshData& mesh, MaterialData& material, Transform& transfrom);
		//Renderable(const Ptr<MeshData>& mesh, const Ptr<MaterialData>& material, const Ptr<Transform> transform = CreatePtr<Transform>());

		/*Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;*/

		//virtual void render(const Matrix4f& view, const Matrix4f& projection);

		//void setMaterial(const Ptr<MaterialData>& material);

		MeshData& mesh() { return m_Mesh; }
		MaterialData& material() { return m_Material; }
		Transform& transform() { return m_Transform; }

	protected:
		MeshData& m_Mesh;
		MaterialData& m_Material;
		Transform& m_Transform;

		/*Ptr<MeshData> m_Mesh;
		Ptr<MaterialData> m_Material;
		Ptr<Transform> m_Transform;*/
	};
}