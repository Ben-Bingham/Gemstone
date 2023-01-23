#pragma once
// #include "Component.h"
//
// #include "Materials/MaterialData.h"
//
// namespace Emerald {
// 	class MaterialComponent : public Esperite::Component {
// 	public:
// 		template<typename ... Args>
// 		MaterialComponent(Args&& ... args)
// 			: m_Material(Celestite::CreatePtr<Ruby::MaterialData>(std::forward<Args>(args)...)) {
// 			
// 		}
//
// 		MaterialComponent(Celestite::Ptr<Ruby::MaterialData> material);
//
// 		Celestite::Ptr<Ruby::MaterialData>& material() { return m_Material; }
//
// 	private:
// 		Celestite::Ptr<Ruby::MaterialData> m_Material;
// 	};
// }