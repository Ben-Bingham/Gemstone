#pragma once

namespace Ruby {
	class RenderingContext {
	public:
		RenderingContext(const RenderingContext& other) = delete;
		RenderingContext(RenderingContext&& other) noexcept = delete;
		RenderingContext& operator=(const RenderingContext& other) = delete;
		RenderingContext& operator=(RenderingContext&& other) noexcept = delete;
		~RenderingContext() = default;

		static RenderingContext& Get();
		void Init();

	private:
		RenderingContext() = default;

		bool m_Initialized{ false };
	};
}