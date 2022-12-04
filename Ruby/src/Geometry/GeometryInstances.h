#pragma once
#include <vector>

#include "GeometryInstance.h"
#include "Pointer.h"

#include "Shaders/VertexShader.h"

namespace Ruby {
	class GeometryInstances {
	public:
		GeometryInstances(const GeometryInstances& other) = delete;
		GeometryInstances& operator=(const GeometryInstances& other) = delete;

		static GeometryInstance& get(const Ptr<GeometryData>& geometryData, VertexShader::LayoutData layoutData);

	private:
		GeometryInstances() = default;

		inline static std::vector<std::unique_ptr<GeometryInstance>> m_GeometryInstances{};
	};
}