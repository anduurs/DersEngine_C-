#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <memory>

namespace DersEngine
{
	namespace graphics
	{
		class Window
		{
		private:
			static unsigned int WIDTH;
			static unsigned int HEIGHT;

			static std::unique_ptr<sf::RenderWindow> m_SFMLWindow;

		public:
			Window(unsigned int width, unsigned int height,
				const std::string& title, bool vsync, bool fullScreen);
			~Window();

			void Display();
			void Clear();
			bool IsOpen();

			static bool PollEvent(sf::Event& event);
			static void Close();

			inline static unsigned int GetWidth() { return WIDTH; }
			inline static unsigned int GetHeight() { return HEIGHT; }
		};
	}
}
