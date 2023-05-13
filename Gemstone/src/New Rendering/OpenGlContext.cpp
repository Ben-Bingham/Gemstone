#include "pch.h"

#include "OpenGlContext.h"

#include "Utility/OpenGlError.h"

namespace Gem {
	void OpenGlContext::StartUp() {
		if (glewInit() != GLEW_OK) {
			LOG("GLEW failed to be initialized", Gem::LogLevel::TERMINAL);
		}

		int flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

		if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
			LOG("OpenGL debug context available.", LogLevel::INFO);
			glEnable(GL_DEBUG_OUTPUT);
			glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
			glDebugMessageCallback(GlErrorCallback, nullptr);
			glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
		}

		CheckErrors();
	}

	void OpenGlContext::ShutDown() { }

	void OpenGlContext::CheckErrors() {
#ifdef GEMSTONE_CHECK_OPEN_GL_ERRORS
		const GLenum error = glGetError();

		switch (error) {
		case GL_NO_ERROR:
			return;
		case GL_INVALID_ENUM:
			LOG("Invalid Enum"); //TODO log system needs a rework allowing this to include file and line number
			break;
		case GL_INVALID_VALUE:
			LOG("Invalid Value");
			break;
		case GL_INVALID_OPERATION:
			LOG("Invalid Operation");
			break;
		case GL_STACK_OVERFLOW:
			LOG("Stack Overflow");
			break;
		case GL_STACK_UNDERFLOW:
			LOG("Stack Underflow");
			break;
		case GL_OUT_OF_MEMORY:
			LOG("Out of memory");
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			LOG("Invalid Frambuffer Operation");
			break;
		default:
			LOG("Unknown Error Code: " + std::to_string(error));
			break;
		}
#endif
	}

	void OpenGlContext::Clear() {
		const Vector4f floatColour{ clearColour.ToVec4f() };

		glClearColor(floatColour.x, floatColour.y, floatColour.z, floatColour.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		CheckErrors();
	}

	OpenGlContext::GlType::GlType(GlTypeName type, size_t elementCount)
		: type(type), componentCount(elementCount), byteCount(BytesPerGlType(type) * elementCount) {
		
	}

	size_t OpenGlContext::BytesPerGlType(const GlTypeName type) {
		switch (type) {
		case GlTypeName::FLOAT:				return sizeof(float);
		case GlTypeName::UNSIGNED_INT:		return sizeof(unsigned int);
		case GlTypeName::INT:				return sizeof(int);
		case GlTypeName::BYTE:				return sizeof(char);
		case GlTypeName::UNSIGNED_BYTE:		return sizeof(unsigned char);
		}

		LOG("Unkown GlTypeName, probably needs to be added");
		return -1;
	}

	// Textures:
	TextureHandle OpenGlContext::GenerateTexture() {
		TextureHandle handle;
		glGenTextures(1, &handle);

		CheckErrors();

		return handle;
	}

	void OpenGlContext::DeleteTexture(TextureHandle handle) {
		glDeleteTextures(1, &handle);

		CheckErrors();
	}

	void OpenGlContext::BindTexture2D(const TextureHandle handle) {
		if (m_BoundTexture == handle) {
			return;
		}

		glBindTexture(GL_TEXTURE_2D, handle);
		m_BoundTexture = handle;

		CheckErrors();
	}

	void OpenGlContext::ConfigureTexture2D(const TextureHandle handle, const WrapMode wrapMode, const FilterMode filterMode) {
		BindTexture2D(handle);

		GLint glWrapMode{ GL_REPEAT };

		switch (wrapMode) {
		case WrapMode::REPEAT: glWrapMode = GL_REPEAT; break;
		case WrapMode::MIRRORED_REPEAT: glWrapMode = GL_MIRRORED_REPEAT; break;
		case WrapMode::CLAMP_TO_EDGE: glWrapMode = GL_CLAMP_TO_EDGE; break;
		case WrapMode::CLAMP_TO_BORDER: glWrapMode = GL_CLAMP_TO_BORDER; break;
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, glWrapMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, glWrapMode);

		GLint glFilterMode{ GL_NEAREST };

		switch (filterMode) {
		case FilterMode::NEAREST: glFilterMode = GL_NEAREST; break;
		case FilterMode::LINEAR: glFilterMode = GL_LINEAR; break;
		}

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glFilterMode);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glFilterMode);

		CheckErrors();
	}

	void OpenGlContext::AssignTextureData2D(TextureHandle handle, const Image& image) {
		BindTexture2D(handle);

		GLint channelFormat{ 0 };
		if (image.channels == 3) {
			channelFormat = GL_RGB;
		}
		else if (image.channels == 4) {
			channelFormat = GL_RGBA;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, channelFormat, image.dimensions.x, image.dimensions.y, 0, channelFormat, GL_UNSIGNED_BYTE, image.content.data());

		CheckErrors();
	}

	void OpenGlContext::GenerateMipMaps2D(TextureHandle handle) {
		BindTexture2D(handle);

		glGenerateMipmap(GL_TEXTURE_2D);

		CheckErrors();
	}

	// Buffers:
	BufferHandle OpenGlContext::GenerateBuffer() {
		BufferHandle handle;
	
		glGenBuffers(1, &handle);
	
		CheckErrors();
	
		return handle;
	}

	void OpenGlContext::DeleteBuffer(BufferHandle handle) {
		glDeleteBuffers(1, &handle);

		CheckErrors();
	}

	void OpenGlContext::BindBuffer(BufferHandle handle, BufferType type) {
		// if (m_BoundBuffer == handle) {
		// 	return;
		// }

		glBindBuffer((GLenum)type, handle);
		m_BoundBuffer = handle;

		CheckErrors();
	}

	void OpenGlContext::SetBufferData(BufferHandle handle, const BufferType type, const void* data, const size_t dataSize, const BufferAccessFrequency accessFrequency, const BufferNatureOfAccess natureOfAccess) {
		BindBuffer(handle, type);

		const int usage = BufferAccessToInt(accessFrequency, natureOfAccess);

		glBufferData((GLenum)type, (unsigned int)dataSize, data, usage);

		CheckErrors();
	}

	void OpenGlContext::ModifyBufferData(BufferHandle handle, const BufferType type, const void* data, const size_t dataSize, const size_t byteOffset) {
		BindBuffer(handle, type);

		glBufferSubData((GLenum)type, (unsigned int)byteOffset, (unsigned int)dataSize, data);

		CheckErrors();
	}

	int OpenGlContext::BufferAccessToInt(const BufferAccessFrequency accessFrequency, const BufferNatureOfAccess natureOfAccess) const {
		switch (accessFrequency) {
		case BufferAccessFrequency::STREAM:
			switch (natureOfAccess) {
			case BufferNatureOfAccess::DRAW:
				return GL_STREAM_DRAW;
			case BufferNatureOfAccess::READ:
				return GL_STREAM_READ;
			case BufferNatureOfAccess::COPY:
				return GL_STREAM_COPY;
			}
			break;
		case BufferAccessFrequency::STATIC:
			switch (natureOfAccess) {
			case BufferNatureOfAccess::DRAW:
				return GL_STATIC_DRAW;
			case BufferNatureOfAccess::READ:
				return GL_STATIC_READ;
			case BufferNatureOfAccess::COPY:
				return GL_STATIC_COPY;
			}
			break;
		case BufferAccessFrequency::DYNAMIC:
			switch (natureOfAccess) {
			case BufferNatureOfAccess::DRAW:
				return GL_DYNAMIC_DRAW;
			case BufferNatureOfAccess::READ:
				return GL_DYNAMIC_READ;
			case BufferNatureOfAccess::COPY:
				return GL_DYNAMIC_COPY;
			}
			break;
		}

		LOG("Unknown buffer access combination");
		return -1;
	}

	// Vertex Attribute Object
	VertexAttributeObjectHandle OpenGlContext::GenerateVertexAttributeObject() {
		VertexAttributeObjectHandle handle;

		glGenVertexArrays(1, &handle);

		CheckErrors();

		return handle;
	}

	void OpenGlContext::DeleteVertexAttributeObject(VertexAttributeObjectHandle handle) {
		glDeleteVertexArrays(1, &handle);

		CheckErrors();
	}

	void OpenGlContext::BindVertexAttributeObject(VertexAttributeObjectHandle handle) {
		if (m_BoundVertexAttributeObject == handle) {
			return;
		}

		glBindVertexArray(handle);

		m_BoundVertexAttributeObject = handle;

		CheckErrors();
	}

	void OpenGlContext::CreateAttributePointer(VertexAttributeObjectHandle handle, const size_t index, GlType type, const size_t stride, const size_t offset) {
		BindVertexAttributeObject(handle);

		EnableVertexAttributeIndex(index);

		glVertexAttribPointer((GLuint)index, (GLint)type.componentCount, (GLenum)type.type, GL_FALSE, (GLint)stride, (void*)offset);

		CheckErrors();
	}

	void OpenGlContext::DeleteAttributePointer(VertexAttributeObjectHandle handle, const size_t index) {
		DisableVertexAttributeIndex(index);
	}

	void OpenGlContext::EnableVertexAttributeIndex(const size_t index) {
		glEnableVertexAttribArray((unsigned int)index);

		CheckErrors();
	}

	void OpenGlContext::DisableVertexAttributeIndex(const size_t index) {
		glDisableVertexAttribArray((unsigned int)index);

		CheckErrors();
	}

	// Shaders
	ShaderHandle OpenGlContext::CreateShader(ShaderType type) {
		const ShaderHandle shader = glCreateShader((GLenum)type);

		CheckErrors();

		return shader;
	}

	void OpenGlContext::AttachShaderSource(ShaderHandle shader, const std::string& shaderSource) {
		const char* charShaderSource = shaderSource.c_str();
		glShaderSource(shader, 1, &charShaderSource, nullptr);

		CheckErrors();
	}

	void OpenGlContext::CompileShader(ShaderHandle shader) {
		glCompileShader(shader);

		int success;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			LOG("Shader failed to compile.\n" + std::string(infoLog), LogLevel::ERROR);
		}

		CheckErrors();
	}

	ShaderProgramHandle OpenGlContext::CreateShaderProgram() {
		ShaderProgramHandle shaderProgram = glCreateProgram();

		CheckErrors();

		return shaderProgram;
	}

	void OpenGlContext::AttachShaderToProgram(ShaderProgramHandle shaderProgram, ShaderHandle shader) {
		glAttachShader(shaderProgram, shader);

		CheckErrors();
	}

	void OpenGlContext::BindShaderProgram(ShaderProgramHandle shaderProgram) {
		// if (m_BoundShaderProgram == shaderProgram) {
		// 	return;
		// }

		glUseProgram(shaderProgram);
		m_BoundShaderProgram = shaderProgram;

		CheckErrors();
	}

	void OpenGlContext::CompileShaderProgram(ShaderProgramHandle shaderProgram) {
		glLinkProgram(shaderProgram);

		int success;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
			LOG("Shader program failed to compile.\n" + std::string(infoLog), LogLevel::ERROR);
		}

		CheckErrors();
	}

	// Rendering
	void OpenGlContext::DrawElements(const size_t indexCount) {
		glDrawElements(GL_TRIANGLES, (int)indexCount, GL_UNSIGNED_INT, 0);

		CheckErrors();
	}
}