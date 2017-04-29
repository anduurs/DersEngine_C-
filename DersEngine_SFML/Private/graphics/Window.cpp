#include "graphics/Window.h"

namespace DersEngine
{
	namespace graphics
	{
		unsigned int Window::WIDTH = 0;
		unsigned int Window::HEIGHT = 0;

		std::unique_ptr<sf::RenderWindow> Window::m_SFMLWindow = nullptr;

		Window::Window(unsigned int width, unsigned int height, const std::string& title,
			bool vsync, bool fullScreen)
		{
			m_SFMLWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
			m_SFMLWindow->setVerticalSyncEnabled(vsync);

			Window::WIDTH = width;
			Window::HEIGHT = height;
		}

		Window::~Window()
		{
		}

		void Window::Display()
		{
			m_SFMLWindow->display();
		}

		bool Window::IsOpen()
		{
			return m_SFMLWindow->isOpen();
		}

		bool Window::PollEvent(sf::Event& event)
		{
			return m_SFMLWindow->pollEvent(event);
		}

		void Window::Close()
		{
			m_SFMLWindow->close();
		}

		void Window::Clear()
		{
			glClearColor(0, 0, 0, 0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}
}

