#include "pch.h"

#include "OpenGlContext.h"
#include <iostream>

#include "Utility/OpenGlError.h"

namespace Gem {
	void CheckErrors(const char* filePath, const int lineNumber) {
		const bool filePathBackup{ Logger::g_FilePath };
		const bool lineNumberBackup{ Logger::g_LineNumber };
		const bool logLevelBackup{ Logger::g_LogLevel };

		Logger::g_FilePath = false;
		Logger::g_LineNumber = false;
		Logger::g_LogLevel = false;

		std::string errorMessage{};

		switch (const GLenum error = glGetError()) {
		case GL_NO_ERROR:
			return;
		case GL_INVALID_ENUM:
			errorMessage += "Invalid Enum";
			break;
		case GL_INVALID_VALUE:
			errorMessage += "Invalid Value";
			break;
		case GL_INVALID_OPERATION:
			errorMessage += "Invalid Operation";
			break;
		case GL_STACK_OVERFLOW:
			errorMessage += "Stack Overflow";
			break;
		case GL_STACK_UNDERFLOW:
			errorMessage += "Stack Underflow";
			break;
		case GL_OUT_OF_MEMORY:
			errorMessage += "Out of memory";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			errorMessage += "Invalid Framebuffer Operation";
			break;
		default:
			errorMessage += "Unknown Error Code: " + std::to_string(error);
			break;
		}

		const std::string filePathStr{ filePath };
		const std::string fileStr = filePathStr.substr(filePathStr.find_last_of('\\') + 1);

		const std::string logMessage = "[OPENGL ERROR] (" + fileStr + ':' + std::to_string(lineNumber) + ") " + errorMessage;

		LOG(logMessage);

		Logger::g_FilePath = filePathBackup;
		Logger::g_LineNumber = lineNumberBackup;
		Logger::g_LogLevel = logLevelBackup;
	}

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

