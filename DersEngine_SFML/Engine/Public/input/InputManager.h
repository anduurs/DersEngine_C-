#pragma once

#include "event/EventDispatcher.h"
#include "event/Signal.h"
#include "utils/Debug.h"

#include "graphics/Window.h"

namespace DersEngine 
{
	namespace input 
	{
		class InputManager
		{
		private:
				
		public:
			InputManager();
			~InputManager();
			static void Init();
			static void Update();
			
			static std::unique_ptr<events::Signal<sf::Event>> inputSignal;
		};
	}
}
