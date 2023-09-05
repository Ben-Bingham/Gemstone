#pragma once
#include "Utility/Pointer.h"
#include "Rendering/Shaders/Shader.h"

namespace Gem {
	class IMaterial {
	public:
		IMaterial(const Ptr<Shader>& shader, const Ptr<Shader>& instancedShader);
		IMaterial(const IMaterial& other) = default;
		IMaterial(IMaterial&& other) noexcept = default;
		IMaterial& operator=(const IMaterial& other) = default;
		IMaterial& operator=(IMaterial&& other) noexcept = default;
		virtual ~IMaterial() = default;

		virtual void Apply();
		virtual void Remove();

		virtual void InstancedApply();
		virtual void InstancedRemove();

		Ptr<Shader> shader;
		Ptr<Shader> instancedShader;
	};
}