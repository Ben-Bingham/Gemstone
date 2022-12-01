#pragma once

#include "Shaders/ShaderProgram.h"

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "OpenGL objects/ElementBufferObject.h"
#include "Geometry/GeometryData.h"
#include "Materials/Material.h"

#include "OpenGL objects/GlBuffer.h"

namespace Ruby {
	class Renderable {
	public:
		Renderable(const GeometryData& geometry, Material& material);

		Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;

		virtual void render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const;

		void setMaterial(Material& material);

		Malachite::Matrix4f& getModelMatrix();

		void setGeometryData(const GeometryData& geometry);

	protected:
		VertexAttributeObject m_VAO{ };
		VertexBuffer m_VertexBuffer;
		IndexBuffer m_IndexBuffer{ };
		
		Material* m_Material;
		//GeometryData* m_GeometryData;

		Malachite::Matrix4f m_ModelMatrix{ 1.0f }; // TODO replace with a transform class
	};
}