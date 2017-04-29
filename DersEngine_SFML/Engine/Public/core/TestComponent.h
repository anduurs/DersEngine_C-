#pragma once

#include <functional>

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

			void OnKeyPressed();

		private:

		};
	}
}
