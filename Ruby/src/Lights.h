#pragma once

#include "Vector.h"
#include "OpenGL objects/Framebuffer.h"
#include "Matrix.h"

namespace Ruby {
	struct PointLight {
		Malachite::Vector3f position{ 0.0f };

		Malachite::Vector3f ambient{ 0.2f };
		Malachite::Vector3f diffuse{ 0.5f };
		Malachite::Vector3f specular{ 1.0f };

		float constant{ 1.0f };
		float linear{ 0.09f };
		float quadratic{ 0.032f };
	};

	class DirectionalLight {
	public:
		DirectionalLight(const Malachite::Vector3f& dir = Malachite::Vector3f{ 0.0f, -1.0f, 0.0f }, const Malachite::Vector3f& pos = Malachite::Vector3f{ 0.0f, 3.0f, 0.0f })
			: direction(dir)
			, position(pos)
			//, shadowMap(GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT)
			/*, framebuffer(framebufferInit())*/ {
			//calculateSpaceMatrix();
		}

		Malachite::Vector3f direction{ 0.0f, -1.0f, 0.0f };
		Malachite::Vector3f position{ 0.0f, 3.0f, 0.0f };

		Malachite::Vector3f ambient{ 0.2f };
		Malachite::Vector3f diffuse{ 0.5f };
		Malachite::Vector3f specular{ 1.0f };

		//static const unsigned int SHADOW_WIDTH;
		//static const unsigned int SHADOW_HEIGHT;

		//Texture shadowMap;
		//Framebuffer framebuffer;
		//Malachite::Matrix4f spaceMatrix{ 1.0f };

		/*void calculateSpaceMatrix() {
			Malachite::Matrix4f projection{ Malachite::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.001f, 10.0f) };
			Malachite::Matrix4f view{ Malachite::lookAt(position, position + direction, Malachite::Vector3f{ 0.0f, 1.0f, 0.0f }) };

			spaceMatrix = Malachite::Matrix4f{ 1.0f };
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