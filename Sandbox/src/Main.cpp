// Wavellite
#include "Window.h"
#include "Timing.h"

// Ruby
#include "Renderers/Renderer.h"
#include "Camera.h"
#include "Renderable Objects/Renderable.h"
#include "Geometry/CubeGeometryData.h"
#include "Geometry/SphereGeometryData.h"
#include "Materials/PhongMaterial.h"
#include "Materials/SolidMaterial.h"
#include "Renderable Objects/SkyBox.h"
#include "Resources/Image.h"

// Custom
#include "FPSCamera.h"

#include "Geometry/PlaneGeometryData.h"

#include "Materials/ScreenMaterial.h"
#include "Materials/TextureMaterial.h"

#include "Utility/Bank.h"
#include <OpenGlErrors.h>

#include "Pointer.h"

int main() {
	Wavellite::Window window{ Wavellite::Window::WindowSize::HALF_SCREEN, "Sandbox", 1000.0f };
	Wavellite::Mouse& mouse = window.ioManger.getMouse();
	Wavellite::Keyboard& keyboard = window.ioManger.getKeyboard();

	FPSCamera camera{};
	mouse.addMousePositionCallback(mousePositionCallback, (void*)&camera);
	window.disableCursor();

	Wavellite::Time time{ };
	Ruby::Renderer renderer{ camera, window };

	camera.position = Malachite::Vector3f{ 0.0f, 0.0f, 5.0f };

	// Ruby::ImageBank imageBank{ };
	Ruby::TextureBank textureBank{ };

	Ruby::Ptr<Ruby::SkyBoxMaterial> skyBoxMat = Ruby::createPtr<Ruby::SkyBoxMaterial>( std::initializer_list<Ruby::Ptr<Ruby::Image>>{
		Ruby::createPtr<Ruby::Image>("assets\\SkyBox\\right.jpg", false),
		Ruby::createPtr<Ruby::Image>("assets\\SkyBox\\left.jpg", false),
		Ruby::createPtr<Ruby::Image>("assets\\SkyBox\\top.jpg", false),
		Ruby::createPtr<Ruby::Image>("assets\\SkyBox\\bottom.jpg", false),
		Ruby::createPtr<Ruby::Image>("assets\\SkyBox\\front.jpg", false),
		Ruby::createPtr<Ruby::Image>("assets\\SkyBox\\back.jpg", false)
	} );

	Ruby::SkyBox skyBox{ skyBoxMat };

	Ruby::Ptr<Ruby::SolidMaterial> blueMaterial = Ruby::createPtr<Ruby::SolidMaterial>(Ruby::Colour::blue);

	Ruby::Ptr<Ruby::CubeGeometryData> cubeGeometryData = Ruby::createPtr<Ruby::CubeGeometryData>();
	Ruby::Ptr<Ruby::SphereGeometryData> sphereGeometryData = Ruby::createPtr<Ruby::SphereGeometryData>();
	Ruby::Ptr<Ruby::PlaneGeometryData> planeGeometryData = Ruby::createPtr<Ruby::PlaneGeometryData>();

	Ruby::Renderable testCube{ cubeGeometryData, blueMaterial };

	Ruby::Ptr<Ruby::PhongMaterial> containerMaterial = Ruby::createPtr<Ruby::PhongMaterial>(
		*textureBank.createAndGet(Ruby::createPtr<Ruby::Image>("assets\\container2.png")),
		*textureBank.createAndGet(Ruby::createPtr<Ruby::Image>("assets\\container2_specular.png"))
	);

	std::vector<Ruby::DirectionalLight*> directionalLights{};
	Ruby::DirectionalLight directionalLight{ Malachite::Vector3f{ 3.0f, -3.0f, 0.5f } };
	directionalLights.push_back(&directionalLight);

	Ruby::PhongMaterial::directionalLights = directionalLights;

	Ruby::Renderable phongCube{ cubeGeometryData, containerMaterial };
	phongCube.getModelMatrix().translate(-3.0f, 0.0f, 0.0f);

	auto doughnutTexture = textureBank.createAndGet(Ruby::createPtr<Ruby::Image>("assets\\Donut4.png"));
	Ruby::Ptr<Ruby::PhongMaterial> donutMat = Ruby::createPtr<Ruby::PhongMaterial>(*doughnutTexture, * doughnutTexture);

	auto* earthTexture = textureBank.createAndGet(Ruby::createPtr<Ruby::Image>("assets\\earth.jpg"));
	Ruby::Ptr<Ruby::PhongMaterial> earthMat = Ruby::createPtr<Ruby::PhongMaterial>(*earthTexture, *earthTexture);

	auto* pawnTexture = textureBank.createAndGet(Ruby::createPtr<Ruby::Image>("assets\\White Pawn.png"));
	Ruby::Ptr<Ruby::PhongMaterial> pawnMat = Ruby::createPtr<Ruby::PhongMaterial>(*pawnTexture, *pawnTexture );

	auto* awesomeFaceTexture = textureBank.createAndGet(Ruby::createPtr<Ruby::Image>("assets\\awesomeface.png"));
	Ruby::Ptr<Ruby::PhongMaterial> awesomeMat = Ruby::createPtr<Ruby::PhongMaterial>(*awesomeFaceTexture, *awesomeFaceTexture);

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

	Ruby::Renderable planeRenderable{ planeGeometryData, containerMaterial };
	planeRenderable.getModelMatrix().translate(3.0f, 3.0f, 0.0f);

	Ruby::Ptr<Ruby::TextureMaterial> awesomeFaceMaterial = Ruby::createPtr<Ruby::TextureMaterial>( * awesomeFaceTexture );
	Ruby::Renderable texturedRenderable{ planeGeometryData, awesomeFaceMaterial };
	texturedRenderable.getModelMatrix().translate(-3.0f, 3.0f, 0.0f);

	Ruby::Ptr<Ruby::ScreenMaterial> awesomeFaceMaterial2 = Ruby::createPtr<Ruby::ScreenMaterial>( * earthTexture );
	Ruby::Renderable screenQuadRenderable{ planeGeometryData, awesomeFaceMaterial2 };
	screenQuadRenderable.getModelMatrix().scale(0.5f).translate(-0.5f, -0.5f, 0.0f);

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

			{ // Planes
				Ruby::OpenGlContext backupContext = Ruby::OpenGlContext::getCurrent();
				Ruby::OpenGlContext newContext = backupContext;
				newContext.faceToCull = Ruby::OpenGlContext::FaceCull::NONE;
				newContext.makeCurrent();

				renderer.render(planeRenderable);
				renderer.render(texturedRenderable);
				//renderer.render(screenQuadRenderable);

				backupContext.makeCurrent();
			}

			//renderer.render(std::vector{ Malachite::Vector3f{ 0.0f, 0.0f, 0.0f }, Malachite::Vector3f{ 5.0f, 5.0f, 5.0f } });

			renderer.render(skyBox);

			renderer.endFrame();
			glCheckError();
		}

		window.swapBuffers();
		time.endFrame();
	}
	renderer.imGuiTerminate();
}