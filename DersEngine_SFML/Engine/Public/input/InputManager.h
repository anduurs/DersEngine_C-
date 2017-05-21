#pragma once

#include "event/EventDispatcher.h"
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
			InputManager();
			~InputManager();
			static void Init();
			static void Update();
			
			static InputSignalEvent inputSignal;
		};
	}
}
