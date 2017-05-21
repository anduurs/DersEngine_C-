#include "input/InputManager.h"



namespace DersEngine
{
	namespace input
	{
		InputSignalEvent InputManager::inputSignal = std::make_unique<events::Signal<sf::Event>>();

		InputManager::InputManager()
		{
			
		}

		InputManager::~InputManager()
		{
		}

		void InputManager::Init()
		{

		}

		void InputManager::Update()
		{
			sf::Event event;

			while (graphics::Window::PollEvent(event))
			{
				inputSignal->Dispatch(event);
				switch (event.type)
				{
					case sf::Event::Closed:
					{
						graphics::Window::Close();
						break;
					}

					default:
						break;
				}
			}
		}
	}
}
