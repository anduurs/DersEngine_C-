#include "input/InputManager.h"



namespace DersEngine
{
	namespace input
	{
		InputSignalEvent InputManager::inputSignal = std::make_unique<events::Signal<sf::Event>>();

		InputManager::InputManager()
		{
			m_InputSignalConnection = inputSignal->AddListener(
				std::bind(&InputManager::OnInput, this, std::placeholders::_1));
		}

		InputManager::~InputManager()
		{
		}

		void InputManager::Update()
		{
			sf::Event event;

			while (graphics::Window::PollEvent(event))
			{
				inputSignal->Dispatch(event);
			}
		}

		void InputManager::CleanUp()
		{
			inputSignal->RemoveListener(m_InputSignalConnection);
		}

		void InputManager::OnInput(const sf::Event& event)
		{
			if (event.type == sf::Event::Closed 
				|| event.key.code == sf::Keyboard::Escape)
			{
				graphics::Window::Close();
			}
		}
	}
}
