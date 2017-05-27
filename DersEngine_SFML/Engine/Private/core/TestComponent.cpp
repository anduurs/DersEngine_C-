#include "core/TestComponent.h"

namespace DersEngine
{
	namespace core
	{
		void TestComponent::OnBegin() 
		{
			Debug::Log("OnBegin");

			m_InputSignalConnection = InputManager::inputSignal->AddListener(
				std::bind(&TestComponent::OnInput, this, std::placeholders::_1));

			//m_InputSignalConnection = InputManager::inputSignal->AddListener(&TestComponent::OnInput, *this);
		}

		void TestComponent::OnUpdate(float deltaTime) 
		{
			//Debug::Log("OnUpdate");
		}

		void TestComponent::OnDestroy() 
		{
			Debug::Log("OnDestroy");
			InputManager::inputSignal->RemoveListener(m_InputSignalConnection);
		}

		void TestComponent::OnInput(const sf::Event& event)
		{
			switch (event.type)
			{
				case sf::Event::KeyPressed:
				{
					Debug::Log("KEY PRESSED EVENT");
					break;
				}
			}
		}
	}
}