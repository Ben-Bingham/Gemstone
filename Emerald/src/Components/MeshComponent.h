// #pragma once
// #include "Pointer.h"
//
// #include "Component.h"
//
// #include "Geometry/MeshData.h"
//
// namespace Emerald {
// 	class MeshComponent : public Esperite::Component {
// 	public:
// 		template<typename ... Args>
// 		MeshComponent(Args&& ... args)
// 			: m_Mesh(Celestite::CreatePtr<Ruby::MeshData>(std::forward<Args>(args)...)) {
//
// 		}
//
// 		MeshComponent(Celestite::Ptr<Ruby::MeshData> mesh);
//
// 		Celestite::Ptr<Ruby::MeshData>& mesh() { return m_Mesh; }
//
// 	private:
// 		Celestite::Ptr<Ruby::MeshData> m_Mesh;
// 	};
// }