#include "pch.h"
#include "Core/Game Flow/Application.h"
#include "imgui.h"
#include "implot.h"
#include "Rendering/Renderer.h"

namespace Gem {
	void Application::Load(const Ptr<Level>& level) const {
		level->InternalLoad();

		//while (g_Engine.window.IsOpen() && level->IsRunning()) {
		//	ExecuteFrame(level);
		//}

		level->InternalUnload();
	}

	void Application::ExecuteFrame(const Ptr<Level>& level) const {
		static DebugTimings timings{};

		//const HumanInterfaceDeviceContext& hid = g_Engine.humanInterfaceDeviceContext;

		const float deltaTime = timings.frameEnd - timings.frameStart;

		//timings.frameStart = hid.GetTime();

		// const float endTime = g_Engine.humanInterfaceDeviceContext.GetTime() + 1.0f / static_cast<float>(Settings::maxFPS);

		//{ // GPU
		//	timings.uiPrepStart = hid.GetTime();
		//	//g_Engine.imGuiContext.StartUiFrame();
		//	timings.uiPrepEnd = hid.GetTime();
		//}

		//{ // CPU
		//	timings.totalCpuStart = hid.GetTime();

		//	timings.eventPollStart = hid.GetTime();
		//	//g_Engine.humanInterfaceDeviceContext.PollEvents();
		//	timings.eventPollEnd = hid.GetTime();

		//	timings.eventDistributionStart = hid.GetTime();
		//	//g_Engine.eventManager.Distribute();
		//	timings.eventDistributionEnd = hid.GetTime();

		//	timings.ecsStart = hid.GetTime();
		//	level->Step(deltaTime);
		//	timings.ecsEnd = hid.GetTime();

		//	timings.totalCpuEnd = hid.GetTime();
		//}

		//if (m_DebugWindow) {
		//	DrawDebugWindow(timings);
		//}

		//{ // GPU
		//	timings.totalGpuStart = hid.GetTime();

		//	timings.renderSetupStart = hid.GetTime();
		//	g_Engine.renderer.RenderSetup();
		//	timings.renderSetupEnd = hid.GetTime();

		//	timings.renderStart = hid.GetTime();
		//	g_Engine.renderer.Render();
		//	timings.renderEnd = hid.GetTime();

		//	timings.uiStart = hid.GetTime();
		//	g_Engine.imGuiContext.RenderUi();
		//	timings.uiEnd = hid.GetTime();

		//	timings.renderCleanupStart = hid.GetTime();
		//	g_Engine.renderer.RenderCleanup();
		//	timings.renderCleanupEnd = hid.GetTime();

		//	timings.totalGpuEnd = hid.GetTime();
		//}

		//timings.frameEnd = hid.GetTime();
		// if (Settings::vSync) {
		// 	g_Engine.humanInterfaceDeviceContext.Wait(endTime - g_Engine.humanInterfaceDeviceContext.GetTime());
		// }
		// m_LastEndTime = endTime;
	}

	void Application::DrawDebugWindow(const DebugTimings& timings) const {
		const float frameTime = (timings.totalCpuEnd - timings.totalCpuStart) + (timings.totalGpuEnd - timings.totalGpuStart);

		if (ImGui::Begin("Debug")) {
			ImGui::Text("Total frame time: %3.5f", frameTime);
			ImGui::Text("Frames per second: %3.5f", (double)(1.0f / frameTime));

			static const char* generalLabels[] = {
				"CPU",
				"GPU"
			};
			
			const std::vector generalData{
				timings.totalCpuEnd - timings.totalCpuStart,
				timings.totalGpuEnd - timings.totalGpuStart
			};

			if (ImPlot::BeginPlot("General timings", ImVec2(250, 250), ImPlotFlags_Equal | ImPlotFlags_NoMouseText)) {
				ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
				ImPlot::SetupAxesLimits(0, 1, 0, 1);
				ImPlot::PlotPieChart(generalLabels, generalData.data(), (int)generalData.size(), 0.5, 0.5, 0.5, "%.5f", 90, ImPlotPieChartFlags_Normalize);
				ImPlot::EndPlot();
			}
			
			ImGui::SameLine();

			static const char* specificLabels[] = { 
				"UI prep", 
				"Event polling", 
				"Event distribution", 
				"Entity component system", 
				"Rendering setup", 
				"Rendering", 
				"Rendering cleanup", 
				"UI Rendering"
			};

			const std::vector specificData{
				timings.uiPrepEnd				- timings.uiPrepStart,
				timings.eventPollEnd			- timings.eventPollStart,
				timings.eventDistributionEnd	- timings.eventDistributionStart,
				timings.ecsEnd					- timings.ecsStart,
				timings.renderSetupEnd			- timings.renderSetupStart,
				timings.renderStart				- timings.renderEnd,
				timings.renderCleanupEnd		- timings.renderCleanupStart,
				timings.uiEnd					- timings.uiStart,
			};

			if (ImPlot::BeginPlot("Specific timings", ImVec2(250, 250), ImPlotFlags_Equal | ImPlotFlags_NoMouseText)) {
				ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations, ImPlotAxisFlags_NoDecorations);
				ImPlot::SetupAxesLimits(0, 1, 0, 1);
				ImPlot::PlotPieChart(specificLabels, specificData.data(), (int)specificData.size(), 0.5, 0.5, 0.5, "%.5f", 90, ImPlotPieChartFlags_Normalize);
				ImPlot::EndPlot();
			}
		}

		ImGui::End();

		ImPlot::ShowDemoWindow();
	}
}