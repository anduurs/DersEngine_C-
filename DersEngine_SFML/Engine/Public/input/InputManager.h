#pragma once

#include "event/Signal.h"
#include "utils/Debug.h"

#include "graphics/Window.h"

namespace DersEngine 
{
	namespace input 
	{
		using InputSignalEvent = std::unique_ptr<events::Signal<sf::Event>>;

		class InputManager
		{	
		public:
			static InputSignalEvent inputSignal;
		private:
			std::shared_ptr<void> m_InputSignalConnection;
		public:
			InputManager();
			~InputManager();
			void Update();
			void CleanUp();
		private:
			void OnInput(const sf::Event& event);
			
		};
	}
}
