#include "core/TestComponent.h"

namespace DersEngine
{
	namespace core
	{
		void TestComponent::OnBegin() 
		{
			Debug::Log("OnBegin ");
			events::EventDispatcher::Register("KeyPressedEvent", 
				std::bind(&TestComponent::OnKeyPressed, this));
		}

		void TestComponent::OnUpdate(float deltaTime) 
		{
			//Debug::Log("OnUpdate");
		}

		void TestComponent::OnDestroy() 
		{
			Debug::Log("OnDestroy");
		}

		void TestComponent::OnKeyPressed()
		{
			Debug::Log("ON KEY PRESSED");
		}
	}
}