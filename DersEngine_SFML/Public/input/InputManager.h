#pragma once

#include "event/EventDispatcher.h"
#include "utils/Debug.h"

namespace DersEngine 
{
	namespace input 
	{
		using namespace utils;
		class InputManager
		{
		private:
				
		public:
			InputManager();
			~InputManager();

			static void Update();
		};
	}
}
