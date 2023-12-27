#include "Rendering/Materials/ScreenSpace.h"

namespace Gem {
	ScreenSpace_::ScreenSpace_() {
		if (m_ScreenSpaceShader == nullptr) {
			m_ScreenSpaceShader = CreateUPtr<Shader>("engineAssets/shaders/ScreenSpace.vert", "engineAssets/shaders/ScreenSpace.frag");
		}
	}

	void ScreenSpace_::Apply() {
		m_ScreenSpaceShader->Bind();
	}

	UPtr<Shader>& ScreenSpace_::GetShader() {
		return m_ScreenSpaceShader;
	}

	UPtr<Shader> ScreenSpace_::m_ScreenSpaceShader;

}