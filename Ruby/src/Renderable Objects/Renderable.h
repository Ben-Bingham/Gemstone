#pragma once

#include "Shaders/ShaderProgram.h"

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "OpenGL objects/ElementBufferObject.h"
#include "Geometry/GeometryData.h"
#include "Material.h"

namespace Ruby {
	class Renderable {
		using GeometryDataPtr = std::shared_ptr<GeometryData>;
		using MaterialPtr = std::shared_ptr<Material>;
	public:
		Renderable(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::vector<Attribute>& attributes);
		Renderable(const GeometryDataPtr& geometry, const MaterialPtr& material);

		Renderable(const Renderable& other) = delete;
		Renderable(Renderable&& other) noexcept = default;
		Renderable& operator=(const Renderable& other) = delete;
		Renderable& operator=(Renderable&& other) noexcept = default;
		virtual ~Renderable() = default;

		// The assumption is made that a shader program is bound prior to this being called
		virtual void render() const;

	protected:
		VertexAttributeObject m_VAO{ };
		VertexBufferObject m_VBO{ };
		ElementBufferObject m_EBO{ };

		unsigned int m_NumberOfIndices;
		Material* m_Material;
	};
}