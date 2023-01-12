// #pragma once
// #include "Pointer.h"
//
// #include "Component.h"
//
// #include "Geometry/Mesh.h"
//
// namespace Emerald {
// 	class MeshComponent : public Esperite::Component {
// 	public:
// 		template<typename ... Args>
// 		MeshComponent(Args&& ... args)
// 			: m_Mesh(Celestite::createPtr<Ruby::Mesh>(std::forward<Args>(args)...)) {
//
// 		}
//
// 		MeshComponent(Celestite::Ptr<Ruby::Mesh> mesh);
//
// 		Celestite::Ptr<Ruby::Mesh>& mesh() { return m_Mesh; }
//
// 	private:
// 		Celestite::Ptr<Ruby::Mesh> m_Mesh;
// 	};
// }