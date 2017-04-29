#pragma once

#include <memory>
#include <string>
#include <chrono>
#include <iostream>

#include "Scene.h"
#include "graphics/Window.h"
#include "input/InputManager.h"

namespace DersEngine 
{
	namespace core 
	{
		using namespace input;
		using namespace graphics;
		class Scene;
		class GameApplication
		{
		private:
			volatile bool m_Running;

			static std::unique_ptr<Scene> m_CurrentScene;
			std::unique_ptr<Window> m_Window;

			void RunGameLoop();
			void ProcessInputs();
			void Update(float deltaTime);
			void Render();

		public:
			GameApplication(unsigned int width, unsigned int height, 
				const std::string& title, bool vsync, bool fullScreen);
			~GameApplication();

			void Start();
			void Stop();
			static void LoadScene(std::unique_ptr<Scene> scene);
		};
	}
}

