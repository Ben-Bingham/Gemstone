#include "GeometryInstances.h"

namespace Ruby {
	Ptr<GeometryInstance> GeometryInstances::get(const Ptr<GeometryData>& geometryData, VertexShader::LayoutData layoutData) {
		for (const Ptr<GeometryInstance>& instance : m_GeometryInstances) {
			if (instance->getDataLayout() == layoutData && &instance->getGeometryData() == geometryData.get()) {
				return instance;
			}
		}

		m_GeometryInstances.emplace_back(createPtr<GeometryInstance>(geometryData, layoutData));
		return m_GeometryInstances.back();
	}
}