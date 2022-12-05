#pragma once

#include "Geometry/RawGeometryData.h"

#include "Materials/SolidMaterial.h"
#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class Renderer;

	class DebugRenderer {
	public:
		DebugRenderer(Renderer* renderer);

		void queue(const std::vector<float>& points);
		void queue(const std::vector<Malachite::Vector3f>& points);
		void queue(const Ptr<GeometryData>& geometryData, Malachite::Vector3f position = Malachite::Vector3f{ 0.0f }, Malachite::Vector3f scale = Malachite::Vector3f{ 1.0f });

		void render();

	private:
		std::vector<Malachite::Vector3f> m_Points;
		Ptr<SolidMaterial> m_Material;
		Renderable m_Renderable;
		Ptr<GeometryInstance> m_GeometryInstance{ createPtr<GeometryInstance>(createPtr<RawGeometryData>()) };
		Renderer* m_Renderer{ nullptr };
	};
}