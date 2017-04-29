#pragma once

#include <iostream>
#include <string>

namespace DersEngine
{
	namespace Debug
	{
		static void Log(const std::string& debugMessage)
		{
			std::cout << debugMessage << std::endl;
		}

		
	}
}