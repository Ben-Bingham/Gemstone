#include "Rendering/Materials/SolidColour.h"

namespace Gem {
	SolidColour_::SolidColour_(const Colour& colour)
		: colour(colour) {
		if (!m_SolidColourShader) {
			m_SolidColourShader = CreateUPtr<Shader>("engineAssets/shaders/SolidColour.vert", "engineAssets/shaders/SolidColour.frag");
		}
	}

	void SolidColour_::Apply() {
		m_SolidColourShader->Bind();

		m_SolidColourShader->Upload("u_Colour", colour.ToVec4f());
	}

	UPtr<Shader> SolidColour_::m_SolidColourShader;

}