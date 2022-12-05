#pragma once

#include "Pointer.h"

#include "Shaders/ShaderProgram.h"

#include "Geometry/GeometryData.h"
#include "Materials/Material.h"

#include "Geometry/GeometryInstance.h"

namespace Ruby {
	class Renderable {
	public:
		Renderable(const Ptr<GeometryData>& geometryData, const Ptr<Material>& material);

		Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;

		virtual void render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const;

		void setMaterial(const Ptr<Material>& material);
		void setGeometryData(const Ptr<GeometryData>& geometryData);
		void setGeometryInstance(const Ptr<GeometryInstance>& geometryInstance);

		Malachite::Matrix4f& getModelMatrix();

	protected:
		Ptr<GeometryInstance> m_GeometryInstance;
		
		Ptr<Material> m_Material;

		Malachite::Matrix4f m_ModelMatrix{ 1.0f }; // TODO replace with a transform class
	};
}