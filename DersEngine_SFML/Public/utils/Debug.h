#pragma once

#include <iostream>
#include <string>

namespace DersEngine
{
	namespace utils
	{
		class Debug 
		{
		public:
			static void Log(const std::string& debugMessage)
			{
				std::cout << debugMessage << std::endl;
			}
		};
	}
}