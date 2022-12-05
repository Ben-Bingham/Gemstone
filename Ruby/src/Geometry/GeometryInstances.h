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

		static Ptr<GeometryInstance> get(const Ptr<GeometryData>& geometryData);

	private:
		GeometryInstances() = default;

		inline static std::vector<Ptr<GeometryInstance>> m_GeometryInstances{};
	};
}