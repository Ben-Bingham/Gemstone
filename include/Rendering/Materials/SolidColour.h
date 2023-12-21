#pragma once
#include "BaseMaterial.h"
#include "Rendering/Shaders/Shader.h"
#include "Utility/Colour.h"
#include "Utility/Pointer.h"

namespace Gem {
	class SolidColour_ : public BaseMaterial {
	public:
		SolidColour_(const Colour& colour);
		SolidColour_(const SolidColour_& other) = default;
		SolidColour_(SolidColour_&& other) noexcept = default;
		SolidColour_& operator=(const SolidColour_& other) = default;
		SolidColour_& operator=(SolidColour_&& other) noexcept = default;
		~SolidColour_() override = default;

		void Apply() override;

		Colour colour;
	private:
		static UPtr<Shader> m_SolidColourShader;
	};

	using SolidColour = Ptr<SolidColour_>;
}