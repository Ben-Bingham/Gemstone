#include "pch.h"
#include "ImGuiContext.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Core/Engine.h"
#include "Core/Window.h"

namespace Gem {
	void ImGuiContext::StartUp() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(g_Engine.window.Handle(), true);
		ImGui_ImplOpenGL3_Init();
	}

	void ImGuiContext::ShutDown() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}
}