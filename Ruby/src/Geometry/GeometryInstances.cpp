#include "GeometryInstances.h"

namespace Ruby {
	GeometryInstance& GeometryInstances::get(const Ptr<GeometryData>& geometryData, VertexShader::LayoutData layoutData) {
		for (const std::unique_ptr<GeometryInstance>& instance : m_GeometryInstances) {
			if (instance->getDataLayout() == layoutData && &instance->getGeometryData() == geometryData.get()) {
				return *instance;
			}
		}

		m_GeometryInstances.emplace_back(std::make_unique<GeometryInstance>(geometryData, layoutData));
		return *m_GeometryInstances.back();
	}
}