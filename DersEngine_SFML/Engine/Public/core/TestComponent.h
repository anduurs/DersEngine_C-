#pragma once

#include "GameComponent.h"
#include "utils/Debug.h"
#include "core/GameApplication.h"
#include <functional>

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
