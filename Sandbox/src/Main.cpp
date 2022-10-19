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

	camera.front = Malachite::normalize(direction);
	camera.updateCameraVectors();
}

using namespace Pyrite::Literals;

int main() {
	Wavellite::Window window{ 640, 480 };
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
	Ruby::PhongCube cube{ cubeMaterial };
	Ruby::PhongCube earth{ cubeMaterial };
	earth.model.scale(2.0f);

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

	float speed = 5.0;
	float angle = 0.0f;
	Pyrite::GravitationalPhysicsObject obj1{ 1.0_m, 10.0_kg, Pyrite::Position3D{ 20.0_m, 0.0_m, 0.0_m }, Pyrite::Velocity{ 0.0_mPerS, 0.0_mPerS, speed } };
	float exponent = 12.0f;
	Pyrite::Kilogram earthMass = Malachite::ee(1.873f, exponent);
	Pyrite::GravitationalPhysicsObject earthPhysics{ 2.0_m, earthMass };

	Wavellite::Time time{ };

	//LOG(std::to_string((float)glfwGetTime()));

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
			// Net Force
			Pyrite::Position3D gravDirection = earthPhysics.getPosition() - obj1.getPosition();
			Pyrite::Position3D upVector = Pyrite::Position3D{ cos(gravDirection.x), sin(gravDirection.y), 0.0_m};
			upVector.normalize();
			Pyrite::Position3D filler = Malachite::cross(gravDirection, upVector + obj1.getPosition());

			Pyrite::Position3D velocityDirection = cross(gravDirection, filler);

			velocityDirection.normalize();
			velocityDirection *= speed;

			obj1.velocity = velocityDirection;

			//LOG(obj1.velocity.toString());
			//LOG(std::to_string(obj1.velocity.length()));
			obj1.calcNetForce(std::vector<Pyrite::GravitationalPhysicsObject*>{ &earthPhysics });

			// Position
			obj1.calcPosition(time.deltaTime);

			//earthPhysics.calcPosition(time.deltaTime);

			//LOG(obj1.getPosition().toString());
			
			earth.model = Malachite::Matrix4f{ 1.0f };
			earth.model.scale(2.0f);
			earth.model.translate(earthPhysics.getPosition());
			cube.model = Malachite::Matrix4f{ 1.0f };
			cube.model.translate(obj1.getPosition());
		}

		{ // Rendering
			renderer.prep(camera.getViewMatrix());

			{ // Normal Rendering
				renderer.phongRenderingPrep();

				// Cube
				Ruby::ShaderProgram::upload("cameraPosition", camera.position); // Shader specific

				renderer.phongRender(cube);
				renderer.phongRender(earth);

				renderer.phongRenderingEnd();
			}

			{ // Debug Rendering
				renderer.debugRenderingPrep();

				Pyrite::Position3D upVector = Pyrite::Position3D{ sin(angle), cos(angle), 0.0_m };
				upVector;
				Pyrite::Position3D gravDirection = earthPhysics.getPosition() - obj1.getPosition();
				Pyrite::Position3D velocityDirection = Malachite::cross(gravDirection, upVector);

				renderer.debugRender(Ruby::DebugLine{ Malachite::Vector3f{0.0f}, upVector * 100.0f, Ruby::Colour{0, 255, 0} });
				renderer.debugRender(Ruby::DebugLine{ obj1.getPosition(), gravDirection, Ruby::Colour{ 255, 0, 0 } });
				renderer.debugRender(Ruby::DebugLine{ obj1.getPosition(), velocityDirection, Ruby::Colour{ 0, 0, 255 } });

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
					ImGui::Begin("Window");
					ImGui::Text("Mass");
					ImGui::SliderFloat("float", &speed, 0.0f, 1000.0f);
					earthPhysics.mass = Malachite::ee(1.873f, exponent);
					ImGui::End();
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