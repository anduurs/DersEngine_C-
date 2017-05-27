#pragma once

#include <algorithm>

#include "GameObject.h"
#include "TestComponent.h"

namespace DersEngine
{
	namespace core
	{
		class Scene
		{
		private:
			std::vector<std::unique_ptr<GameObject>> m_GameObjects;
			std::string m_SceneName;

			void Refresh();
		public:
			Scene(const std::string& name);
			virtual ~Scene();

			virtual void Update(float deltaTime);
			virtual void Render();

			void AddGameObject(std::unique_ptr<GameObject> gameObject);
		};
	}
}


