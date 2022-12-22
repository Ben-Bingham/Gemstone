#pragma once

#include "Pointer.h"
#include "Shaders/ShaderProgram.h"
#include "Materials/Material.h"
#include "Geometry/Mesh.h"
#include "Utility/Transform.h"

namespace Ruby {
	class Renderable {
	public:
		Renderable(const Celestite::Ptr<Mesh>& mesh, const Celestite::Ptr<Material>& material);

		Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;

		virtual void render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection);

		void setMaterial(const Celestite::Ptr<Material>& material);

		[[nodiscard]] Malachite::Transform& transform() const { return *m_Transform; }

	protected:
		Celestite::Ptr<Mesh> m_Mesh;
		Celestite::Ptr<Material> m_Material;
		Celestite::Ptr<Malachite::Transform> m_Transform{ Celestite::createPtr<Malachite::Transform>() };
	};
}