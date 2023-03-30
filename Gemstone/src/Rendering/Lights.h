#pragma once

namespace Gem {
	struct PointLight {
		Vector3f position{ 0.0f };

		Vector3f ambient{ 0.2f };
		Vector3f diffuse{ 0.5f };
		Vector3f specular{ 1.0f };

		float constant{ 1.0f };
		float linear{ 0.09f };
		float quadratic{ 0.032f };
	};

	class DirectionalLight {
	public:
		DirectionalLight(const Vector3f& dir = Vector3f{ 0.0f, -1.0f, 0.0f }, const Vector3f& pos = Vector3f{ 0.0f, 3.0f, 0.0f })
			: direction(dir)
			, position(pos)
			//, shadowMap(GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT)
			/*, framebuffer(framebufferInit())*/ {
			//calculateSpaceMatrix();
		}

		Vector3f direction{ 0.0f, -1.0f, 0.0f };
		Vector3f position{ 0.0f, 3.0f, 0.0f };

		Vector3f ambient{ 0.2f };
		Vector3f diffuse{ 0.5f };
		Vector3f specular{ 1.0f };

		//static const unsigned int SHADOW_WIDTH;
		//static const unsigned int SHADOW_HEIGHT;

		//Texture shadowMap;
		//Framebuffer framebuffer;
		//Matrix4f spaceMatrix{ 1.0f };

		/*void calculateSpaceMatrix() {
			Matrix4f projection{ ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.001f, 10.0f) };
			Matrix4f view{ lookAt(position, position + direction, Vector3f{ 0.0f, 1.0f, 0.0f }) };

			spaceMatrix = Matrix4f{ 1.0f };
			spaceMatrix = view * projection;
		}*/

	/*private:
		Framebuffer framebufferInit() {
			Framebuffer framebuffer{ };

			framebuffer.bind();

			framebuffer.attachTexture(shadowMap, GL_DEPTH_ATTACHMENT);
			framebuffer.setDrawBuffer(GL_NONE);
			framebuffer.setReadBuffer(GL_NONE);
			framebuffer.checkStatus();

			framebuffer.unbind();
			return framebuffer;
		}*/
	};
}