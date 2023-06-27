// #include "Celestite/Pointer.h"
//
// #include "Emerald/ECSManager.h"
//
// #include "Esperite/System.h"
//
// #include "Malachite/Angles.h"
// #include "Malachite/Vector.h"
//
// #include "Ruby/Camera.h"
//
// #include "Wavellite/Window.h"
// #include "Wavellite/Input/Keyboard.h"
// #include "Wavellite/Input/Mouse.h"
// #include "Malachite/Utility/Transform.h"
//
// #include "Ruby/Lights.h"
// #include "Ruby/Geometry/Mesh.h"
// #include "Ruby/Geometry/MeshData.h"
// #include "Ruby/Materials/Material.h"
// #include "Ruby/Materials/PhongMaterial.h"
// #include "Ruby/Materials/SolidMaterial.h"
// #include "Ruby/Renderers/RenderingSystem.h"
// #include "Ruby/Resources/Image.h"
// #include "Ruby/Utility/Colour.h"
//
// #include "imgui.h"
//
// class MovementController {
// public:
// 	float movementSpeed{ 0.1f };
//
// 	int lastXPosition{ 0 };
// 	int lastYPosition{ 0 };
// 	bool firstMouseMovement{ false };
// 	float mouseSensitivity{ 0.1f };
// 	Degree yaw{ -90.0f };
// 	Degree pitch{ 0.0f };
// };
//
// class Movement : public Gem::System {
// public:
// 	Movement() = default;
// 	~Movement() override = default;
//
// 	void StartUp(Gem::Scene* scene) override {
// 		Wavellite::Window::Get().disableCursor();
// 	}
//
// 	void Step(Gem::Scene* scene) override {
// 		for (auto& gb : scene->gameObjects) {
// 			if (scene->HasComponent<MovementController>(gb)
// 				&& scene->HasComponent<Transform>(gb)
// 				&& scene->HasComponent<Ruby::Camera>(gb)) {
//
// 				MovementController* controller = scene->GetComponent<MovementController>(gb);
// 				Transform* transform = scene->GetComponent<Transform>(gb);
// 				Ruby::Camera* camera = scene->GetComponent<Ruby::Camera>(gb);
//
// 				const Wavellite::Keyboard& keyboard = Wavellite::Keyboard::Get();
//
// 				Vector3f up = Vector3f::up;
// 				Vector3f left = cross(camera->forward, up).normalize();
//
// 				if (keyboard.KEY_W) { transform->position() += camera->forward * controller->movementSpeed; }
// 				if (keyboard.KEY_S) { transform->position() -= camera->forward * controller->movementSpeed; }
// 				if (keyboard.KEY_A) { transform->position() -= left * controller->movementSpeed; }
// 				if (keyboard.KEY_D) { transform->position() += left * controller->movementSpeed; }
// 				if (keyboard.KEY_SPACE) { transform->position() += up * controller->movementSpeed; }
// 				if (keyboard.KEY_LEFT_SHIFT) { transform->position() -= up * controller->movementSpeed; }
//
// 				if (Wavellite::Mouse::Get().hasMoved) {
// 					if (!controller->firstMouseMovement) {
// 						controller->lastXPosition = Wavellite::Mouse::Get().xPosition;
// 						controller->lastYPosition = Wavellite::Mouse::Get().yPosition;
// 						controller->firstMouseMovement = true;
// 					}
//
// 					float xOffset = (float)(Wavellite::Mouse::Get().xPosition - controller->lastXPosition);
// 					float yOffset = (float)(controller->lastYPosition - Wavellite::Mouse::Get().yPosition);
// 					controller->lastXPosition = Wavellite::Mouse::Get().xPosition;
// 					controller->lastYPosition = Wavellite::Mouse::Get().yPosition;
//
// 					xOffset *= controller->mouseSensitivity;
// 					yOffset *= controller->mouseSensitivity;
//
// 					controller->yaw += xOffset;
// 					controller->pitch += yOffset;
//
// 					if (controller->pitch > 89.0f)
// 						controller->pitch = 89.0f;
// 					if (controller->pitch < -89.0f)
// 						controller->pitch = -89.0f;
//
// 					Vector3f direction;
// 					direction.x = cos(degreesToRadians(controller->yaw)) * cos(degreesToRadians(controller->pitch));
// 					direction.y = sin(degreesToRadians(controller->pitch));
// 					direction.z = sin(degreesToRadians(controller->yaw)) * cos(degreesToRadians(controller->pitch));
//
// 					camera->forward = direction.normalize();
// 				}
// 			}
// 		}
// 	}
// };
//
// class UISystem : public Gem::System {
// public:
// 	using GUI = Ruby::RenderingSystem::GUI;
//
// 	UISystem() = default;
//
// 	void StartUp(Gem::Scene* scene) override {
// 		GUI::StartUp();
// 	}
//
// 	void Step(Gem::Scene* scene) override {
// 		GUI::Begin();
// 		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
//
// 		if (ImGui::Begin("Test")) {
// 			// ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
// 			// ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f));
// 			ImGui::Text("Hello World!");
// 		}
// 		ImGui::End();
//
// 		ImGui::ShowDemoWindow();
// 		// ImGui::ShowDemoWindow();
// 		
// 		GUI::End();
// 		
// 		if (Wavellite::Keyboard::Get().KEY_ESCAPE) {
// 			Wavellite::Window::Get().Close();
// 		}
// 		if (Wavellite::Keyboard::Get().KEY_M) {
// 			Wavellite::Window::Get().enableCursor();
// 		}
// 		else if (Wavellite::Keyboard::Get().KEY_N) {
// 			Wavellite::Window::Get().disableCursor();
// 		}
// 	}
//
// 	void ShutDown(Gem::Scene* scene) override {
// 		GUI::ShutDown();
// 	}
// };
//
// using namespace Celestite;
// int main2() {
// 	Emerald::ECSManager engine{};
// 	engine.AddDefaultSystems();
//
// 	Gem::Scene scene{};
//
// 	const Gem::InternalGameObject player = scene.NewGameObject<Ruby::Camera, MovementController, Transform>();
// 	Transform* playerTransform = scene.GetComponent<Transform>(player);
// 	playerTransform->position().z = 5.0f;
//
// 	Ruby::Camera* camComponent = scene.GetComponent<Ruby::Camera>(player);
// 	camComponent->target = Ruby::RenderingTarget::WINDOW;
//
//
// 	// engine.AddSystem(CreatePtr<Emerald::Input>());
// 	// engine.AddSystem(CreatePtr<Ruby::RenderingSystem>(Wavellite::Window::Get()));
// 	// engine.AddSystem(CreatePtr<Ruby::ViewMatrixCorrection>());
//
// 	engine.AddSystem(CreatePtr<Movement>());
// 	engine.AddSystem(CreatePtr<UISystem>());
//
// 	engine.activeScene = &scene;
//
// 	// Meshes
// 	Ptr<Ruby::MeshData> cubeMesh = CreatePtr<Ruby::MeshData>(CreatePtr<Ruby::Cube>());
// 	Ptr<Ruby::MeshData> planeMesh = CreatePtr<Ruby::MeshData>(CreatePtr<Ruby::Plane>());
// 	Ptr<Ruby::MeshData> sphereMesh = CreatePtr<Ruby::MeshData>(CreatePtr<Ruby::Sphere>());
//
// 	// Materials
// 	Ruby::PhongMaterial::directionalLights.push_back(CreatePtr<Ruby::DirectionalLight>());
//
// 	Ptr<Ruby::SolidMaterial> blueMaterial = CreatePtr<Ruby::SolidMaterial>(Ruby::Colour::blue);
//
// 	// Ptr<Ruby::SkyBoxMaterial> skyBoxMat = CreatePtr<Ruby::SkyBoxMaterial>(std::initializer_list<Ptr<Ruby::Image>>{
// 	// 	CreatePtr<Ruby::Image>("assets\\SkyBox\\right.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\left.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\top.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\bottom.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\front.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\back.jpg", false)
// 	// });
//
// 	Ptr<Ruby::PhongMaterial> containerMaterial = CreatePtr<Ruby::PhongMaterial>(
// 		CreatePtr<Ruby::Image>("assets\\container2.png"),
// 		CreatePtr<Ruby::Image>("assets\\container2_specular.png")
// 	);
// 	
// 	auto doughnutImage = CreatePtr<Ruby::Image>("assets\\Donut4.png");
// 	Ptr<Ruby::PhongMaterial> doughnutMat = CreatePtr<Ruby::PhongMaterial>(doughnutImage, doughnutImage);
// 	
// 	auto earthImage = CreatePtr<Ruby::Image>("assets\\earth.jpg");
// 	Ptr<Ruby::PhongMaterial> earthMat = CreatePtr<Ruby::PhongMaterial>(earthImage, earthImage);
// 	
// 	auto pawnImage = CreatePtr<Ruby::Image>("assets\\White Pawn.png");
// 	Ptr<Ruby::PhongMaterial> pawnMat = CreatePtr<Ruby::PhongMaterial>(pawnImage, pawnImage);
// 	
// 	auto awesomeFaceImage = CreatePtr<Ruby::Image>("assets\\awesomeface.png");
// 	Ptr<Ruby::PhongMaterial> awesomeMat = CreatePtr<Ruby::PhongMaterial>(awesomeFaceImage, awesomeFaceImage);
//
//
// 	// Game Objects
// 	Gem::InternalGameObject doughnut = scene.NewGameObject<Ruby::Mesh, Ruby::Material, Transform>();
// 	scene.GetComponent<Ruby::Mesh>(doughnut)->mesh = sphereMesh;
// 	scene.GetComponent<Ruby::Material>(doughnut)->material = doughnutMat;
// 	Transform* doughnutTransform = scene.GetComponent<Transform>(doughnut);
// 	doughnutTransform->scale().x = 1.0f;
// 	doughnutTransform->scale().y = 0.4f;
// 	doughnutTransform->scale().z = 1.0f;
// 	doughnutTransform->position().x = -6.0f;
// 	
// 	Gem::InternalGameObject earth = scene.NewGameObject<Ruby::Mesh, Ruby::Material, Transform>();
// 	scene.GetComponent<Ruby::Mesh>(earth)->mesh = sphereMesh;
// 	scene.GetComponent<Ruby::Material>(earth)->material = earthMat;
// 	Transform* earthTransform = scene.GetComponent<Transform>(earth);
// 	earthTransform->position().x = 3.0f;
//
// 	Gem::InternalGameObject pawn = scene.NewGameObject<Ruby::Mesh, Ruby::Material, Transform>();
// 	scene.GetComponent<Ruby::Mesh>(pawn)->mesh = cubeMesh;
// 	scene.GetComponent<Ruby::Material>(pawn)->material = pawnMat;
// 	Transform* pawnTransform = scene.GetComponent<Transform>(pawn);
// 	pawnTransform->position() = Vector3f{ 6.0f, 0.0f, 0.0f };
// 	pawnTransform->scale() = Vector3f{ 0.6f, 2.0f, 0.6f };
//
// 	Gem::InternalGameObject awesome = scene.NewGameObject<Ruby::Mesh, Ruby::Material, Transform>();
// 	scene.GetComponent<Ruby::Mesh>(awesome)->mesh = cubeMesh;
// 	scene.GetComponent<Ruby::Material>(awesome)->material = awesomeMat;
// 	Transform* awesomeTransform = scene.GetComponent<Transform>(awesome);
// 	awesomeTransform->position().y = 3.0f;
// 	
// 	Gem::InternalGameObject awesome2 = scene.NewGameObject<Ruby::Mesh, Ruby::Material, Transform>();
// 	scene.GetComponent<Ruby::Mesh>(awesome2)->mesh = sphereMesh;
// 	scene.GetComponent<Ruby::Material>(awesome2)->material = awesomeMat;
// 	Transform* awesome2Transform = scene.GetComponent<Transform>(awesome2);
// 	awesome2Transform->position().y = -3.0f;
//
// 	Gem::InternalGameObject plane = scene.NewGameObject<Ruby::Mesh, Ruby::Material, Transform>();
// 	scene.GetComponent<Ruby::Mesh>(plane)->mesh = planeMesh;
// 	scene.GetComponent<Ruby::Material>(plane)->material = containerMaterial;
// 	Transform* planeTransform = scene.GetComponent<Transform>(plane);
// 	planeTransform->position().x = 3.0f;
// 	planeTransform->position().y = 3.0f;
//
// 	// Ptr<Ruby::TextureMaterial> awesomeFaceMaterial = CreatePtr<Ruby::TextureMaterial>(awesomeFaceTexture);
// 	// auto texturedRenderable = CreatePtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial );
// 	// texturedRenderable->transform()->position().y = -3.0f;
// 	// texturedRenderable->transform()->position().x = 3.0f;
// 	//
// 	// Ptr<Ruby::ScreenMaterial> awesomeFaceMaterial2 = CreatePtr<Ruby::ScreenMaterial>(earthTexture);
// 	// auto screenQuadRenderable = CreatePtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial2 );
// 	// screenQuadRenderable->transform()->position().y = -0.5f;
// 	// screenQuadRenderable->transform()->position().x = -0.5f;
// 	// screenQuadRenderable->transform()->scale() = Vector3f{ 0.5f };
//
// 	Gem::InternalGameObject cube = scene.NewGameObject<Ruby::Mesh, Ruby::Material, Transform>();
// 	scene.GetComponent<Ruby::Mesh>(cube)->mesh = cubeMesh;
// 	scene.GetComponent<Ruby::Material>(cube)->material = blueMaterial;
//
// 	// Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO
//
// 	engine.Start();
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// 	// // Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f };
// 	// // window.setSwapInterval(0);
// 	// Wavellite::Window& window = engine.window();
// 	//
// 	// Wavellite::Mouse& mouse = window.ioManger.getMouse();
// 	// Wavellite::Keyboard& keyboard = window.ioManger.getKeyboard();
// 	//
// 	// FPSCamera camera{};
// 	// mouse.addMousePositionCallback(mousePositionCallback, (void*)&camera);
// 	// bool cursor = false;
// 	// window.disableCursor();
// 	//
// 	// Wavellite::Time time{ }; //TODO add to engine class
// 	//
// 	// // Ruby::RenderingSystem renderer{ window, &camera };
// 	//
// 	// camera.position = Vector3f{ 0.0f, 0.0f, 5.0f };
// 	//
// 	// Ptr<Ruby::SkyBoxMaterial> skyBoxMat = CreatePtr<Ruby::SkyBoxMaterial>(std::initializer_list<Ptr<Ruby::Image>>{
// 	// 	CreatePtr<Ruby::Image>("assets\\SkyBox\\right.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\left.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\top.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\bottom.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\front.jpg", false),
// 	// 		CreatePtr<Ruby::Image>("assets\\SkyBox\\back.jpg", false)
// 	// });
// 	//
// 	// //auto skyBox = CreatePtr<Ruby::SkyBox>(skyBoxMat);
// 	//
// 	// Ptr<Ruby::SolidMaterial> blueMaterial = CreatePtr<Ruby::SolidMaterial>(Ruby::Colour::blue);
// 	//
// 	// Ptr<Ruby::MeshData> cubeMesh = CreatePtr<Ruby::MeshData>(Ruby::MeshData::Shape::CUBE);
// 	// Ptr<Ruby::MeshData> planeMesh = CreatePtr<Ruby::MeshData>(Ruby::MeshData::Shape::PLANE);
// 	// Ptr<Ruby::MeshData> sphereMesh = CreatePtr<Ruby::MeshData>(Ruby::MeshData::Shape::SPHERE);
// 	//
// 	// //auto testCube = CreatePtr<Ruby::Renderable>(cubeMesh, blueMaterial );
// 	//
// 	// Ptr<Ruby::PhongMaterial> containerMaterial = CreatePtr<Ruby::PhongMaterial>(
// 	// 	CreatePtr<Ruby::Texture>(CreatePtr<Ruby::Image>("assets\\container2.png")),
// 	// 	CreatePtr<Ruby::Texture>(CreatePtr<Ruby::Image>("assets\\container2_specular.png"))
// 	// );
// 	//
// 	// std::vector<Ruby::DirectionalLight*> directionalLights{};
// 	// Ruby::DirectionalLight directionalLight{ Vector3f{ 3.0f, -3.0f, 0.5f } };
// 	// directionalLights.push_back(&directionalLight);
// 	//
// 	// Ruby::PhongMaterial::directionalLights = directionalLights;
// 	//
// 	// //auto phongCube = CreatePtr<Ruby::Renderable>(cubeMesh, containerMaterial);
// 	// //phongCube->transform()->position().x = -3.0f;
// 	//
// 	// auto doughnutTexture = CreatePtr<Ruby::Texture>(CreatePtr<Ruby::Image>("assets\\Donut4.png"));
// 	// Ptr<Ruby::PhongMaterial> donutMat = CreatePtr<Ruby::PhongMaterial>(doughnutTexture, doughnutTexture);
// 	//
// 	// auto earthTexture = CreatePtr<Ruby::Texture>(CreatePtr<Ruby::Image>("assets\\earth.jpg"));
// 	// Ptr<Ruby::PhongMaterial> earthMat = CreatePtr<Ruby::PhongMaterial>(earthTexture, earthTexture);
// 	//
// 	// auto pawnTexture = CreatePtr<Ruby::Texture>(CreatePtr<Ruby::Image>("assets\\White Pawn.png"));
// 	// Ptr<Ruby::PhongMaterial> pawnMat = CreatePtr<Ruby::PhongMaterial>(pawnTexture, pawnTexture);
// 	//
// 	// auto awesomeFaceTexture = CreatePtr<Ruby::Texture>(CreatePtr<Ruby::Image>("assets\\awesomeface.png"));
// 	// Ptr<Ruby::PhongMaterial> awesomeMat = CreatePtr<Ruby::PhongMaterial>(awesomeFaceTexture, awesomeFaceTexture);
// 	//
// 	// //auto donut = CreatePtr<Ruby::Renderable>(sphereMesh, donutMat);
// 	// //donut->transform()->scale().x = 1.0f;
// 	// //donut->transform()->scale().y = 0.4f;
// 	// //donut->transform()->scale().y = 1.0f;
// 	// //donut->transform()->position().x = -6.0f;
// 	// //
// 	// //auto earthRenderable = CreatePtr<Ruby::Renderable>(sphereMesh, earthMat );
// 	// //earthRenderable->transform()->position().x = 3.0f;
// 	// //
// 	// //auto pawn = CreatePtr<Ruby::Renderable>(cubeMesh, pawnMat );
// 	// //pawn->transform()->scale() = Vector3f{ 0.6f, 2.0f, 0.6f };
// 	// //pawn->transform()->position() = Vector3f{ 6.0f, 0.0f, 0.0f };
// 	// //
// 	// //auto awesomeRenderable = CreatePtr<Ruby::Renderable>( cubeMesh, awesomeMat );
// 	// //awesomeRenderable->transform()->position().y = 3.0f;
// 	// //
// 	// //auto awesomeRenderable2 = CreatePtr<Ruby::Renderable>(sphereMesh, awesomeMat );
// 	// //awesomeRenderable2->transform()->position().y = -3.0f;
// 	// //
// 	// //auto planeRenderable = CreatePtr<Ruby::Renderable>(planeMesh, containerMaterial );
// 	// //planeRenderable->transform()->position().y = 3.0f;
// 	// //planeRenderable->transform()->position().x = 3.0f;
// 	// //
// 	// //Ptr<Ruby::TextureMaterial> awesomeFaceMaterial = CreatePtr<Ruby::TextureMaterial>(awesomeFaceTexture);
// 	// //auto texturedRenderable = CreatePtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial );
// 	// //texturedRenderable->transform()->position().y = -3.0f;
// 	// //texturedRenderable->transform()->position().x = 3.0f;
// 	// //
// 	// //Ptr<Ruby::ScreenMaterial> awesomeFaceMaterial2 = CreatePtr<Ruby::ScreenMaterial>(earthTexture);
// 	// //auto screenQuadRenderable = CreatePtr<Ruby::Renderable>(planeMesh, awesomeFaceMaterial2 );
// 	// //screenQuadRenderable->transform()->position().y = -0.5f;
// 	// //screenQuadRenderable->transform()->position().x = -0.5f;
// 	// //screenQuadRenderable->transform()->scale() = Vector3f{ 0.5f };
// 	// //
// 	// //auto bigSphere = CreatePtr<Ruby::Renderable>(sphereMesh, blueMaterial);
// 	// //bigSphere->transform()->position().x = 100.0f;
// 	// //bigSphere->transform()->scale() = Vector3f{ 100.0f };
// 	//
// 	// //auto cubeRenderable = CreatePtr<Ruby::Renderable>(cubeMesh, blueMaterial );
// 	//
// 	// //auto cubeRenderable2 = CreatePtr<Ruby::Renderable>(cubeMesh, earthMat );
// 	// //cubeRenderable2->transform()->position().x = 3.0f;
// 	//
// 	// //Ruby::CubeRenderable cube{/*position, width, height, depth*/}; //TODO
// 	//
// 	// //auto testRenderable = CreatePtr<Ruby::Renderable>(sphereMesh, blueMaterial); //TODO is not added to buckets properly
// 	//
// 	// std::vector<Ptr<Ruby::Renderable>> cubes;
// 	//
// 	// for (int i = 0; i < 4; i++) {
// 	// 	for (int j = 0; j < 4; j++) {
// 	// 		for (int k = 0; k < 4; k++) {
// 	// 			//cubes.push_back(CreatePtr<Ruby::Renderable>(cubeMesh, blueMaterial));
// 	// 			//cubes.back()->transform()->position() = Vector3f{(float)i, (float)j, (float)k};
// 	// 		}
// 	// 	}
// 	// }
// 	//
// 	// int frameCount = 0;
// 	// float averageDelta = 0.0f;
// 	//
// 	// // Gem::UglyGameObject gb{};
// 	//
// 	// // auto transform = CreatePtr<Emerald::TransformComponent>();
// 	// // gb.addComponent(transform);
// 	// // auto mesh = CreatePtr<Emerald::MeshComponent>(cubeMesh);
// 	// // gb.addComponent(mesh);
// 	// // auto material = CreatePtr<Emerald::MaterialComponent>(earthMat);
// 	// // gb.addComponent(material);
// 	//
// 	// // auto renderable = CreatePtr<Emerald::RenderingComponent>(transform, mesh, material);
// 	//
// 	// // engine.enlist(gb);
// 	//
// 	// // Rendering loop
// 	// while (window.isOpen()) {
// 	// 	window.pollEvents();
// 	// 	float velocity = 0.05f;
// 	// 	 
// 	// 	if (keyboard.KEY_W) {
// 	// 		camera.position += camera.front * velocity;
// 	// 	}
// 	//
// 	// 	if (keyboard.KEY_A) {
// 	// 		camera.position -= camera.right * velocity;
// 	// 	}
// 	//
// 	// 	if (keyboard.KEY_S) {
// 	// 		camera.position -= camera.front * velocity;
// 	// 	}
// 	//
// 	// 	if (keyboard.KEY_D) {
// 	// 		camera.position += camera.right * velocity;
// 	// 	}
// 	//
// 	// 	if (keyboard.KEY_SPACE) {
// 	// 		camera.position += Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
// 	// 	}
// 	//
// 	// 	if (keyboard.KEY_LEFT_SHIFT) {
// 	// 		camera.position -= Vector3f{ 0.0f, 1.0f, 0.0f } * velocity;
// 	// 	}
// 	//
// 	// 	if (keyboard.KEY_ESCAPE) {
// 	// 		window.close();
// 	// 	}
// 	//
// 	// 	if (mouse.button2) {
// 	// 		if (cursor) {
// 	// 			window.disableCursor();
// 	// 			cursor = false;
// 	// 		}
// 	// 		else {
// 	// 			window.enableCursor();
// 	// 			cursor = true;
// 	// 		}
// 	// 	}
// 	//
// 	// 	{ // Physics
// 	//
// 	// 	}
// 	//
// 	// 	{ // Rendering
// 	// 		// renderer.beginFrame();
// 	// 		//
// 	// 		// for (const Ptr<Ruby::Renderable>& cube : cubes) {
// 	// 		// 	renderer.render(cube);
// 	// 		// }
// 	// 		//
// 	// 		// if (keyboard.KEY_B) {
// 	// 		// 	renderer.render(testRenderable);
// 	// 		// }
// 	// 		//
// 	// 		// renderer.render(cubeRenderable2);
// 	// 		//
// 	// 		// renderer.render(donut);
// 	// 		// // renderer.render(bigSphere);
// 	// 		// renderer.render(earthRenderable);
// 	// 		// renderer.render(pawn);
// 	// 		// renderer.render(awesomeRenderable);
// 	// 		// renderer.render(awesomeRenderable2);
// 	// 		//
// 	// 		// renderer.render(testCube);
// 	// 		// renderer.render(phongCube);
// 	// 		//
// 	// 		// { // Planes
// 	// 		// 	Ruby::OpenGlState::Face culledFace = Ruby::OpenGlState::get().getFaceToCull();
// 	// 		// 	Ruby::OpenGlState::get().setFaceToCull(Ruby::OpenGlState::Face::NONE);
// 	// 		//
// 	// 		// 	renderer.render(planeRenderable);
// 	// 		// 	renderer.render(texturedRenderable);
// 	// 		// 	// renderer.render(screenQuadRenderable);
// 	// 		//
// 	// 		// 	Ruby::OpenGlState::get().setFaceToCull(culledFace);
// 	// 		// }
// 	// 		//
// 	// 		// renderer.debugRender(std::vector{ Vector3f{ 0.0f, 0.0f, 0.0f }, Vector3f{ (float)mouse.xPosition, (float)mouse.yPosition, 5.0f } });
// 	// 		// //renderer.debugRender(cubeMesh, Vector3f{0.0f, 0.0f, 0.0f}, Vector3f{3.0f, 3.0f, 3.0f}); //TODO non functional
// 	// 		//
// 	// 		// renderer.render(skyBox);
// 	// 		//
// 	// 		// renderer.imGuiPrep();
// 	// 		// {
// 	// 		// 	ImGui::Begin("Settings");
// 	// 		// 	{
// 	// 		// 		ImGui::SliderFloat3("Position", &pawn->transform()->position().x, -10.0f, 10.0f);
// 	// 		// 	}
// 	// 		// 	ImGui::End();
// 	// 		// }
// 	// 		// renderer.imGuiEnd();
// 	// 		//
// 	// 		// renderer.endFrame();
// 	// 		// glCheckError();
// 	// 	}
// 	//
// 	// 	window.swapBuffers();
// 	// 	time.endFrame();
// 	// 	frameCount++;
// 	// 	averageDelta += time.deltaTime;
// 	//
// 	// 	if (frameCount == 100) {
// 	// 		// break;
// 	// 	}
// 	// }
// 	//
// 	// LOG("Number of frames: " + std::to_string(frameCount));
// 	// LOG("Average delta time: " + std::to_string(averageDelta / (float)frameCount));
// 	// LOG("Average FPS: " + std::to_string(1 / (averageDelta / (float)frameCount)));
//
// 	// std::cin.get();
//
// 	// renderer.imGuiTerminate();
// return 0;
// }