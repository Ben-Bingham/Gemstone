#pragma once

#include "Shaders/ShaderProgram.h"

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "OpenGL objects/ElementBufferObject.h"
#include "Geometry/GeometryData.h"
#include "Materials/Material.h"

namespace Ruby {
	class Renderable {
	public:
		Renderable(GeometryData& geometry, Material& material);

		Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;

		virtual void render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const;

		Malachite::Matrix4f& getModelMatrix();

	protected:
		VertexAttributeObject m_VAO{ };
		VertexBufferObject m_VBO{ };
		ElementBufferObject m_EBO{ };
		
		Material* m_Material;
		GeometryData* m_GeometryData;

		Malachite::Matrix4f m_ModelMatrix{ 1.0f }; // TODO replace with a transform class
	};
}