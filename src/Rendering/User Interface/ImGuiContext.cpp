#include "pch.h"
#include "Rendering/User Interface/ImGuiContext.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Core/Engine.h"
#include "Core/Window.h"
#include "implot.h"

namespace Gem {
	void ImGuiContext::StartUp() {
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImPlot::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

		ImGui::StyleColorsDark();

		//ImGui_ImplGlfw_InitForOpenGL(g_Engine.window.Handle(), true);
		ImGui_ImplOpenGL3_Init();
	}

	void ImGuiContext::ShutDown() {
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImPlot::DestroyContext(); 
		ImGui::DestroyContext();
	}

	void ImGuiContext::StartUiFrame() {
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		imGuiIsActive = true;
	}

	void ImGuiContext::RenderUi() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		imGuiIsActive = false;
	}
}