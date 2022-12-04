#include "GeometryInstances.h"

namespace Ruby {
	GeometryInstance& GeometryInstances::get(const Ptr<GeometryData>& geometryData, VertexShader::LayoutData layoutData) {
		for (const UPtr<GeometryInstance>& instance : m_GeometryInstances) {
			if (instance->getDataLayout() == layoutData && &instance->getGeometryData() == geometryData.get()) {
				return *instance;
			}
		}

		m_GeometryInstances.emplace_back(createUPtr<GeometryInstance>(geometryData, layoutData));
		return *m_GeometryInstances.back();
	}
}