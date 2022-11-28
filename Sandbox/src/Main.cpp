// Wavellite
#include "Window.h"
#include "Timing.h"

// Ruby
#include "Renderer.h"
#include "Camera.h"
#include "Renderable.h"
#include "Geometry/CubeGeometryData.h"
#include "Geometry/SphereGeometryData.h"
#include "Materials/PhongMaterial.h"
#include "Materials/SolidMaterial.h"

// Malachite
#include "Utility.h"



Ruby::Camera camera{ };
struct FPSController {
	bool firstMouse = true;
	int lastX = 0;
	int lastY = 0;
	float mouseSensitivity = 0.1f;
	Malachite::Degree yaw = -90.0f;
	Malachite::Degree pitch;
}; 
FPSController fpsController{ };
bool cursorNormal = false;

void mousePositionCallback(int xpos, int ypos, void* data) {
	FPSController* controller = (FPSController*)data;

	if (controller->firstMouse) {
		controller->lastX = (int)xpos;
		controller->lastY = (int)ypos;
		controller->firstMouse = false;
	}

	float xOffset = (float)(xpos - controller->lastX);
	float yOffset = (float)(controller->lastY - ypos);
	controller->lastX = (int)xpos;
	controller->lastY = (int)ypos;

	xOffset *= controller->mouseSensitivity;
	yOffset *= controller->mouseSensitivity;

	controller->yaw += xOffset;
	controller->pitch += yOffset;

	if (controller->pitch > 89.0f)
		controller->pitch = 89.0f;
	if (controller->pitch < -89.0f)
		controller->pitch = -89.0f;

	Malachite::Vector3f direction;
	direction.x = cos(Malachite::degreesToRadians(controller->yaw)) * cos(Malachite::degreesToRadians(controller->pitch));
	direction.y = sin(Malachite::degreesToRadians(controller->pitch));
	direction.z = sin(Malachite::degreesToRadians(controller->yaw)) * cos(Malachite::degreesToRadians(controller->pitch));

	camera.front = direction.normalize();
	camera.updateCameraVectors();
}

int main() {
	Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f};
	Wavellite::Mouse& mouse = window.ioManger.getMouse();
	Wavellite::Keyboard& keyboard = window.ioManger.getKeyboard();

	mouse.addMousePositionCallback(mousePositionCallback, (void*)&fpsController);
	window.disableCursor();

	Wavellite::Time time{ };
	Ruby::Renderer renderer{ camera, window };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 5.0f };

	// SkyBox setup
	std::vector<Ruby::Image> skyboxImages {
		Ruby::Image{ "assets\\SkyBox\\right.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\left.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\top.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\bottom.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\front.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\back.jpg", false },
	};

	// Ruby::SkyBox skybox{ skyboxImages };



	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::Texture contianerTexture{ containerImage };
	Ruby::Texture containerSpecularTexture{ containerSpecularImage };




	Ruby::SolidMaterial blueMaterial{ Ruby::Colour::blue };
	Ruby::CubeGeometryData cubeGeometryData{};
	Ruby::SphereGeometryData sphereGeometryData{};

	Ruby::Renderable testCube{ cubeGeometryData, blueMaterial };


	Ruby::PhongMaterial containerMaterial{ contianerTexture, containerSpecularTexture };

	std::vector<Ruby::DirectionalLight> directionalLights{};
	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(directionalLight);

	containerMaterial.directionalLights = directionalLights;

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
	donutMat.directionalLights = directionalLights;
	Ruby::PhongMaterial earthMat{ earthTexture, earthTexture };
	earthMat.directionalLights = directionalLights;
	Ruby::PhongMaterial pawnMat{ pawnTexture, pawnTexture };
	pawnMat.directionalLights = directionalLights;
	Ruby::PhongMaterial awesomeMat{ awesomeFaceTexture, awesomeFaceTexture };
	awesomeMat.directionalLights = directionalLights;


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

	Ruby::Renderable awesomeRenderalbe2{ sphereGeometryData, awesomeMat };
	awesomeRenderalbe2.getModelMatrix().translate(0.0f, -3.0f, 0.0f);

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

		float spd = 1.0f;

		{ // Physics

		}

		{ // Rendering
			renderer.beginFrame();

			renderer.render(donut);
			renderer.render(earthRenderable);
			renderer.render(pawn);
			renderer.render(awesomeRenderable);
			renderer.render(awesomeRenderalbe2);

			renderer.render(testCube);
			renderer.render(phongCube);

			//renderer.render(skybox);

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