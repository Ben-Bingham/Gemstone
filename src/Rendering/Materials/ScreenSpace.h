#pragma once
#include "BaseMaterial.h"

namespace Gem {
	class ScreenSpace_ : public BaseMaterial { // TODO deprecate
	public:
		ScreenSpace_();
		ScreenSpace_(const ScreenSpace_& other) = default;
		ScreenSpace_(ScreenSpace_&& other) noexcept = default;
		ScreenSpace_& operator=(const ScreenSpace_& other) = default;
		ScreenSpace_& operator=(ScreenSpace_&& other) noexcept = default;
		~ScreenSpace_() override = default;

		void Apply() override;
		UPtr<Shader>& GetShader() override;

	private:
		static UPtr<Shader> m_ScreenSpaceShader;
	};

	using ScreenSpace = Ptr<ScreenSpace_>;
}