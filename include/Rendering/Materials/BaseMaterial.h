#pragma once

namespace Gem {
	class BaseMaterial {
	public:
		BaseMaterial() = default;
		BaseMaterial(const BaseMaterial& other) = default;
		BaseMaterial(BaseMaterial&& other) noexcept = default;
		BaseMaterial& operator=(const BaseMaterial& other) = default;
		BaseMaterial& operator=(BaseMaterial&& other) noexcept = default;
		virtual ~BaseMaterial() = default;

		virtual void Apply() = 0;
	};
}