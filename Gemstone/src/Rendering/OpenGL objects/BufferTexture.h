#pragma once

#include <GL/glew.h>

#include "GlBuffer.h"
#include "Utility/Log.h"
#include "Utility/Pointer.h"

namespace Gem {
	template <typename T>
	class BufferTexture {
	public:
		BufferTexture()
			: m_BufferAddress(0) {
			glGenTextures(1, &m_BufferAddress);

			if constexpr (std::is_same_v<T, float>) {
				m_DataType = GL_R32F;
			}
			else if constexpr (std::is_same_v<T, unsigned int>) {
				m_DataType = GL_R32UI;
			}
			else if constexpr (std::is_same_v<T, unsigned char>) {
				m_DataType = GL_R8UI;
			}
			else if constexpr (std::is_same_v<T, int>) {
				m_DataType = GL_R32I;
			}
			else if constexpr (std::is_same_v<T, Vector4<unsigned char>>) {
				m_DataType = GL_RGBA8;
			}
			else if constexpr (std::is_same_v<T, Vector4<unsigned int>>) {
				m_DataType = GL_RGBA32UI;
			}
			else if constexpr (std::is_same_v<T, Vector3<unsigned int>>) {
				m_DataType = GL_RGB32I;
			}
			else if constexpr (std::is_same_v<T, Vector3<unsigned char>>) {
				m_DataType = GL_RGB8;
			}
			else {
				m_DataType = 0;
				// LOG("Invalid type given to buffer texture", LogLevel::ERROR); //TODO broken for some reason
			}
		}

		void Bind() const {
			if (m_BoundBuffer == this) {
				return;
			}
			glBindTexture(GL_TEXTURE_BUFFER, m_BufferAddress);
			m_BoundBuffer = this;
		}

		void ForceBind() const {
			glBindTexture(GL_TEXTURE_BUFFER, m_BufferAddress);
			m_BoundBuffer = this;
		}

		static void Unbind() {
			m_BoundBuffer = nullptr;
			glBindTexture(GL_TEXTURE_BUFFER, 0);
		}

		unsigned int GetAddress() const {
			return m_BufferAddress;
		}

		void AssignBuffer(const Ptr<BlankBuffer<T>> buffer) {
			Bind();
#ifdef RUBY_DEBUG
			if (m_Buffer != nullptr) {
				LOG("Buffer already assigned.", LogLevel::ERROR);
			}
#endif
			m_Buffer = buffer;
			glTexBuffer(GL_TEXTURE_BUFFER, m_DataType, buffer->GetAddress());
		}

		~BufferTexture() {
			glDeleteTextures(1, &m_BufferAddress);
		}

	private:
		unsigned int m_BufferAddress;

		Ptr<BlankBuffer<T>> m_Buffer;

		GLenum m_DataType;

		static inline const BufferTexture<T>* m_BoundBuffer{nullptr};
	};
}