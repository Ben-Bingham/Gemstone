#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Ruby/Utility/Colour.h"
#include "Rutile/Interfaces/IRenderingAPI.h"

namespace Rutile {
	class OpenGlAPI : public IRenderingAPI {
	public:
		OpenGlAPI() = default;
		~OpenGlAPI() override = default;

		void StartUp() override;
		void ShutDown() override;

		void CreateContext() override;
		void ClearColour(const Ruby::Colour& colour) override;
		void ClearColorBit() override;
		void ClearDepthBit() override;
		void DrawMesh() override;
	};
}