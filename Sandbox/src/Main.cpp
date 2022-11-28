// Wavellite
#include "Window.h"
#include "Timing.h"

// Ruby
#include "Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Renderable.h"
#include "Geometry/CubeGeometryData.h"
#include "Geometry/SphereGeometryData.h"
#include "Materials/PhongMaterial.h"
#include "Materials/SolidMaterial.h"
#include "Renderable Objects/SkyBox.h"
#include "Resources/Image.h"

// Malachite
#include "Utility.h"

// Custom
#include "FPSCamera.h"

int main() {
	Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f};
	Wavellite::Mouse& mouse = window.ioManger.getMouse();
	Wavellite::Keyboard& keyboard = window.ioManger.getKeyboard();

	FPSCamera camera{};
	mouse.addMousePositionCallback(mousePositionCallback, (void*)&camera);
	window.disableCursor();

	Wavellite::Time time{ };
	Ruby::Renderer renderer{ camera, window };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 5.0f };

	Ruby::SkyBoxMaterial skyboxMat{ {
		Ruby::Image{ "assets\\SkyBox\\right.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\left.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\top.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\bottom.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\front.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\back.jpg", false }
	} };

	Ruby::SkyBox skyBox{ skyboxMat };

	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::Texture contianerTexture{ containerImage };
	Ruby::Texture containerSpecularTexture{ containerSpecularImage };

	Ruby::SolidMaterial blueMaterial{ Ruby::Colour::blue };
	Ruby::CubeGeometryData cubeGeometryData{};
	Ruby::SphereGeometryData sphereGeometryData{};

	Ruby::Renderable testCube{ cubeGeometryData, blueMaterial };

	Ruby::PhongMaterial containerMaterial{ contianerTexture, containerSpecularTexture };

	std::vector<Ruby::DirectionalLight*> directionalLights{};
	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(&directionalLight);

	Ruby::PhongMaterial::directionalLights = directionalLights;

	Ruby::Renderable phongCube{ cubeGeometryData, containerMaterial };
	phongCube.getModelMatrix().translate(-3.0f, 0.0f, 0.0f);

	Ruby::Image donutImg{ "assets\\Donut4.png" };
	Ruby::Image earthImg{ "assets\\earth.jpg" };
	Ruby::Image pawnImg{ "assets\\White Pawn.png" };
	Ruby::Image awesomeFaceImg{ "assets\\awesomeface.png" };

	Ruby::Texture donutTexture{ donutImg };
	Ruby::Texture earthTexture{ earthImg };
	Ruby::Texture pawnTexture{ pawnImg };
	Ruby::Texture awesomeFaceTexture{ awesomeFaceImg };

	Ruby::PhongMaterial donutMat{ donutTexture, donutTexture };
	Ruby::PhongMaterial earthMat{ earthTexture, earthTexture };
	Ruby::PhongMaterial pawnMat{ pawnTexture, pawnTexture };
	Ruby::PhongMaterial awesomeMat{ awesomeFaceTexture, awesomeFaceTexture };

	Ruby::Renderable donut{ sphereGeometryData, donutMat };
	donut.getModelMatrix().scale(1.0f, 0.4f, 1.0f);
	donut.getModelMatrix().translate(-6.0f, 0.0f, 0.0f);

	Ruby::Renderable earthRenderable{ sphereGeometryData, earthMat };
	earthRenderable.getModelMatrix().translate(3.0f, 0.0f, 0.0f);

	Ruby::Renderable pawn{ cubeGeometryData, pawnMat };
	pawn.getModelMatrix().scale(0.6f, 2.0f, 0.6f);
	pawn.getModelMatrix().translate(6.0f, 0.0f, 0.0f);

	Ruby::Renderable awesomeRenderable{ cubeGeometryData, awesomeMat };
	awesomeRenderable.getModelMatrix().translate(0.0f, 3.0f, 0.0f);

	Ruby::Renderable awesomeRenderable2{ sphereGeometryData, awesomeMat };
	awesomeRenderable2.getModelMatrix().translate(0.0f, -3.0f, 0.0f);

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO

	// Rendering loop
	while (window.isOpen()) {
		window.pollEvents();
		float velocity = 0.05f;
		 
		if (keyboard.KEY_W) {
			camera.position += camera.front * velocity;
		}

		if (keyboard.KEY_A) {
			camera.position -= camera.right * velocity;
		}

		if (keyboard.KEY_S) {
			camera.position -= camera.front * velocity;
		}

		if (keyboard.KEY_D) {
			camera.position += camera.right * velocity;
		}

		if (keyboard.KEY_SPACE) {
			camera.position += Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyboard.KEY_LEFT_SHIFT) {
			camera.position -= Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyboard.KEY_ESCAPE) {
			window.close();
		}

		{ // Physics

		}

		{ // Rendering
			renderer.beginFrame();

			renderer.render(donut);
			renderer.render(earthRenderable);
			renderer.render(pawn);
			renderer.render(awesomeRenderable);
			renderer.render(awesomeRenderable2);

			renderer.render(testCube);
			renderer.render(phongCube);

			renderer.render(skyBox);

			{ // ImGui
				renderer.imGuiPrep();

				//ImGui::ShowDemoWindow();
				{

				}

				renderer.imGuiEnd();
			}

			renderer.endFrame();
		}

		window.swapBuffers();
		time.endFrame();
	}
	renderer.imGuiTerminate();
}