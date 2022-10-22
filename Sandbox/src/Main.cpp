#include <iostream>

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Solid/SolidCube.h"
#include "Renderable Objects/Image/ImageQuad.h"
#include "Renderable Objects/Phong/PhongCube.h"
#include "OpenGL objects/Framebuffer.h"
#include "Renderable Objects/Skybox.h"

#include "Units.h"
#include "Gravitation/GravitationalPhysicsObject.h"
#include "Timing.h"

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

using namespace Pyrite::Literals;

int main() {
	Wavellite::Window window{ 640, 480, "Sandbox", 1000.0f}; //TODO full screen and an option for half or quarter of screen
	Wavellite::Mouse* mouse = &window.ioManger.mouse;
	Wavellite::Keyboard* keyboard = &window.ioManger.keyboard;

	mouse->addMousePositionCallback(mousePositionCallback, (void*)&fpsController);
	window.disableCursor();

	Ruby::Renderer renderer{ };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 3.0f };

	std::vector<Ruby::PointLight*> pointLights;

	Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	pointLights.push_back(&pointLight);

	std::vector<Ruby::DirectionalLight*> directionalLights;

	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(&directionalLight);

	// Cube setup
	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::Texture contianerTexture{ containerImage };
	Ruby::Texture containerSpecularTexture{ containerSpecularImage };

	Ruby::PhongMaterial cubeMaterial{ contianerTexture, containerSpecularTexture };
	Ruby::PhongCube sun{ cubeMaterial };
	Ruby::PhongCube earth{ cubeMaterial };
	Ruby::PhongCube moon{ cubeMaterial };

	// Skybox setup
	std::vector<Ruby::Image> skyboxImages {
		Ruby::Image{ "assets\\Skybox\\right.jpg", false },
		Ruby::Image{ "assets\\Skybox\\left.jpg", false },
		Ruby::Image{ "assets\\Skybox\\top.jpg", false },
		Ruby::Image{ "assets\\Skybox\\bottom.jpg", false },
		Ruby::Image{ "assets\\Skybox\\front.jpg", false },
		Ruby::Image{ "assets\\Skybox\\back.jpg", false },
	};

	Ruby::Skybox skybox{ skyboxImages };

	// Shader setup
	renderer.shaders.phongShader.use();
	Ruby::ShaderProgram::upload("pointLights", pointLights); // Shader specific
	Ruby::ShaderProgram::upload("directionalLights", 2, directionalLights);  // Shader specific

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO

	// Renderer setup
	renderer.init(window.getProjectionMatrix());

	// Physics
	using namespace Pyrite::Literals;

	/*Pyrite::Kilogram earthMass = 1'000'000'000'000'000.0_kg;
	Pyrite::Meter distanceBetween = 50.0_m;
	float speed = sqrt(((Pyrite::gravitationalConstant * earthMass) / distanceBetween));

	Pyrite::GravitationalPhysicsObject obj1{ 1.0_m, 10.0_kg, Pyrite::Position3D{ distanceBetween, 0.0_m, 0.0_m }, Pyrite::Velocity{0.0f, 0.0f, 1.0f } };
	obj1.velocity = obj1.velocity.normalize();
	obj1.velocity *= speed;
	Pyrite::GravitationalPhysicsObject earthPhysics{ 2.0_m, earthMass };*/

	Pyrite::Speed earthSpeed = 5.0_mPerS;
	Pyrite::Speed moonSpeed = earthSpeed / 2;

	Pyrite::GravitationalPhysicsObject moonPhysics{ 1.0_m, 10.0_kg, Pyrite::Position3D{ (Pyrite::Meter)sqrt(10 * 10 + 15 * 15), 0.0_m, 0.0_m}, Pyrite::Velocity{0.0_mPerS, 0.0_mPerS, moonSpeed}};
	Pyrite::GravitationalPhysicsObject earthPhysics{ 2.0_m, (Pyrite::Kilogram)((moonSpeed * moonSpeed) * (sqrt(50))) / Pyrite::gravitationalConstant, Pyrite::Position3D{ (Pyrite::Meter)sqrt(200), 0.0_m, 0.0_m}, Pyrite::Velocity{0.0_mPerS, 0.0_mPerS, earthSpeed}};
	Pyrite::GravitationalPhysicsObject sunPhysics{ 3.0_m, (Pyrite::Kilogram)((earthSpeed * earthSpeed) * (sqrt(200))) / Pyrite::gravitationalConstant };

	Wavellite::Time time{ };

	// Rendering loop
	while (window.isOpen()) {
		window.pollEvents();
		float velocity = 0.05f;
		 
		if (keyboard->KEY_W) {
			camera.position += camera.front * velocity;
		}

		if (keyboard->KEY_A) {
			camera.position -= camera.right * velocity;
		}

		if (keyboard->KEY_S) {
			camera.position -= camera.front * velocity;
		}

		if (keyboard->KEY_D) {
			camera.position += camera.right * velocity;
		}

		if (keyboard->KEY_SPACE) {
			camera.position += Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyboard->KEY_LEFT_SHIFT) {
			camera.position -= Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
		}

		if (keyboard->KEY_ESCAPE) {
			window.close();
		}

		float spd = 0.05f;

		if (keyboard->KEY_UP) {
			directionalLight.position += Malachite::Vector3f{0, 0, -1 * spd};
		}

		if (keyboard->KEY_DOWN) {
			directionalLight.position += Malachite::Vector3f{ 0, 0, 1 * spd };
		}

		if (keyboard->KEY_LEFT) {
			directionalLight.position += Malachite::Vector3f{ -1 * spd, 0, 0 };
		}

		if (keyboard->KEY_RIGHT) {
			directionalLight.position += Malachite::Vector3f{ 1 * spd, 0, 0 };
		}

		if (keyboard->KEY_I) {
			directionalLight.position += Malachite::Vector3f{ 0, 1 * spd, 0 };
		}

		if (keyboard->KEY_K) {
			directionalLight.position += Malachite::Vector3f{ 0, -1 * spd, 0 };
		}

		if (keyboard->KEY_M) {
			if (cursorNormal) {
				window.disableCursor();
				cursorNormal = false;
			}
			else {
				window.enableCursor();
				cursorNormal = true;
			}
		}

		{ // Physics
			// Position
			/*obj1.calcPosition(time.deltaTime);
			obj1.calcNetForce(std::vector<Pyrite::GravitationalPhysicsObject*>{ &earthPhysics });
			obj1.calcVelocity(time.deltaTime);

			earthPhysics.calcPosition(time.deltaTime);
			earthPhysics.calcNetForce(std::vector<Pyrite::GravitationalPhysicsObject*>{&obj1});
			earthPhysics.calcVelocity(time.deltaTime);
			
			earth.model = Malachite::Matrix4f{ 1.0f };
			earth.model.scale(2.0f);
			earth.model.translate(earthPhysics.getPosition());
			cube.model = Malachite::Matrix4f{ 1.0f };
			cube.model.translate(obj1.getPosition());*/

			sunPhysics.calcPosition(time.deltaTime);
			sunPhysics.calcNetForce(std::vector<Pyrite::GravitationalPhysicsObject*>{ &earthPhysics, &moonPhysics });
			sunPhysics.calcVelocity(time.deltaTime);

			earthPhysics.calcPosition(time.deltaTime);
			earthPhysics.calcNetForce(std::vector<Pyrite::GravitationalPhysicsObject*>{ &sunPhysics, & moonPhysics });
			earthPhysics.calcVelocity(time.deltaTime);

			moonPhysics.calcPosition(time.deltaTime);
			moonPhysics.calcNetForce(std::vector<Pyrite::GravitationalPhysicsObject*>{ &earthPhysics, & sunPhysics });
			moonPhysics.calcVelocity(time.deltaTime);

			sun.model = Malachite::Matrix4f{ 1.0f };
			sun.model.scale(3.0f);
			sun.model.translate(sunPhysics.getPosition());

			earth.model = Malachite::Matrix4f{ 1.0f };
			earth.model.scale(2.0f);
			earth.model.translate(earthPhysics.getPosition());

			moon.model = Malachite::Matrix4f{ 1.0f };
			moon.model.scale(1.0f);
			moon.model.translate(moonPhysics.getPosition());
		}

		{ // Rendering
			renderer.prep(camera.getViewMatrix());

			{ // Normal Rendering
				renderer.phongRenderingPrep();

				// Cube
				Ruby::ShaderProgram::upload("cameraPosition", camera.position); // Shader specific

				renderer.phongRender(sun);
				renderer.phongRender(earth);
				renderer.phongRender(moon);

				renderer.phongRenderingEnd();
			}

			{ // Debug Rendering
				renderer.debugRenderingPrep();

				renderer.debugRenderingEnd();
			}

			{ // Skybox Rendering
				renderer.skyboxRenderingPrep();

				renderer.skyboxRender(skybox);

				renderer.skyboxRenderingEnd();
			}

			{ // ImGui
				renderer.imGuiPrep();

				//ImGui::ShowDemoWindow();
				{
					/*ImGui::Begin("Window");
					ImGui::Text("Mass");
					ImGui::SliderFloat("float", &speed, 0.0f, 1000.0f);
					earthPhysics.mass = Malachite::ee(1.873f, exponent);
					ImGui::End();*/
				}

				renderer.imGuiEnd();
			}

			renderer.end();
		}

		window.swapBuffers();
		time.endFrame();
	}
	renderer.imGuiTerminate();
}