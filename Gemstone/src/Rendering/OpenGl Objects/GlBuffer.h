#pragma once
#include <vector>

#include "Core/Engine.h"
#include "Rendering/OpenGlContext.h"

namespace Gem {
	template<typename StorageType, typename BufferTypeEnum, BufferTypeEnum BufferType>
	class GlBuffer {
	public:
		GlBuffer(
			const OpenGlContext::BufferAccessFrequency accessFrequency = OpenGlContext::BufferAccessFrequency::STATIC,
			const OpenGlContext::BufferNatureOfAccess natureOfAccess = OpenGlContext::BufferNatureOfAccess::DRAW
		) : m_Handle(0
			//g_Engine.openGlContext.GenerateBuffer()
		), m_AccessFrequency(accessFrequency), m_NatureOfAccess(natureOfAccess) {
			Bind();
		}

		GlBuffer(const GlBuffer& other) = delete;
		GlBuffer(GlBuffer&& other) noexcept = default;
		GlBuffer& operator=(const GlBuffer& other) = delete;
		GlBuffer& operator=(GlBuffer&& other) noexcept = default;

		~GlBuffer() {
			//g_Engine.openGlContext.DeleteBuffer(m_Handle);
		}

		void Bind() {
			//g_Engine.openGlContext.BindBuffer(m_Handle, BufferType);
		}

		void SetAllData(const std::vector<StorageType>& data) {
			if (m_Initialized) {
				SetPartialData(data);
				return;
			}

			//g_Engine.openGlContext.SetBufferData(m_Handle, BufferType, data.data(), data.size() * sizeof(StorageType), m_AccessFrequency, m_NatureOfAccess);
		}

		// ElementOffset should be number of StorageTypes you want as offset ex:
		// Buffer contains 10 floats and you want to insert at index 3
		// ElementOffset would be 3, because there are 3 floats before it the ones at index 0, 1, and 2
		void SetPartialData(const std::vector<StorageType>& data, const size_t elementOffset = 0) {
			if (!m_Initialized) {
				SetAllData(data);
				return;
			}

			//g_Engine.openGlContext.ModifyBufferData(m_Handle, BufferType, data.data(), data.size() * sizeof(StorageType), elementOffset * sizeof(StorageType));
		}

		void ReserveSpace(const size_t size) {
			if (m_Initialized) {
				LOG("Cannot reserve space on a buffer that has already been initialized.", LogLevel::ERROR);
				return;
			}

			//g_Engine.openGlContext.SetBufferData(m_Handle, BufferType, nullptr, size, m_AccessFrequency, m_NatureOfAccess);
		}

	private:
		BufferHandle m_Handle;
		OpenGlContext::BufferAccessFrequency m_AccessFrequency;
		OpenGlContext::BufferNatureOfAccess m_NatureOfAccess;
		bool m_Initialized{ false };
	};

	using IndexBuffer = GlBuffer<unsigned int, OpenGlContext::BufferType, OpenGlContext::BufferType::INDEX_BUFFER>;
	using VertexBuffer = GlBuffer<float, OpenGlContext::BufferType, OpenGlContext::BufferType::VERTEX_BUFFER>;
}