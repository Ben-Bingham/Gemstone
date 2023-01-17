// Wavellite
#include "Window.h"
#include "Timing.h"

// Ruby
#include "Renderers/Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Renderable.h"
#include "Materials/PhongMaterial.h"
#include "Materials/SolidMaterial.h"
#include "Renderable Objects/SkyBox.h"
#include "Resources/Image.h"
#include "Materials/ScreenMaterial.h"
#include "Materials/TextureMaterial.h"
#include "OpenGlErrors.h"
#include "Lights.h"
#include "OpenGLState.h"
#include "Pointer.h"
#include "Geometry/Mesh.h"
#include "Materials/SkyboxMaterial.h"
#include "OpenGL objects/Texture.h"
#include "Utility/Colour.h"

// Pyrite
#include "Units.h"
#include "PhysicsWorld.h"

#include "Log.h"
#include "Vector.h"
#include "Window.h"

// Custom
#include "FPSCamera.h"

// Base
#include "Engine.h"
#include "Pointer.h"

#include "Vector.h"

// #include "UglyGameObject.h"
#include "GameObject.h"
#include "Components/MaterialComponent.h"
#include "Components/MeshComponent.h"
#include "Components/RenderingComponent.h"
#include "Components/Transform.h"
#include <any>
#include <array>

#include "Scene.h"
#include "SceneManager.h"

class Transform { //TODO remove
public:
	Transform(const float x = 0, const float y = 0)
		: x(x), y(y) {
	}

	float x;
	float y;
};

class Test {
	
};

class AdvancedComponent {
public:
	AdvancedComponent() = default;

	std::array<float, 20> data;
};

