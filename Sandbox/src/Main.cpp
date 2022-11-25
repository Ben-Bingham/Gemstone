// Wavellite
#include "Window.h"
#include "Timing.h"

// Ruby
#include "Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Phong/PhongGeometry.h"
#include "Geometry/CubeGeometry.h"
#include "Geometry/SphereGeometry.h"
#include "Renderable Objects/Solid/SolidGeometry.h"
#include "Shaders/UniformData/UniformSet.h"
#include "Shaders/UniformData/BasicUniforms.h"

// Pyrite
#include "PhysicsObject.h"
#include "Collision/Colliders/AxisAlignedBoxCollider.h"
#include "Collision/Colliders/SphereCollider.h"
#include "ForceGenerator.h"
#include "Collision/CollisionWorld.h"
#include "Collision/CollisionDetection.h"

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

using namespace Pyrite::Literals;

int main() {
	Ruby::UniformSet<float, int> uniforms{ { "u_Roughness", "u_IsBlock" } };

	float roughness = 3.0f;
	int isBlock = 1;
	uniforms.set("u_Roughness", roughness);

	roughness = 1.0f;

	auto testVal = uniforms.get<float>("u_Roughness");







	Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f};
	Wavellite::Mouse& mouse = window.ioManger.getMouse();
	Wavellite::Keyboard& keyboard = window.ioManger.getKeyboard();

	mouse.addMousePositionCallback(mousePositionCallback, (void*)&fpsController);
	window.disableCursor();

	Wavellite::Time time{ };
	Ruby::Renderer renderer{ camera };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 5.0f };

	std::vector<Ruby::PointLight*> pointLights;

	// Shader setup
	Ruby::PointLight pointLight{ Malachite::Vector3f{ 2.0f } };
	pointLights.push_back(&pointLight);

	std::vector<Ruby::DirectionalLight*> directionalLights;

	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(&directionalLight);

	// Solid setup
	Ruby::Colour staticColour{ Malachite::Vector3f{ 0.0f, 0.0f, 1.0f } };
	Ruby::Colour defaultColour{ Malachite::Vector3f{ 1.0f, 0.0f, 0.0f } };
	Ruby::Colour collidedColour{ Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } };

	Ruby::SolidGeometry staticSphere{ std::make_unique<Ruby::SphereGeometry>(), defaultColour };
	staticSphere.model.scale(3.0f);
	Ruby::SolidGeometry movingSphere{ std::make_unique<Ruby::CubeGeometry>(), collidedColour };

	// SkyBox setup
	std::vector<Ruby::Image> skyboxImages {
		Ruby::Image{ "assets\\SkyBox\\right.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\left.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\top.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\bottom.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\front.jpg", false },
		Ruby::Image{ "assets\\SkyBox\\back.jpg", false },
	};

	// normal rendering setup
	Ruby::SkyBox skybox{ skyboxImages };

	Ruby::Image containerImage{ "assets\\container2.png" };
	Ruby::Image containerSpecularImage{ "assets\\container2_specular.png" };

	Ruby::Texture contianerTexture{ containerImage };
	Ruby::Texture containerSpecularTexture{ containerSpecularImage };

	Ruby::PhongMaterial cubeMaterial{ contianerTexture, containerSpecularTexture };
	Ruby::PhongGeometry sun{ std::make_unique<Ruby::CubeGeometry>(), cubeMaterial };
	Ruby::PhongGeometry earth{ std::make_unique<Ruby::CubeGeometry>(), cubeMaterial };
	
	Ruby::PhongGeometry testObj1{ std::make_unique<Ruby::CubeGeometry>(), cubeMaterial };
	Ruby::PhongGeometry testObj2{ std::make_unique<Ruby::SphereGeometry>(), cubeMaterial };
	testObj2.model.translate(Malachite::Vector3f{ 3.0f, 0.0f, 0.0f });
	Ruby::SolidGeometry testObj3{ std::make_unique<Ruby::SphereGeometry>(), staticColour };
	testObj3.model.translate(Malachite::Vector3f{ -3.0f, 0.0f, 0.0f });






	// Not in main file:
	//Ruby::UniformSet standardUniforms; // Should have Model View and Projection matrices

	// In Main:
	std::shared_ptr<Ruby::PhongMaterial> phongMaterial; // Should have a std::shared_ptr to the standard Phong shader Program
	std::shared_ptr<Ruby::CubeGeometry> cubeData;

	//Ruby::Renderable phongRenderable{ cubeData, phongMaterial };

	float val3 = 1;
	Ruby::UniformSet uniformsForShader {
		Ruby::Uniform::Float{ "u_Temp", val3 },
		Ruby::Uniform::Vector3f{ "u_Colour", Malachite::Vector3f{ val3 } }
	};

	Ruby::Uniform::Float* tempUniform = uniformsForShader.get<Ruby::Uniform::Float>("u_Temp");
	
	float val1 = 0.0f;
	tempUniform->setData(val1);
	val1 = 3.0f;

	// In main loop:
	//renderer.render(phongRenderable);





	// // Desired Funcitonality
	// Ruby::UniformSet uniforms {
	// 	// Vert
	// 	Ruby::Uniform::Matrix4x4f{"u_Model"},
	// 	Ruby::Uniform::Matrix4x4f{"u_Projection"},
	// 	Ruby::Uniform::Matrix4x4f{"u_View"},
	// 	// Frag
	// 	Ruby::Uniform::Vector3f{"u_Colour"}, 
	// 	Ruby::Uniform::Float{"u_Roughness"}
	// };
	//
	// Ruby::VertexShader vert{ "shaderPath" };
	//
	// Ruby::FragmentShader frag{ "shaderPath"};
	//
	// Ruby::ShaderProgram program{ vert, frag }; // Program should combine all incoming uniform sets into one larger one
	//
	// struct Material {
	// 	vec3 colour;
	// 	float roughness;
	// };
	//
	//
	// // Inside Render:
	// program.bind();
	// program.uploadUnifroms();







	//Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO

	// Shader setup
	renderer.shaders.phongShader.use();
	Ruby::ShaderProgram::upload("pointLights", pointLights);
	Ruby::ShaderProgram::upload("directionalLights", 2, directionalLights);

	// Renderer setup
	renderer.init(window.getProjectionMatrix());

	// Physics
	using namespace Pyrite::Literals;

	Pyrite::CollisionWorld collisionWorld{ };

	Pyrite::PhysicsObject staticObject{ 10_kg };
	Pyrite::SphereCollider staticCollider{ 3_m, Pyrite::Point3D{ 0.0_m } };
	collisionWorld.addCollider(staticCollider);
	//Pyrite::PhysicsObject movingObject{ 2.0_kg, Pyrite::Point3D{ 5.0_m, 0.0_m, 0.0_m } };
	//Pyrite::AxisAlignedBoxCollider movingCollider{ Pyrite::Point3D{ movingObject.position - 0.5_m }, Pyrite::Point3D{ movingObject.position + 0.5_m } };
	//collisionWorld.addCollider(movingCollider);

	Pyrite::Collider::Collision collision;

	Pyrite::PhysicsObject sunPhysics{ ((5.0_mPerS * 5.0_mPerS) * 30.0_m) / Pyrite::GravitationalConstant };
	//Pyrite::PhysicsObject earthPhysics{ ((2.0_mPerS * 2.0_mPerS) * 10.0_m) / Pyrite::GravitationalConstant, Pyrite::Point3D{ 30.0_m, 0.0_m, 0.0_m }};

	//earthPhysics.velocity.z = 5.0_mPerS;

	float val = 0.0f;
	std::unique_ptr<Ruby::Uniform::Float> test = std::make_unique<Ruby::Uniform::Float>("u_Temp", val);
	val = 5.0f;

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

		/*if (keyboard->KEY_UP) {
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
		}*/

		{ // Physics
			/*movingObject.calcVelocity(time.deltaTime);
			movingObject.calcPosition(time.deltaTime);
			movingObject.netForce = Pyrite::Newton3D{ 0.0_N };

			movingSphere.model = Malachite::Matrix4f{ 1.0f };
			movingSphere.model.translate(movingObject.position);

			movingCollider.min = movingObject.position - 0.5_m;
			movingCollider.max = movingObject.position + 0.5_m;

			staticObject.calcVelocity(time.deltaTime);
			staticObject.calcPosition(time.deltaTime);
			staticObject.netForce = Pyrite::Newton3D{ 0.0_N };*/

			staticSphere.model = Malachite::Matrix4f{ 1.0f };
			staticSphere.model.scale(3.0f);
			staticSphere.model.translate(staticObject.position);

			staticCollider.position = staticObject.position;

			collisionWorld.step();

			//collision = Pyrite::CollisionDetection::AABBWithSphere(&movingCollider, &staticCollider);

			//collision = movingCollider.collidesWithAABB(&staticCollider);

			/*if (collision.hasCollision) {
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
			}*/

			/*earthPhysics.netForce = Pyrite::Newton3D{ 0.0_N };
			earthPhysics.netForce += Pyrite::ForceGenerator::gravitationalForce(&sunPhysics, &earthPhysics);
			earthPhysics.calcVelocity(time.deltaTime);
			earthPhysics.calcPosition(time.deltaTime);

			sun.model = Malachite::Matrix4f{ 1.0f };
			sun.model.scale(2.0f);
			sun.model.translate(sunPhysics.position);

			earth.model = Malachite::Matrix4f{ 1.0f };
			earth.model.scale(2.0f);
			earth.model.translate(earthPhysics.position);*/
		}

		{ // Rendering
			renderer.prep();

			/*renderer.render(staticSphere);
			renderer.render(movingSphere);

			renderer.render(sun);
			renderer.render(earth);*/
			renderer.render(testObj1);
			renderer.render(testObj3);
			renderer.render(testObj2);

			renderer.render(skybox);

			{ // ImGui
				renderer.imGuiPrep();

				//ImGui::ShowDemoWindow();
				{

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