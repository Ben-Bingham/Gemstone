#pragma once
#include <GL/glew.h>

#include "Core/ISubSystem.h"
#include "Math/Matrix.h"
#include "Math/Vector.h"
#include "Utility/Colour.h"
#include "Utility/Image.h"

#ifdef GEMSTONE_DEBUG
#define GEMSTONE_CHECK_OPEN_GL_ERRORS
#endif

namespace Gem {
	void CheckErrors(const char* filePath, int lineNumber);
}

#ifdef GEMSTONE_CHECK_OPEN_GL_ERRORS
#define CHECK_ERRORS() Gem::CheckErrors(__FILE__, __LINE__)
#else
#define CHECK_ERRORS()
#endif

namespace Gem {
	using OpenGlHandle = GLuint;

	using TextureHandle = OpenGlHandle;
	using BufferHandle = OpenGlHandle;
	using VertexAttributeObjectHandle = OpenGlHandle;
	using ShaderHandle = OpenGlHandle;
	using VertexShaderHandle = ShaderHandle;
	using FragmentShaderHandle = ShaderHandle;
	using ShaderProgramHandle = OpenGlHandle;
	using FrameBufferHandle = OpenGlHandle;
	using RenderBufferHandle = OpenGlHandle;

	using UniformLocation = GLint;

	class OpenGlContext : ISubSystem {
	public:
		OpenGlContext() = default;
		OpenGlContext(const OpenGlContext& other) = default;
		OpenGlContext(OpenGlContext&& other) noexcept = default;
		OpenGlContext& operator=(const OpenGlContext& other) = default;
		OpenGlContext& operator=(OpenGlContext&& other) noexcept = default;
		~OpenGlContext() override = default;

		void StartUp() override;
		void ShutDown() override;

		// ------------------------------ State ------------------------------
		void EnableDepthTesting();
		void DisableDepthTesting();
		[[nodiscard]] bool GetDepthTesting() const;

		enum class DepthTestFunction {
			NEVER = GL_NEVER,
			EQUAL = GL_EQUAL,
			LESS_THAN = GL_LESS,
			LESS_THAN_OR_EQUAL = GL_LEQUAL,
			GREATER_THAN = GL_GREATER,
			GREATER_THAN_OR_EQUAL = GL_GEQUAL
		};
		void SetDepthTestFunction(DepthTestFunction function);
		[[nodiscard]] DepthTestFunction GetDepthTestFunction() const;

		void EnableDepthMask();
		void DisableDepthMask();
		[[nodiscard]] bool GetDepthMask() const;

		void EnableFaceCulling();
		void DisableFaceCulling();
		[[nodiscard]] bool GetFaceCulling() const;

		enum class CullableFaces {
			FRONT = GL_FRONT,
			BACK = GL_BACK
		};

		void CullFace(CullableFaces face);
		[[nodiscard]] CullableFaces GetCulledFace() const;

		enum class FrontFaceDirection {
			CLOCKWISE = GL_CW,
			COUNTER_CLOCKWISE = GL_CCW
		};

		void SetFrontFaceDirection(FrontFaceDirection direction);
		[[nodiscard]] FrontFaceDirection GetFrontFaceDirection() const;

	private:
		bool m_DepthTesting{ false };
		DepthTestFunction m_DepthTestFunction;
		bool m_DepthMask{ false };
		bool m_FaceCulling{ false };
		CullableFaces m_CulledFace;
		FrontFaceDirection m_FrontFaceDirection;

		// ------------------------------ Miscellaneous ------------------------------
	public:
		void Clear();
		Colour clearColour{ 128, 128, 128 };

		void SetViewportSize(const Vector2ui& size);

	private:
		enum class GlTypeName {
			FLOAT = (GLenum)GL_FLOAT,
			UNSIGNED_INT = (GLenum)GL_UNSIGNED_INT,
			INT = (GLenum)GL_INT,
			BYTE = (GLenum)GL_BYTE,
			UNSIGNED_BYTE = (GLenum)GL_UNSIGNED_BYTE
		};

		static size_t BytesPerGlType(GlTypeName type);

	public:
		struct GlType {
			GlType(GlTypeName type, size_t elementCount);

			GlTypeName type;
			size_t componentCount;
			size_t byteCount;
		};

		static inline const GlType FLOAT		{ GlTypeName::FLOAT, 1 };
		static inline const GlType VECTOR2F		{ GlTypeName::FLOAT, 2 };
		static inline const GlType VECTOR3F		{ GlTypeName::FLOAT, 3 };
		static inline const GlType VECTOR4F		{ GlTypeName::FLOAT, 4 };

		// ------------------------------ Textures ------------------------------ //TODO remove 2ds from functions, find a way to auto detect
		enum class WrapMode {
			REPEAT, // Repeats the texture image.
			MIRRORED_REPEAT, // Same as REPEAT but mirrors the image with each repeat.
			CLAMP_TO_EDGE, // Clamps the coordinates between 0 and 1. The result is that higher coordinates become clamped to the edge, resulting in a stretched edge pattern.
			CLAMP_TO_BORDER // Coordinates outside the range are now given a user-specified border color.
		}; // Descriptions from https://learnopengl.com/Getting-started/Textures

		enum class FilterMode {
			NEAREST, // Selects the texel that center is closest to the texture coordinate.
			LINEAR // Takes an interpolated value from the texture coordinate's neighboring texels.
		}; // Descriptions from https://learnopengl.com/Getting-started/Textures

