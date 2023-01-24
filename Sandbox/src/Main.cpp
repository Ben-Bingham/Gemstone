// Wavellite

// Ruby
#include "Camera.h"
#include "Renderable Objects/Renderable.h"

#include "Pointer.h"
#include "Geometry/MeshData.h"

// Pyrite
#include "Log.h"
#include "Vector.h"

// Custom

// Base
#include "Engine.h"

#include "GameObject.h"
#include "Components/MaterialComponent.h"
#include "Components/MeshComponent.h"
#include "Components/RenderingComponent.h"
#include "Components/Transform.h"

#include "Scene.h"
#include "Geometry/Mesh.h"
#include "Geometry/MeshManager.h"

#include "Materials/Material.h"
#include "Materials/MaterialManager.h"
#include "Input/Keyboard.h"
#include "Input/Mouse.h"

class GameLogic : public Esperite::System {
public:
	GameLogic() = default;
	~GameLogic() override = default;

	void Step(Esperite::Scene* scene) override {
		LOG(Wavellite::Mouse::Get().xPosition);
		if (Wavellite::Mouse::Get().button1) {
			LOG("W");
		}
	}
};

int main() {
	Emerald::Engine engine{};
	engine.AddDefaultSystems();

	Esperite::Scene testScene{};
	
	Esperite::GameObject gb = testScene.NewGameObject();
	
	testScene.AddComponent<Malachite::Transform>(gb);

	Malachite::Transform* transform = testScene.GetComponent<Malachite::Transform>(gb);
	transform->position().z -= 5.0f;

	testScene.AddComponent<Ruby::Mesh>(gb);
	testScene.AddComponent<Ruby::Material>(gb);

	Ruby::Mesh* mesh = testScene.GetComponent<Ruby::Mesh>(gb);
	mesh->mesh = Ruby::MeshManager::Get().NewMesh(Ruby::SPHERE);

	Ruby::Material* material = testScene.GetComponent<Ruby::Material>(gb);
	material->material = Ruby::MaterialManager::Get().NewMaterial();

	Esperite::GameObject cam = testScene.NewGameObject();
	testScene.AddComponent<Ruby::Camera>(cam);

	Ruby::Camera* camComponent = testScene.GetComponent<Ruby::Camera>(cam);
	camComponent->target = Ruby::RenderingTarget::WINDOW;

	engine.activeScene = &testScene;

	const Celestite::Ptr<GameLogic> gameLogic = Celestite::CreatePtr<GameLogic>();
	engine.AddSystem(gameLogic);

	engine.Start();















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
	// Celestite::Ptr<Ruby::SkyBoxMaterial> skyBoxMat = Celestite::CreatePtr<Ruby::SkyBoxMaterial>(std::initializer_list<Celestite::Ptr<Ruby::Image>>{
	// 	Celestite::CreatePtr<Ruby::Image>("assets\\SkyBox\\right.jpg", false),
	// 		Celestite::CreatePtr<Ruby::Image>("assets\\SkyBox\\left.jpg", false),
	// 		Celestite::CreatePtr<Ruby::Image>("assets\\SkyBox\\top.jpg", false),
	// 		Celestite::CreatePtr<Ruby::Image>("assets\\SkyBox\\bottom.jpg", false),
	// 		Celestite::CreatePtr<Ruby::Image>("assets\\SkyBox\\front.jpg", false),
	// 		Celestite::CreatePtr<Ruby::Image>("assets\\SkyBox\\back.jpg", false)
	// });
	//
	// //auto skyBox = Celestite::CreatePtr<Ruby::SkyBox>(skyBoxMat);
	//
	// Celestite::Ptr<Ruby::SolidMaterial> blueMaterial = Celestite::CreatePtr<Ruby::SolidMaterial>(Ruby::Colour::blue);
	//
	// Celestite::Ptr<Ruby::MeshData> cubeMesh = Celestite::CreatePtr<Ruby::MeshData>(Ruby::MeshData::Shape::CUBE);
	// Celestite::Ptr<Ruby::MeshData> planeMesh = Celestite::CreatePtr<Ruby::MeshData>(Ruby::MeshData::Shape::PLANE);
	// Celestite::Ptr<Ruby::MeshData> sphereMesh = Celestite::CreatePtr<Ruby::MeshData>(Ruby::MeshData::Shape::SPHERE);
	//
	// //auto testCube = Celestite::CreatePtr<Ruby::Renderable>(cubeMesh, blueMaterial );
	//
	// Celestite::Ptr<Ruby::PhongMaterial> containerMaterial = Celestite::CreatePtr<Ruby::PhongMaterial>(
	// 	Celestite::CreatePtr<Ruby::Texture>(Celestite::CreatePtr<Ruby::Image>("assets\\container2.png")),
	// 	Celestite::CreatePtr<Ruby::Texture>(Celestite::CreatePtr<Ruby::Image>("assets\\container2_specular.png"))
	// );
	//
	// std::vector<Ruby::DirectionalLight*> directionalLights{};
	// Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	// directionalLights.push_back(&directionalLight);
	//
	// Ruby::PhongMaterial::directionalLights = directionalLights;
	//
	// //auto phongCube = Celestite::CreatePtr<Ruby::Renderable>(cubeMesh, containerMaterial);
	// //phongCube->transform()->position().x = -3.0f;
	//
	// auto doughnutTexture = Celestite::CreatePtr<Ruby::Texture>(Celestite::CreatePtr<Ruby::Image>("assets\\Donut4.png"));
	// Celestite::Ptr<Ruby::PhongMaterial> donutMat = Celestite::CreatePtr<Ruby::PhongMaterial>(doughnutTexture, doughnutTexture);
	//
	// auto earthTexture = Celestite::CreatePtr<Ruby::Texture>(Celestite::CreatePtr<Ruby::Image>("assets\\earth.jpg"));
	// Celestite::Ptr<Ruby::PhongMaterial> earthMat = Celestite::CreatePtr<Ruby::PhongMaterial>(earthTexture, earthTexture);
	//
	// auto pawnTexture = Celestite::CreatePtr<Ruby::Texture>(Celestite::CreatePtr<Ruby::Image>("assets\\White Pawn.png"));
	// Celestite::Ptr<Ruby::PhongMaterial> pawnMat = Celestite::CreatePtr<Ruby::PhongMaterial>(pawnTexture, pawnTexture);
	//
	// auto awesomeFaceTexture = Celestite::CreatePtr<Ruby::Texture>(Celestite::CreatePtr<Ruby::Image>("assets\\awesomeface.png"));
	// Celestite::Ptr<Ruby::PhongMaterial> awesomeMat = Celestite::CreatePtr<Ruby::PhongMaterial>(awesomeFaceTexture, awesomeFaceTexture);
	//
	// //auto donut = Celestite::CreatePtr<Ruby::Renderable>(sphereMesh, donutMat);
	// //donut->transform()->scale().x = 1.0f;
	// //donut->transform()->scale().y = 0.4f;
	// //donut->transform()->scale().y = 1.0f;
	// //donut->transform()->position().x = -6.0f;
	// //
	// //auto earthRenderable = Celestite::CreatePtr<Ruby::Renderable>(sphereMesh, earthMat );
	// //earthRenderable->transform()->position().x = 3.0f;
	// //
	// //auto pawn = Celestite::CreatePtr<Ruby::Renderable>(cubeMesh, pawnMat );
	// //pawn->transform()->scale() = Malachite::Vector3f{ 0.6f, 2.0f, 0.6f };
	// //pawn->transform()->position() = Malachite::Vector3f{ 6.0f, 0.0f, 0.0f };
	// //
	// //auto awesomeRenderable = Celestite::CreatePtr<Ruby::Renderable>( cubeMesh, awesomeMat );
	// //awesomeRenderable->transform()->position().y = 3.0f;
	// //
	// //auto awesomeRenderable2 = Celestite::CreatePtr<Ruby::Renderable>(sphereMesh, awesomeMat );
	// //awesomeRenderable2->transform()->position().y = -3.0f;
	// //
	// //auto planeRenderable = Celestite::CreatePtr<Ruby::Renderable>(planeMesh, containerMaterial );
	// //planeRenderable->transform()->position().y = 3.0f;
	// //planeRenderable->transform()->position().x = 3.0f;
	// //
	// //Celestite::Ptr<Ruby::TextureMaterial> awesomeFaceMaterial = Celestite::CreatePtr<Ruby::TextureMaterial>(awesomeFaceTexture);
	// //auto texturedRenderable = Celestite::CreatePtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial );
	// //texturedRenderable->transform()->position().y = -3.0f;
	// //texturedRenderable->transform()->position().x = 3.0f;
	// //
	// //Celestite::Ptr<Ruby::ScreenMaterial> awesomeFaceMaterial2 = Celestite::CreatePtr<Ruby::ScreenMaterial>(earthTexture);
	// //auto screenQuadRenderable = Celestite::CreatePtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial2 );
	// //screenQuadRenderable->transform()->position().y = -0.5f;
	// //screenQuadRenderable->transform()->position().x = -0.5f;
	// //screenQuadRenderable->transform()->scale() = Malachite::Vector3f{ 0.5f };
	// //
	// //auto bigSphere = Celestite::CreatePtr<Ruby::Renderable>(sphereMesh, blueMaterial);
	// //bigSphere->transform()->position().x = 100.0f;
	// //bigSphere->transform()->scale() = Malachite::Vector3f{ 100.0f };
	//
	// //auto cubeRenderable = Celestite::CreatePtr<Ruby::Renderable>(cubeMesh, blueMaterial );
	//
	// //auto cubeRenderable2 = Celestite::CreatePtr<Ruby::Renderable>(cubeMesh, earthMat );
	// //cubeRenderable2->transform()->position().x = 3.0f;
	//
	// //Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO
	//
	// //auto testRenderable = Celestite::CreatePtr<Ruby::Renderable>(sphereMesh, blueMaterial); //TODO is not added to buckets properly
	//
	// std::vector<Celestite::Ptr<Ruby::Renderable>> cubes;
	//
	// for (int i = 0; i < 4; i++) {
	// 	for (int j = 0; j < 4; j++) {
	// 		for (int k = 0; k < 4; k++) {
	// 			//cubes.push_back(Celestite::CreatePtr<Ruby::Renderable>(cubeMesh, blueMaterial));
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
	// // auto transform = Celestite::CreatePtr<Emerald::TransformComponent>();
	// // gb.addComponent(transform);
	// // auto mesh = Celestite::CreatePtr<Emerald::MeshComponent>(cubeMesh);
	// // gb.addComponent(mesh);
	// // auto material = Celestite::CreatePtr<Emerald::MaterialComponent>(earthMat);
	// // gb.addComponent(material);
	//
	// // auto renderable = Celestite::CreatePtr<Emerald::RenderingComponent>(transform, mesh, material);
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