		CHECK_ERRORS();
	}

	void OpenGlContext::ShutDown() { }

	// ------------------------------ State ------------------------------
	void OpenGlContext::EnableDepthTesting() {
		if (m_DepthTesting) {
			return;
		}

		glEnable(GL_DEPTH_TEST);
		m_DepthTesting = true;

		CHECK_ERRORS();
	}

	void OpenGlContext::DisableDepthTesting() {
		if (!m_DepthTesting) {
			return;
		}

		glDisable(GL_DEPTH_TEST);
		m_DepthTesting = false;

		CHECK_ERRORS();
	}

	bool OpenGlContext::GetDepthTesting() const { return m_DepthTesting; }

	void OpenGlContext::SetDepthTestFunction(const DepthTestFunction function) {
		if (m_DepthTestFunction == function) {
			return;
		}

		glDepthFunc((GLenum)function);
		m_DepthTestFunction = function;

		CHECK_ERRORS();
	}

	OpenGlContext::DepthTestFunction OpenGlContext::GetDepthTestFunction() const { return m_DepthTestFunction; }

	void OpenGlContext::EnableDepthMask() {
		if (m_DepthMask) {
			return;
		}

		glDepthMask(GL_TRUE);
		m_DepthMask = true;

		CHECK_ERRORS();
	}

	void OpenGlContext::DisableDepthMask() {
		if (!m_DepthMask) {
			return;
		}

		glDepthMask(GL_FALSE);
		m_DepthMask = false;

		CHECK_ERRORS();
	}

	bool OpenGlContext::GetDepthMask() const { return m_DepthMask; }

	void OpenGlContext::EnableFaceCulling() {
		if (m_FaceCulling) {
			return;
		}

		glEnable(GL_CULL_FACE);
		m_FaceCulling = true;

		CHECK_ERRORS();
	}

	void OpenGlContext::DisableFaceCulling() {
		if (!m_FaceCulling) {
			return;
		}

		glDisable(GL_CULL_FACE);
		m_FaceCulling = false;

		CHECK_ERRORS();
	}

	bool OpenGlContext::GetFaceCulling() const { return m_FaceCulling; }

	void OpenGlContext::CullFace(const CullableFaces face) {
		if (m_CulledFace == face) {
			return;
		}

		glCullFace((GLenum)face);
		m_CulledFace = face;

		CHECK_ERRORS();
 	}

	OpenGlContext::CullableFaces OpenGlContext::GetCulledFace() const { return m_CulledFace; }

	void OpenGlContext::SetFrontFaceDirection(const FrontFaceDirection direction) {
		if (m_FrontFaceDirection == direction) {
			return;
		}

		glFrontFace((GLenum)direction);
		m_FrontFaceDirection = direction;

		CHECK_ERRORS();
	}

	OpenGlContext::FrontFaceDirection OpenGlContext::GetFrontFaceDirection() const { return m_FrontFaceDirection; }

	// ------------------------------ Miscellaneous ------------------------------
	void OpenGlContext::Clear() {
		const Vector4f floatColour{ clearColour.ToVec4f() };

		glClearColor(floatColour.x, floatColour.y, floatColour.z, floatColour.w);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		CHECK_ERRORS();
	}

	void OpenGlContext::SetViewportSize(const Vector2ui& size) {
		glViewport(0, 0, size.x, size.y);

		CHECK_ERRORS();
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

	// ------------------------------ Textures ------------------------------
	TextureHandle OpenGlContext::GenerateTexture() {
		TextureHandle handle;
		glGenTextures(1, &handle);

		CHECK_ERRORS();

		return handle;
	}

	void OpenGlContext::DeleteTexture(TextureHandle handle) {
		glDeleteTextures(1, &handle);

		CHECK_ERRORS();
	}

	void OpenGlContext::BindTexture2D(const TextureHandle handle) {
		if (m_BoundTexture == handle) {
			return;
		}

		glBindTexture(GL_TEXTURE_2D, handle);
		m_BoundTexture = handle;

		CHECK_ERRORS();
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

		CHECK_ERRORS();
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

		CHECK_ERRORS();
	}

	void OpenGlContext::GenerateMipMaps2D(TextureHandle handle) {
		BindTexture2D(handle);

		glGenerateMipmap(GL_TEXTURE_2D);

		CHECK_ERRORS();
	}

	void OpenGlContext::ActivateTextureUnit(const size_t index) {
		glActiveTexture(GL_TEXTURE0 + (int)index);

		CHECK_ERRORS();
	}

	// ------------------------------ Buffers ------------------------------
	BufferHandle OpenGlContext::GenerateBuffer() {
		BufferHandle handle;
	
		glGenBuffers(1, &handle);
	
		CHECK_ERRORS();
	
		return handle;
	}

	void OpenGlContext::DeleteBuffer(BufferHandle handle) {
		glDeleteBuffers(1, &handle);

		CHECK_ERRORS();
	}

	void OpenGlContext::BindBuffer(BufferHandle handle, BufferType type) {
		if (m_BoundBuffer == handle) {
			return;
		}

		glBindBuffer((GLenum)type, handle);
		m_BoundBuffer = handle;

		CHECK_ERRORS();
	}

	void OpenGlContext::SetBufferData(BufferHandle handle, const BufferType type, const void* data, const size_t dataSize, const BufferAccessFrequency accessFrequency, const BufferNatureOfAccess natureOfAccess) {
		BindBuffer(handle, type);

		const int usage = BufferAccessToInt(accessFrequency, natureOfAccess);

		glBufferData((GLenum)type, (unsigned int)dataSize, data, usage);

		CHECK_ERRORS();
	}

	void OpenGlContext::ModifyBufferData(BufferHandle handle, const BufferType type, const void* data, const size_t dataSize, const size_t byteOffset) {
		BindBuffer(handle, type);

		glBufferSubData((GLenum)type, (unsigned int)byteOffset, (unsigned int)dataSize, data);

		CHECK_ERRORS();
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

	// ------------------------------ Vertex Attribute Objects ------------------------------
	VertexAttributeObjectHandle OpenGlContext::GenerateVertexAttributeObject() {
		VertexAttributeObjectHandle handle;

		glGenVertexArrays(1, &handle);

		CHECK_ERRORS();

		return handle;
	}

	void OpenGlContext::DeleteVertexAttributeObject(VertexAttributeObjectHandle handle) {
		glDeleteVertexArrays(1, &handle);

		CHECK_ERRORS();
	}

	void OpenGlContext::BindVertexAttributeObject(VertexAttributeObjectHandle handle) {
		if (m_BoundVertexAttributeObject == handle) {
			return;
		}

		glBindVertexArray(handle);

		m_BoundVertexAttributeObject = handle;

		CHECK_ERRORS();
	}

	void OpenGlContext::CreateAttributePointer(VertexAttributeObjectHandle handle, const size_t index, GlType type, const size_t stride, const size_t offset) {
		BindVertexAttributeObject(handle);

		EnableVertexAttributeIndex(index);

		glVertexAttribPointer((GLuint)index, (GLint)type.componentCount, (GLenum)type.type, GL_FALSE, (GLint)stride, (void*)offset);

		CHECK_ERRORS();
	}

	void OpenGlContext::DeleteAttributePointer(VertexAttributeObjectHandle handle, const size_t index) {
		DisableVertexAttributeIndex(index);
	}

	void OpenGlContext::EnableVertexAttributeIndex(const size_t index) {
		glEnableVertexAttribArray((unsigned int)index);

		CHECK_ERRORS();
	}

	void OpenGlContext::DisableVertexAttributeIndex(const size_t index) {
		glDisableVertexAttribArray((unsigned int)index);

		CHECK_ERRORS();
	}

	// ------------------------------ Shaders ------------------------------
	ShaderHandle OpenGlContext::CreateShader(ShaderType type) {
		const ShaderHandle shader = glCreateShader((GLenum)type);

		CHECK_ERRORS();

		return shader;
	}

	void OpenGlContext::AttachShaderSource(ShaderHandle shader, const std::string& shaderSource) {
		const char* charShaderSource = shaderSource.c_str();
		glShaderSource(shader, 1, &charShaderSource, nullptr);

		CHECK_ERRORS();
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

		CHECK_ERRORS();
	}

	ShaderProgramHandle OpenGlContext::CreateShaderProgram() {
		ShaderProgramHandle shaderProgram = glCreateProgram();

		CHECK_ERRORS();

		return shaderProgram;
	}

	void OpenGlContext::AttachShaderToProgram(ShaderProgramHandle shaderProgram, ShaderHandle shader) {
		glAttachShader(shaderProgram, shader);

		CHECK_ERRORS();
	}

	void OpenGlContext::BindShaderProgram(ShaderProgramHandle shaderProgram) {
		if (m_BoundShaderProgram == shaderProgram) {
			return;
		}

		glUseProgram(shaderProgram);
		m_BoundShaderProgram = shaderProgram;

		CHECK_ERRORS();
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

		CHECK_ERRORS();
	}

	// ------------------------------ Rendering ------------------------------
	void OpenGlContext::DrawElements(const size_t indexCount) {
		glDrawElements(GL_TRIANGLES, (int)indexCount, GL_UNSIGNED_INT, 0);

		CHECK_ERRORS();
	}

	// ------------------------------ Uniform Uploads ------------------------------
	UniformLocation OpenGlContext::GetUniformLocation(ShaderHandle handle, const std::string& uniformName) const {
		const UniformLocation location = glGetUniformLocation(handle, uniformName.c_str());

#ifdef GEMSTONE_CHECK_OPEN_GL_ERRORS
		if (location < 0) {
			LOG("Failed to fetch unifrom location.", LogLevel::ERROR);
		}
#endif

		CHECK_ERRORS();

		return location;
	}

	void OpenGlContext::UploadUniform(UniformLocation location, int value) {
		glUniform1i(location, value);

		CHECK_ERRORS();
	}

	void OpenGlContext::UploadUniform(UniformLocation location, float value) {
		glUniform1f(location, value);

		CHECK_ERRORS();
	}

	void OpenGlContext::UploadUniform(UniformLocation location, const Matrix4f& value) {
		glUniformMatrix4fv(location, 1, GL_FALSE, &value.row1.x);

		CHECK_ERRORS();
	}

	void OpenGlContext::UploadUniform(UniformLocation location, const Vector3f& value) {
		glUniform3fv(location, 1, &value.x);

		CHECK_ERRORS();
	}

	void OpenGlContext::UploadUniform(UniformLocation location, const Vector4f& value) {
		glUniform4fv(location, 1, &value.x);

		CHECK_ERRORS();
	}

	// ------------------------------ Frame Buffers ------------------------------
	FrameBufferHandle OpenGlContext::GenerateFrameBuffer() {
		FrameBufferHandle handle;

		glGenFramebuffers(1, &handle);

		CHECK_ERRORS();

		return handle;
	}

	void OpenGlContext::DeleteFrameBuffer(FrameBufferHandle handle) {
		glDeleteFramebuffers(1, &handle);

		CHECK_ERRORS();
	}

	void OpenGlContext::BindFrameBuffer(const FrameBufferHandle handle) {
		if (m_BoundFrameBuffer == handle) {
			return;
		}

		glBindFramebuffer(GL_FRAMEBUFFER, handle);
		m_BoundFrameBuffer = handle;

		CHECK_ERRORS();
	}

	bool OpenGlContext::GetFrameBufferStatus(const FrameBufferHandle frameBuffer) {
		BindFrameBuffer(frameBuffer);

		const bool result = glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;

		CHECK_ERRORS();

		return result;
	}

	void OpenGlContext::AttachTextureToFrameBuffer(const FrameBufferHandle frameBuffer, const TextureHandle texture) {
		BindFrameBuffer(frameBuffer);

		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

		CHECK_ERRORS();
	}

	void OpenGlContext::AttachRenderBufferToFrameBuffer(const FrameBufferHandle frameBuffer, const RenderBufferHandle renderBuffer) {
		BindFrameBuffer(frameBuffer);

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, renderBuffer);
	}

	// ------------------------------ Render Buffers ------------------------------

	RenderBufferHandle OpenGlContext::GenerateRenderBuffer() {
		RenderBufferHandle handle;

		glGenRenderbuffers(1, &handle);

		CHECK_ERRORS();

		return handle;
	}

	void OpenGlContext::DeleteRenderBuffer(const RenderBufferHandle handle) {
		glDeleteRenderbuffers(1, &handle);

		CHECK_ERRORS();
	}

	void OpenGlContext::BindRenderBuffer(const RenderBufferHandle handle) {
		if (m_BoundRenderBuffer == handle) {
			return;
		}

		glBindRenderbuffer(GL_RENDERBUFFER, handle);
		m_BoundRenderBuffer = handle;

		CHECK_ERRORS();
	}

	void OpenGlContext::SetRenderBufferStorageType(const RenderBufferHandle handle, const Vector2ui& size) {
		BindRenderBuffer(handle);

		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, (int)size.x, (int)size.y);

		CHECK_ERRORS();
	}
}