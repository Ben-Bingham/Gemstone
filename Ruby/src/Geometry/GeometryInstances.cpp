#include "GeometryInstances.h"

namespace Ruby {
	Ptr<GeometryInstance> GeometryInstances::get(const Ptr<GeometryData>& geometryData) {
		for (const Ptr<GeometryInstance>& instance : m_GeometryInstances) {
			if (&instance->getGeometryData() == geometryData.get()) {
				return instance;
			}
		}

		m_GeometryInstances.emplace_back(createPtr<GeometryInstance>(geometryData));
		return m_GeometryInstances.back();
	}
}