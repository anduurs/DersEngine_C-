#include "core/GameApplication.h"

namespace DersEngine 
{
	namespace core
	{
		std::unique_ptr<Scene> GameApplication::m_CurrentScene = nullptr;

		GameApplication::GameApplication(unsigned int width, unsigned int height,
			const std::string& title, bool vsync, bool fullScreen)
		{
			m_Window = std::make_unique<Window>(width, height, title, vsync, fullScreen);
			m_InputManager = std::make_unique<InputManager>();
		}

		GameApplication::~GameApplication()
		{

		}

		void GameApplication::Start()
		{
			std::cout << "Game started" << std::endl;
			m_Running = true;
			RunGameLoop();
		}

		void GameApplication::Stop()
		{
			std::cout << "Game stopped" << std::endl;
			m_Running = false;
			m_InputManager->CleanUp();
		}

		void GameApplication::RunGameLoop()
		{
			auto previousTime = std::chrono::high_resolution_clock::now();

			double elapsedTimeInSeconds = 0.0;
			double accumulator = 0.0;
			double frameCounter = 0.0;

			int fps = 0;
			int tps = 0;

			const double TARGET_UPS = 60.0;
			const double SECONDS_PER_UPDATE = 1.0 / TARGET_UPS;
			float dt = (float)SECONDS_PER_UPDATE;

			while (m_Running)
			{
				auto currentTime = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> elapsedTime = currentTime - previousTime;

				elapsedTimeInSeconds = elapsedTime.count();

				if (elapsedTimeInSeconds > 0.25)
				{
					elapsedTimeInSeconds = 0.25;
				}

				accumulator += elapsedTimeInSeconds;
				frameCounter += elapsedTimeInSeconds;

				previousTime = currentTime;

				while (accumulator >= SECONDS_PER_UPDATE)
				{
					ProcessInputs();
			
					Update(dt);

					tps++;
					accumulator -= SECONDS_PER_UPDATE;
				}

				Render();
				fps++;

				if (frameCounter >= 1)
				{
					//Debug::Log(fps, " fps, ", tps, " tps");
					fps = 0;
					tps = 0;
					frameCounter = 0;
				}

				if (!m_Window->IsOpen())
				{
					Stop();
				}
			}
		}

		void GameApplication::ProcessInputs()
		{
			m_InputManager->Update();
		}

		void GameApplication::Update(float deltaTime)
		{
			m_CurrentScene->Update(deltaTime);
		}

		void GameApplication::Render()
		{
			m_Window->Clear();
			m_CurrentScene->Render();
			m_Window->Display();
		}

		void GameApplication::LoadScene(std::unique_ptr<Scene> scene)
		{
			m_CurrentScene = std::move(scene);
		}
	}
}
