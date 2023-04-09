#include "pch.h"

#include <GL/glew.h>

#include "Renderer.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Core/Engine.h"

namespace Gem {
	void Renderer::StartUp() {
		
	}

	void Renderer::ShutDown() {
		
	}

	void Renderer::StartUiFrame() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void Renderer::Render() {
		RenderSetup();

		RenderUI();

		RenderCleanup();
	}

	void Renderer::RenderSetup() {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::RenderCleanup() {
		g_Engine.window.SwapBuffers();
	}

	void Renderer::RenderUI() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
}