#pragma once
#include <vector>

#include <GL/glew.h>
#include <Vector.h>

#include "Log.h"

namespace Ruby {
	template<typename T, int BufferType>
	class GlBuffer {
	public:
		GlBuffer()
			: m_BufferAddress(0) {
			glGenBuffers(1, &m_BufferAddress);
		}

		template<typename ...Type>
		explicit GlBuffer(Type&&... args)
			: m_BufferAddress(0) {
			glGenBuffers(1, &m_BufferAddress);

			setData(args...);
		}

		GlBuffer(const GlBuffer& other) = delete;

		GlBuffer(GlBuffer&& other) noexcept
			: m_BufferAddress(other.m_BufferAddress) {}

		GlBuffer& operator=(const GlBuffer& other) = delete;

		GlBuffer& operator=(GlBuffer&& other) noexcept {
			if (this == &other)
				return *this;
			m_BufferAddress = other.m_BufferAddress;
			return *this;
		}

		~GlBuffer() {
			glDeleteBuffers(1, &m_BufferAddress);
		}

		void setData(const std::vector<T>& data, const int usage = GL_STATIC_DRAW) {
			bind();

#ifdef RUBY_DEBUG
			if (m_Initialized) {
				LOG("Attempting to place data into preinitilized buffer. Please use setSubData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif

			m_Size = data.size() * sizeof(T);
			glBufferData(BufferType, m_Size, data.data(), usage);
#ifdef RUBY_DEBUG
			m_Initialized = true;
			unbind();
#endif
		}

		void setData(const std::vector<Malachite::Vector2<T>>& data, const int usage = GL_STATIC_DRAW) {
			bind();

#ifdef RUBY_DEBUG
			if (m_Initialized) {
				LOG("Attempting to place data into preinitilized buffer. Please use setSubData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif

			constexpr int elementsInVector = 2;
			m_Size = data.size() * sizeof(T) * elementsInVector;
			glBufferData(BufferType, m_Size, data.data(), usage);
#ifdef RUBY_DEBUG
			m_Initialized = true;
			unbind();
#endif
		}

		void setData(const std::vector<Malachite::Vector3<T>>& data, const int usage = GL_STATIC_DRAW) {
			bind();

#ifdef RUBY_DEBUG
			if (m_Initialized) {
				LOG("Attempting to place data into preinitilized buffer. Please use setSubData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif

			constexpr int elementsInVector = 3;
			m_Size = data.size() * sizeof(T) * elementsInVector;
			glBufferData(BufferType, m_Size, data.data(), usage);
#ifdef RUBY_DEBUG
			m_Initialized = true;
			unbind();
#endif
		}

		void setData(const std::vector<Malachite::Vector4<T>>& data, const int usage = GL_STATIC_DRAW) {
			bind();

#ifdef RUBY_DEBUG
			if (m_Initialized) {
				LOG("Attempting to place data into preinitilized buffer. Please use setSubData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif

			constexpr int elementsInVector = 4;
			m_Size = data.size() * sizeof(T) * elementsInVector;
			glBufferData(BufferType, m_Size, data.data(), usage);
#ifdef RUBY_DEBUG
			m_Initialized = true;
			unbind();
#endif
		}

		void setSubData(const std::vector<T>& data, const unsigned int offset = 0) {
#ifdef RUBY_DEBUG
			if (!m_Initialized) {
				LOG("Attempting to place data into a buffer that has not been initilized yet. Please use setData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif
			const size_t dataSize = data.size() * sizeof(T);
#ifdef RUBY_DEBUG
			if (dataSize > m_Size || dataSize + offset > m_Size) {
				LOG("Attempted to modify data outside of buffer range, operation not possible.", Lazuli::LogLevel::ERROR);
			}
#endif
			bind();
			glBufferSubData(BufferType, offset, dataSize, data.data());
#ifdef RUBY_DEBUG
			unbind();
#endif
		}

		void setSubData(const std::vector<Malachite::Vector2<T>>& data, const unsigned int offset = 0) {
#ifdef RUBY_DEBUG
			if (!m_Initialized) {
				LOG("Attempting to place data into a buffer that has not been initilized yet. Please use setData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif
			constexpr int elementsInVector = 2;
			const size_t dataSize = data.size() * sizeof(T) * elementsInVector;
#ifdef RUBY_DEBUG
			if (dataSize > m_Size || dataSize + offset > m_Size) {
				LOG("Attempted to modify data outside of buffer range, operation not possible.", Lazuli::LogLevel::ERROR);
			}
#endif
			bind();
			glBufferSubData(BufferType, offset, dataSize, data.data());
#ifdef RUBY_DEBUG
			unbind();
#endif
		}

		void setSubData(const std::vector<Malachite::Vector3<T>>& data, const unsigned int offset = 0) {
#ifdef RUBY_DEBUG
			if (!m_Initialized) {
				LOG("Attempting to place data into a buffer that has not been initilized yet. Please use setData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif
			constexpr int elementsInVector = 3;
			const size_t dataSize = data.size() * sizeof(T) * elementsInVector;
#ifdef RUBY_DEBUG
			if (dataSize > m_Size || dataSize + offset > m_Size) {
				LOG("Attempted to modify data outside of buffer range, operation not possible.", Lazuli::LogLevel::ERROR);
			}
#endif
			bind();
			glBufferSubData(BufferType, offset, dataSize, data.data());
#ifdef RUBY_DEBUG
			unbind();
#endif
		}

		void setSubData(const std::vector<Malachite::Vector4<T>>& data, const unsigned int offset = 0) {
#ifdef RUBY_DEBUG
			if (!m_Initialized) {
				LOG("Attempting to place data into a buffer that has not been initilized yet. Please use setData() instead.", Lazuli::LogLevel::WARNING);
			}
#endif
			constexpr int elementsInVector = 4;
			const size_t dataSize = data.size() * sizeof(T) * elementsInVector;
#ifdef RUBY_DEBUG
			if (dataSize > m_Size || dataSize + offset > m_Size) {
				LOG("Attempted to modify data outside of buffer range, operation not possible.", Lazuli::LogLevel::ERROR);
			}
#endif
			bind();
			glBufferSubData(BufferType, offset, dataSize, data.data());
#ifdef RUBY_DEBUG
			unbind();
#endif
		}

	private:
		void bind() const {
			if (m_BoundBuffer == this) {
				return;
			}
			glBindBuffer(BufferType, m_BufferAddress);
			m_BoundBuffer = this;
		}

		static void unbind() {
			m_BoundBuffer = nullptr;
			glBindBuffer(BufferType, 0);
		}

		unsigned int m_BufferAddress;

		size_t m_Size{ 0 }; // Number of bytes allocated to the buffer

		static inline const GlBuffer<T, BufferType>* m_BoundBuffer{ nullptr };

#ifdef RUBY_DEBUG
		bool m_Initialized{ false };
#endif
	};

	using VertexBuffer = GlBuffer<float, GL_ARRAY_BUFFER>;
	using IndexBuffer = GlBuffer<unsigned int, GL_ELEMENT_ARRAY_BUFFER>;
}