int main() {
	Emerald::Engine engine{};
	engine.init();

	// Esperite::Scene testScene{};
	//
	// Esperite::GameObject gb = testScene.newGameObject();
	//
	// testScene.addComponent<Malachite::Transform>(gb);
	// testScene.addComponent<Ruby::Mesh>(gb);
	// testScene.addComponent<Ruby::SolidMaterial>(gb);
	//
	// Esperite::GameObject cam = testScene.newGameObject();
	//
	// testScene.addComponent<Ruby::Camera>(cam);
	//
	// engine.activeScene = &testScene;
	//
	// engine.start();

	using TransformComponent = Transform;
	using AdvComp = AdvancedComponent;
	Wavellite::Time time{ }; //TODO add to engine class


	Esperite::Scene timingScene{}; //TODO test the run time speed penalties of std::vector

	for (int i = 0; i < 1000000; i++) {
		Esperite::GameObject gb = timingScene.newGameObject();

		timingScene.AddComponent<TransformComponent>(gb);
		timingScene.AddComponent<AdvComp>(gb);
	}

	for (int i = 0; i < 100; i++) {
		float startTime = time.getTime();

		for (Esperite::GameObject gb : timingScene.gameObjects) {
			if (timingScene.HasComponent<TransformComponent>(gb) && timingScene.HasComponent<AdvComp>(gb)) {
				TransformComponent* transform = timingScene.GetComponent<TransformComponent>(gb);
				const AdvComp* advComp = timingScene.GetComponent<AdvComp>(gb);

				for (auto& val : advComp->data) {
					transform->x += val;
					transform->y -= val;
				}
			}
		}
		
		float endTime = time.getTime();

		for (Esperite::GameObject gb : timingScene.gameObjects) {
			timingScene.GetComponent<TransformComponent>(gb)->x = 0.0f;
			timingScene.GetComponent<TransformComponent>(gb)->y = 0.0f;
		}

		LOG(std::to_string(endTime - startTime));
	}

	LOG("DONE");
	std::cin.get();






	// // Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f };
	// // window.setSwapInterval(0);
	// Wavellite::Window& window = engine.window();
	//
	// Wavellite::Mouse& mouse = window.ioManger.getMouse();
	// Wavellite::Keyboard& keyboard = window.ioManger.getKeyboard();
	//
	// FPSCamera camera{};
	// mouse.addMousePositionCallback(mousePositionCallback, (void*)&camera);
	// bool cursor = false;
	// window.disableCursor();
	//
	// Wavellite::Time time{ }; //TODO add to engine class
	//
	// // Ruby::Renderer renderer{ window, &camera };
	//
	// camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 5.0f };
	//
	// Celestite::Ptr<Ruby::SkyBoxMaterial> skyBoxMat = Celestite::createPtr<Ruby::SkyBoxMaterial>(std::initializer_list<Celestite::Ptr<Ruby::Image>>{
	// 	Celestite::createPtr<Ruby::Image>("assets\\SkyBox\\right.jpg", false),
	// 		Celestite::createPtr<Ruby::Image>("assets\\SkyBox\\left.jpg", false),
	// 		Celestite::createPtr<Ruby::Image>("assets\\SkyBox\\top.jpg", false),
	// 		Celestite::createPtr<Ruby::Image>("assets\\SkyBox\\bottom.jpg", false),
	// 		Celestite::createPtr<Ruby::Image>("assets\\SkyBox\\front.jpg", false),
	// 		Celestite::createPtr<Ruby::Image>("assets\\SkyBox\\back.jpg", false)
	// });
	//
	// //auto skyBox = Celestite::createPtr<Ruby::SkyBox>(skyBoxMat);
	//
	// Celestite::Ptr<Ruby::SolidMaterial> blueMaterial = Celestite::createPtr<Ruby::SolidMaterial>(Ruby::Colour::blue);
	//
	// Celestite::Ptr<Ruby::Mesh> cubeMesh = Celestite::createPtr<Ruby::Mesh>(Ruby::Mesh::Shape::CUBE);
	// Celestite::Ptr<Ruby::Mesh> planeMesh = Celestite::createPtr<Ruby::Mesh>(Ruby::Mesh::Shape::PLANE);
	// Celestite::Ptr<Ruby::Mesh> sphereMesh = Celestite::createPtr<Ruby::Mesh>(Ruby::Mesh::Shape::SPHERE);
	//
	// //auto testCube = Celestite::createPtr<Ruby::Renderable>(cubeMesh, blueMaterial );
	//
	// Celestite::Ptr<Ruby::PhongMaterial> containerMaterial = Celestite::createPtr<Ruby::PhongMaterial>(
	// 	Celestite::createPtr<Ruby::Texture>(Celestite::createPtr<Ruby::Image>("assets\\container2.png")),
	// 	Celestite::createPtr<Ruby::Texture>(Celestite::createPtr<Ruby::Image>("assets\\container2_specular.png"))
	// );
	//
	// std::vector<Ruby::DirectionalLight*> directionalLights{};
	// Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	// directionalLights.push_back(&directionalLight);
	//
	// Ruby::PhongMaterial::directionalLights = directionalLights;
	//
	// //auto phongCube = Celestite::createPtr<Ruby::Renderable>(cubeMesh, containerMaterial);
	// //phongCube->transform()->position().x = -3.0f;
	//
	// auto doughnutTexture = Celestite::createPtr<Ruby::Texture>(Celestite::createPtr<Ruby::Image>("assets\\Donut4.png"));
	// Celestite::Ptr<Ruby::PhongMaterial> donutMat = Celestite::createPtr<Ruby::PhongMaterial>(doughnutTexture, doughnutTexture);
	//
	// auto earthTexture = Celestite::createPtr<Ruby::Texture>(Celestite::createPtr<Ruby::Image>("assets\\earth.jpg"));
	// Celestite::Ptr<Ruby::PhongMaterial> earthMat = Celestite::createPtr<Ruby::PhongMaterial>(earthTexture, earthTexture);
	//
	// auto pawnTexture = Celestite::createPtr<Ruby::Texture>(Celestite::createPtr<Ruby::Image>("assets\\White Pawn.png"));
	// Celestite::Ptr<Ruby::PhongMaterial> pawnMat = Celestite::createPtr<Ruby::PhongMaterial>(pawnTexture, pawnTexture);
	//
	// auto awesomeFaceTexture = Celestite::createPtr<Ruby::Texture>(Celestite::createPtr<Ruby::Image>("assets\\awesomeface.png"));
	// Celestite::Ptr<Ruby::PhongMaterial> awesomeMat = Celestite::createPtr<Ruby::PhongMaterial>(awesomeFaceTexture, awesomeFaceTexture);
	//
	// //auto donut = Celestite::createPtr<Ruby::Renderable>(sphereMesh, donutMat);
	// //donut->transform()->scale().x = 1.0f;
	// //donut->transform()->scale().y = 0.4f;
	// //donut->transform()->scale().y = 1.0f;
	// //donut->transform()->position().x = -6.0f;
	// //
	// //auto earthRenderable = Celestite::createPtr<Ruby::Renderable>(sphereMesh, earthMat );
	// //earthRenderable->transform()->position().x = 3.0f;
	// //
	// //auto pawn = Celestite::createPtr<Ruby::Renderable>(cubeMesh, pawnMat );
	// //pawn->transform()->scale() = Malachite::Vector3f{ 0.6f, 2.0f, 0.6f };
	// //pawn->transform()->position() = Malachite::Vector3f{ 6.0f, 0.0f, 0.0f };
	// //
	// //auto awesomeRenderable = Celestite::createPtr<Ruby::Renderable>( cubeMesh, awesomeMat );
	// //awesomeRenderable->transform()->position().y = 3.0f;
	// //
	// //auto awesomeRenderable2 = Celestite::createPtr<Ruby::Renderable>(sphereMesh, awesomeMat );
	// //awesomeRenderable2->transform()->position().y = -3.0f;
	// //
	// //auto planeRenderable = Celestite::createPtr<Ruby::Renderable>(planeMesh, containerMaterial );
	// //planeRenderable->transform()->position().y = 3.0f;
	// //planeRenderable->transform()->position().x = 3.0f;
	// //
	// //Celestite::Ptr<Ruby::TextureMaterial> awesomeFaceMaterial = Celestite::createPtr<Ruby::TextureMaterial>(awesomeFaceTexture);
	// //auto texturedRenderable = Celestite::createPtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial );
	// //texturedRenderable->transform()->position().y = -3.0f;
	// //texturedRenderable->transform()->position().x = 3.0f;
	// //
	// //Celestite::Ptr<Ruby::ScreenMaterial> awesomeFaceMaterial2 = Celestite::createPtr<Ruby::ScreenMaterial>(earthTexture);
	// //auto screenQuadRenderable = Celestite::createPtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial2 );
	// //screenQuadRenderable->transform()->position().y = -0.5f;
	// //screenQuadRenderable->transform()->position().x = -0.5f;
	// //screenQuadRenderable->transform()->scale() = Malachite::Vector3f{ 0.5f };
	// //
	// //auto bigSphere = Celestite::createPtr<Ruby::Renderable>(sphereMesh, blueMaterial);
	// //bigSphere->transform()->position().x = 100.0f;
	// //bigSphere->transform()->scale() = Malachite::Vector3f{ 100.0f };
	//
	// //auto cubeRenderable = Celestite::createPtr<Ruby::Renderable>(cubeMesh, blueMaterial );
	//
	// //auto cubeRenderable2 = Celestite::createPtr<Ruby::Renderable>(cubeMesh, earthMat );
	// //cubeRenderable2->transform()->position().x = 3.0f;
	//
	// //Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO
	//
	// //auto testRenderable = Celestite::createPtr<Ruby::Renderable>(sphereMesh, blueMaterial); //TODO is not added to buckets properly
	//
	// std::vector<Celestite::Ptr<Ruby::Renderable>> cubes;
	//
	// for (int i = 0; i < 4; i++) {
	// 	for (int j = 0; j < 4; j++) {
	// 		for (int k = 0; k < 4; k++) {
	// 			//cubes.push_back(Celestite::createPtr<Ruby::Renderable>(cubeMesh, blueMaterial));
	// 			//cubes.back()->transform()->position() = Malachite::Vector3f{(float)i, (float)j, (float)k};
	// 		}
	// 	}
	// }
	//
	// int frameCount = 0;
	// float averageDelta = 0.0f;
	//
	// // Esperite::UglyGameObject gb{};
	//
	// // auto transform = Celestite::createPtr<Emerald::TransformComponent>();
	// // gb.addComponent(transform);
	// // auto mesh = Celestite::createPtr<Emerald::MeshComponent>(cubeMesh);
	// // gb.addComponent(mesh);
	// // auto material = Celestite::createPtr<Emerald::MaterialComponent>(earthMat);
	// // gb.addComponent(material);
	//
	// // auto renderable = Celestite::createPtr<Emerald::RenderingComponent>(transform, mesh, material);
	//
	// // engine.enlist(gb);
	//
	// // Rendering loop
	// while (window.isOpen()) {
	// 	window.pollEvents();
	// 	float velocity = 0.05f;
	// 	 
	// 	if (keyboard.KEY_W) {
	// 		camera.position += camera.front * velocity;
	// 	}
	//
	// 	if (keyboard.KEY_A) {
	// 		camera.position -= camera.right * velocity;
	// 	}
	//
	// 	if (keyboard.KEY_S) {
	// 		camera.position -= camera.front * velocity;
	// 	}
	//
	// 	if (keyboard.KEY_D) {
	// 		camera.position += camera.right * velocity;
	// 	}
	//
	// 	if (keyboard.KEY_SPACE) {
	// 		camera.position += Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
	// 	}
	//
	// 	if (keyboard.KEY_LEFT_SHIFT) {
	// 		camera.position -= Malachite::Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
	// 	}
	//
	// 	if (keyboard.KEY_ESCAPE) {
	// 		window.close();
	// 	}
	//
	// 	if (mouse.button2) {
	// 		if (cursor) {
	// 			window.disableCursor();
	// 			cursor = false;
	// 		}
	// 		else {
	// 			window.enableCursor();
	// 			cursor = true;
	// 		}
	// 	}
	//
	// 	{ // Physics
	//
	// 	}
	//
	// 	{ // Rendering
	// 		// renderer.beginFrame();
	// 		//
	// 		// for (const Celestite::Ptr<Ruby::Renderable>& cube : cubes) {
	// 		// 	renderer.render(cube);
	// 		// }
	// 		//
	// 		// if (keyboard.KEY_B) {
	// 		// 	renderer.render(testRenderable);
	// 		// }
	// 		//
	// 		// renderer.render(cubeRenderable2);
	// 		//
	// 		// renderer.render(donut);
	// 		// // renderer.render(bigSphere);
	// 		// renderer.render(earthRenderable);
	// 		// renderer.render(pawn);
	// 		// renderer.render(awesomeRenderable);
	// 		// renderer.render(awesomeRenderable2);
	// 		//
	// 		// renderer.render(testCube);
	// 		// renderer.render(phongCube);
	// 		//
	// 		// { // Planes
	// 		// 	Ruby::OpenGlState::Face culledFace = Ruby::OpenGlState::get().getFaceToCull();
	// 		// 	Ruby::OpenGlState::get().setFaceToCull(Ruby::OpenGlState::Face::NONE);
	// 		//
	// 		// 	renderer.render(planeRenderable);
	// 		// 	renderer.render(texturedRenderable);
	// 		// 	// renderer.render(screenQuadRenderable);
	// 		//
	// 		// 	Ruby::OpenGlState::get().setFaceToCull(culledFace);
	// 		// }
	// 		//
	// 		// renderer.debugRender(std::vector{ Malachite::Vector3f{ 0.0f, 0.0f, 0.0f }, Malachite::Vector3f{ (float)mouse.xPosition, (float)mouse.yPosition, 5.0f } });
	// 		// //renderer.debugRender(cubeMesh, Malachite::Vector3f{0.0f, 0.0f, 0.0f}, Malachite::Vector3f{3.0f, 3.0f, 3.0f}); //TODO non functional
	// 		//
	// 		// renderer.render(skyBox);
	// 		//
	// 		// renderer.imGuiPrep();
	// 		// {
	// 		// 	ImGui::Begin("Settings");
	// 		// 	{
	// 		// 		ImGui::SliderFloat3("Position", &pawn->transform()->position().x, -10.0f, 10.0f);
	// 		// 	}
	// 		// 	ImGui::End();
	// 		// }
	// 		// renderer.imGuiEnd();
	// 		//
	// 		// renderer.endFrame();
	// 		// glCheckError();
	// 	}
	//
	// 	window.swapBuffers();
	// 	time.endFrame();
	// 	frameCount++;
	// 	averageDelta += time.deltaTime;
	//
	// 	if (frameCount == 100) {
	// 		// break;
	// 	}
	// }
	//
	// LOG("Number of frames: " + std::to_string(frameCount));
	// LOG("Average delta time: " + std::to_string(averageDelta / (float)frameCount));
	// LOG("Average FPS: " + std::to_string(1 / (averageDelta / (float)frameCount)));

	// std::cin.get();

	// renderer.imGuiTerminate();
}