		[[nodiscard]] TextureHandle GenerateTexture();
		void DeleteTexture(TextureHandle handle);
		void BindTexture2D(TextureHandle handle);
		void ConfigureTexture2D(TextureHandle handle, WrapMode wrapMode = WrapMode::REPEAT, FilterMode filterMode = FilterMode::NEAREST);
		void AssignTextureData2D(TextureHandle handle, const Image& image);
		void GenerateMipMaps2D(TextureHandle handle);

		void ActivateTextureUnit(size_t index);

	private:
		TextureHandle m_BoundTexture;

	public:
		// ------------------------------ Buffers ------------------------------
		enum class BufferAccessFrequency {
			STREAM, // The data store contents will be modified once and used at most a few times.
			STATIC, // The data store contents will be modified once and used many times.
			DYNAMIC // The data store contents will be modified repeatedly and used many times.

		}; // Descriptions from https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBufferData.xhtml

		enum class BufferNatureOfAccess {
			DRAW, // The data store contents are modified by the application, and used as the source for GL drawing and image specification commands.
			READ, // The data store contents are modified by reading data from the GL, and used to return that data when queried by the application.
			COPY // The data store contents are modified by reading data from the GL, and used as the source for GL drawing and image specification commands.
		}; // Descriptions from https://registry.khronos.org/OpenGL-Refpages/gl4/html/glBufferData.xhtml

		enum class BufferType {
			VERTEX_BUFFER = GL_ARRAY_BUFFER,
			INDEX_BUFFER = GL_ELEMENT_ARRAY_BUFFER
		};

		[[nodiscard]] BufferHandle GenerateBuffer();
		void DeleteBuffer(BufferHandle handle);
		void BindBuffer(BufferHandle handle, BufferType type);
		void SetBufferData(BufferHandle handle, BufferType type, const void* data = nullptr, size_t dataSize = 0, BufferAccessFrequency accessFrequency = BufferAccessFrequency::STATIC, BufferNatureOfAccess natureOfAccess = BufferNatureOfAccess::DRAW); // dataSize in bytes
		void ModifyBufferData(BufferHandle handle, BufferType type, const void* data, size_t dataSize, size_t byteOffset = 0); // dataSize in bytes

	private:
		[[nodiscard]] int BufferAccessToInt(BufferAccessFrequency accessFrequency, BufferNatureOfAccess natureOfAccess) const;

		BufferHandle m_BoundBuffer;

	public:
		// ------------------------------ Vertex Attribute Object ------------------------------
		[[nodiscard]] VertexAttributeObjectHandle GenerateVertexAttributeObject();
		void DeleteVertexAttributeObject(VertexAttributeObjectHandle handle);
		void BindVertexAttributeObject(VertexAttributeObjectHandle handle);
		void CreateAttributePointer(VertexAttributeObjectHandle handle, size_t index, GlType type, size_t stride, size_t offset);
		void DeleteAttributePointer(VertexAttributeObjectHandle handle, size_t index);

	private:
		void EnableVertexAttributeIndex(size_t index);
		void DisableVertexAttributeIndex(size_t index);

		VertexAttributeObjectHandle m_BoundVertexAttributeObject;

	public:
		// ------------------------------ Shaders ------------------------------
		enum class ShaderType {
			VERTEX = GL_VERTEX_SHADER,
			FRAGMENT = GL_FRAGMENT_SHADER
		};

		[[nodiscard]] ShaderHandle CreateShader(ShaderType type);
		void AttachShaderSource(ShaderHandle shader, const std::string& shaderSource);
		void CompileShader(ShaderHandle shader);

		[[nodiscard]] ShaderProgramHandle CreateShaderProgram();
		void AttachShaderToProgram(ShaderProgramHandle shaderProgram, ShaderHandle shader);
		void BindShaderProgram(ShaderProgramHandle shaderProgram);
		void CompileShaderProgram(ShaderProgramHandle shaderProgram);

	private:
		ShaderProgramHandle m_BoundShaderProgram;

	public:
		// ------------------------------ Rendering ------------------------------
		void DrawElements(size_t indexCount);

		// ------------------------------ Uniform Uploads ------------------------------
		[[nodiscard]] UniformLocation GetUniformLocation(ShaderHandle handle, const std::string& uniformName) const;

		void UploadUniform(UniformLocation location, int value);
		void UploadUniform(UniformLocation location, float value);
		void UploadUniform(UniformLocation location, const Matrix4f& value);
		void UploadUniform(UniformLocation location, const Vector3f& value);
		void UploadUniform(UniformLocation location, const Vector4f& value);

		// ------------------------------ Frame Buffers ------------------------------
		[[nodiscard]] FrameBufferHandle GenerateFrameBuffer();
		void DeleteFrameBuffer(FrameBufferHandle handle);
		void BindFrameBuffer(FrameBufferHandle handle);

		bool GetFrameBufferStatus(FrameBufferHandle frameBuffer);

		void AttachTextureToFrameBuffer(FrameBufferHandle frameBuffer, TextureHandle texture);
		void AttachRenderBufferToFrameBuffer(FrameBufferHandle frameBuffer, RenderBufferHandle renderBuffer);

	private:
		FrameBufferHandle m_BoundFrameBuffer;

	public:
		// ------------------------------ Render Buffers ------------------------------
		[[nodiscard]] RenderBufferHandle GenerateRenderBuffer();
		void DeleteRenderBuffer(RenderBufferHandle handle);
		void BindRenderBuffer(RenderBufferHandle handle);

		void SetRenderBufferStorageType(RenderBufferHandle handle, const Vector2ui& size);

	private:
		RenderBufferHandle m_BoundRenderBuffer;
	};
}