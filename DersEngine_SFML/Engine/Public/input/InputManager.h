#pragma once

#include "event/EventDispatcher.h"
#include "utils/Debug.h"

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
		};
	}
}
