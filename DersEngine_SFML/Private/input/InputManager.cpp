#include "input/InputManager.h"

#include "graphics/Window.h"

namespace DersEngine
{
	namespace input
	{
		InputManager::InputManager()
		{
		}

		InputManager::~InputManager()
		{
		}

		void InputManager::Update()
		{
			sf::Event event;

			while (graphics::Window::PollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
				{
					graphics::Window::Close();
					break;
				}

				case sf::Event::KeyPressed:
				{
					
					events::EventDispatcher::Dispatch("KeyPressedEvent");
					break;
				}

				default:
					break;
				}
			}
		}
	}
}
