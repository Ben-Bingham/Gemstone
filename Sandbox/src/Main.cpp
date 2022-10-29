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
#include "Timing.h"
#include "Powers.h"

#include "Collision/Colliders/AxisAlignedBoxCollider.h"
#include "Renderable Objects/Solid/SolidSphere.h"

#include "ForceGenerator.h"

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
	Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f};
	Wavellite::Mouse* mouse = &window.ioManger.mouse;
	Wavellite::Keyboard* keyboard = &window.ioManger.keyboard;

	mouse->addMousePositionCallback(mousePositionCallback, (void*)&fpsController);
	window.disableCursor();

	Wavellite::Time time{ };
	Ruby::Renderer renderer{ };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 5.0f };

	std::vector<Ruby::PointLight*> pointLights;

	// Shader setup
	Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	pointLights.push_back(&pointLight);

	std::vector<Ruby::DirectionalLight*> directionalLights;

	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(&directionalLight);

	// Solid setup
	Ruby::SolidMaterial staticMat{ Malachite::Vector3f{ 0.0f, 0.0f, 1.0f } };
	Ruby::SolidMaterial defaultMat{ Malachite::Vector3f{ 1.0f, 0.0f, 0.0f } };
	Ruby::SolidMaterial collidedMat{ Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } };

	Ruby::SolidCube staticCube{ defaultMat };
	staticCube.model.scale(3.0f);
	Ruby::SolidCube movingCube{ staticMat };

	Ruby::SolidSphere sphere{ defaultMat, 4000, 2000 };
	sphere.model.scale(6.0f);

	// Skybox setup
	std::vector<Ruby::Image> skyboxImages {
		Ruby::Image{ "assets\\Skybox\\right.jpg", false },
		Ruby::Image{ "assets\\Skybox\\left.jpg", false },
		Ruby::Image{ "assets\\Skybox\\top.jpg", false },
		Ruby::Image{ "assets\\Skybox\\bottom.jpg", false },
		Ruby::Image{ "assets\\Skybox\\front.jpg", false },
		Ruby::Image{ "assets\\Skybox\\back.jpg", false },
	};

	// normal rendering setup
	Ruby::Skybox skybox{ skyboxImages };

	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::Texture contianerTexture{ containerImage };
	Ruby::Texture containerSpecularTexture{ containerSpecularImage };

	Ruby::PhongMaterial cubeMaterial{ contianerTexture, containerSpecularTexture };
	Ruby::PhongCube sun{ cubeMaterial };
	Ruby::PhongCube earth{ cubeMaterial };

	//Ruby::PhongSphere sphere{ cubeMaterial };
	//Ruby::PhongCube moon{ cubeMaterial };

	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO

	// Shader setup
	renderer.shaders.phongShader.use();
	Ruby::ShaderProgram::upload("pointLights", pointLights);
	Ruby::ShaderProgram::upload("directionalLights", 2, directionalLights);

	// Renderer setup
	renderer.init(window.getProjectionMatrix());

	// Physics
	using namespace Pyrite::Literals;

	Pyrite::PhysicsObject staticObject{ 10_kg };
	Pyrite::AxisAlignedBoxCollider staticCollider{ Pyrite::Point3D{ 0.0_m } - 1.5_m, Pyrite::Point3D{ 0.0_m } + 1.5_m };
	Pyrite::PhysicsObject movingObject{ 2.0_kg, Pyrite::Point3D{ 5.0_m, 0.0_m, 0.0_m } };
	Pyrite::AxisAlignedBoxCollider movingCollider{ movingObject.position - 0.5_m, movingObject.position + 0.5_m };
	
	Pyrite::Collider::Collision collision;

	Pyrite::PhysicsObject sunPhysics{ ((5.0_mPerS * 5.0_mPerS) * 30.0_m) / Pyrite::GravitationalConstant };
	Pyrite::PhysicsObject earthPhysics{ ((2.0_mPerS * 2.0_mPerS) * 10.0_m) / Pyrite::GravitationalConstant, Pyrite::Point3D{ 30.0_m, 0.0_m, 0.0_m }};

	earthPhysics.velocity.z = 5.0_mPerS;

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

		float spd = 1.0f;

		if (keyboard->KEY_UP) {
			movingObject.netForce += Malachite::Vector3f{0, 0, -1 * spd};
		}

		if (keyboard->KEY_DOWN) {
			movingObject.netForce += Malachite::Vector3f{ 0, 0, 1 * spd };
		}

		if (keyboard->KEY_LEFT) {
			movingObject.netForce += Malachite::Vector3f{ -1 * spd, 0, 0 };
		}

		if (keyboard->KEY_RIGHT) {
			movingObject.netForce += Malachite::Vector3f{ 1 * spd, 0, 0 };
		}

		if (keyboard->KEY_I) {
			movingObject.netForce += Malachite::Vector3f{ 0, 1 * spd, 0 };
		}

		if (keyboard->KEY_K) {
			movingObject.netForce += Malachite::Vector3f{ 0, -1 * spd, 0 };
		}
		{ // Physics
			movingObject.calcVelocity(time.deltaTime);
			movingObject.calcPosition(time.deltaTime);
			movingObject.netForce = Pyrite::Newton3D{ 0.0_N };

			movingCube.model = Malachite::Matrix4f{ 1.0f };
			movingCube.model.translate(movingObject.position);
			movingCollider.min = movingObject.position - 0.5_m;
			movingCollider.max = movingObject.position + 0.5_m;

			staticObject.calcVelocity(time.deltaTime);
			staticObject.calcPosition(time.deltaTime);
			staticObject.netForce = Pyrite::Newton3D{ 0.0_N };

			staticCube.model = Malachite::Matrix4f{ 1.0f };
			staticCube.model.scale(3.0f);
			staticCube.model.translate(staticObject.position);
			staticCollider.min = staticObject.position - 1.5_m;
			staticCollider.max = staticObject.position + 1.5_m;

			collision = movingCollider.collidesWithAABB(&staticCollider);

			if (collision.hasCollision) {
				Pyrite::Speed speed = dot(collision.normal, movingObject.velocity - staticObject.velocity);
				if (speed > 0) {
					Pyrite::KilogramMeterPerSeconds impulse = 2 * speed / (movingObject.mass + staticObject.mass);

					movingObject.velocity -= (impulse * staticObject.mass * collision.normal);
					staticObject.velocity += (impulse * staticObject.mass * collision.normal);
				}
			}

			if (collision.hasCollision) {
				staticCube.material = collidedMat;
			}
			else {
				staticCube.material = defaultMat;
			}

			earthPhysics.netForce = Pyrite::Newton3D{ 0.0_N };
			earthPhysics.netForce += Pyrite::ForceGenerator::gravitationalForce(&sunPhysics, &earthPhysics);
			earthPhysics.calcVelocity(time.deltaTime);
			earthPhysics.calcPosition(time.deltaTime);

			sun.model = Malachite::Matrix4f{ 1.0f };
			sun.model.scale(2.0f);
			sun.model.translate(sunPhysics.position);

			earth.model = Malachite::Matrix4f{ 1.0f };
			earth.model.scale(2.0f);
			earth.model.translate(earthPhysics.position);
		}

		{ // Rendering
			renderer.prep(camera.getViewMatrix());

			{ // Solid Rendering
				renderer.solidRenderingPrep();

				renderer.solidRender(staticCube);
				renderer.solidRender(movingCube);
				renderer.solidRender(sphere);

				renderer.solidRenderingEnd();
			}

			{ // Normal Rendering
				renderer.phongRenderingPrep();

				// Cube
				Ruby::ShaderProgram::upload("cameraPosition", camera.position); // Shader specific

				renderer.phongRender(sun);
				renderer.phongRender(earth);

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