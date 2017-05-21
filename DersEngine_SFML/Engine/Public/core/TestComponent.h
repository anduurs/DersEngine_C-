#pragma once

#include "input/InputManager.h"

#include "GameComponent.h"
#include "core/GameApplication.h"

namespace DersEngine
{
	namespace core
	{
		class TestComponent : public GameComponent
		{
		public:
			virtual void OnBegin() override;
			virtual void OnUpdate(float deltaTime) override;
			virtual void OnDestroy() override;

			void OnInput(const sf::Event& event);

		private:
			std::shared_ptr<void> m_InputSignalConnection;
			
		};
	}
}
