#pragma once
#include "Utility/Pointer.h"
#include "Rendering/Shaders/Shader.h"

namespace Gem {
	class IMaterial {
	public:
		IMaterial(const Ptr<Shader>& shader);
		IMaterial(const IMaterial& other) = default;
		IMaterial(IMaterial&& other) noexcept = default;
		IMaterial& operator=(const IMaterial& other) = default;
		IMaterial& operator=(IMaterial&& other) noexcept = default;
		virtual ~IMaterial() = default;

		virtual void Apply();
		virtual void Remove();

		Ptr<Shader> shader;
	};
}