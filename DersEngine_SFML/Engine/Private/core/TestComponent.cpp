#include "core/TestComponent.h"

namespace DersEngine
{
	namespace core
	{
		void TestComponent::OnBegin() 
		{
			Debug::Log("OnBegin");

			m_InputSignalConnection = InputManager::inputSignal->AddListener(
				std::bind(&TestComponent::OnKeyPressed, this, std::placeholders::_1));
		}

		void TestComponent::OnUpdate(float deltaTime) 
		{
			//Debug::Log("OnUpdate");
		}

		void TestComponent::OnDestroy() 
		{
			InputManager::inputSignal->RemoveListener(m_InputSignalConnection);
			Debug::Log("OnDestroy");
		}

		void TestComponent::OnKeyPressed(const sf::Event& event)
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
				{
					Debug::Log("ON KEY PRESSED");
					InputManager::inputSignal->RemoveListener(m_InputSignalConnection);
					break;
				}
			}
		}
	}
}