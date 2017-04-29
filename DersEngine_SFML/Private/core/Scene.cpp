#include "core/Scene.h"


namespace DersEngine
{
	namespace core
	{
		Scene::Scene(const std::string& name) 
			: m_SceneName(name)
		{
			auto gameobject = std::make_unique<GameObject>();
			gameobject->AddComponent<TestComponent>();
			AddGameObject(std::move(gameobject));
		}

		Scene::~Scene()
		{

		}

		void Scene::AddGameObject(std::unique_ptr<GameObject> gameObject)
		{
			m_GameObjects.emplace_back(std::move(gameObject));
		}

		void Scene::Refresh()
		{
			m_GameObjects.erase(
				std::remove_if(std::begin(m_GameObjects), std::end(m_GameObjects),
				[](const std::unique_ptr<GameObject>& gameObject) 
				{
					return !gameObject->IsAlive();
			    }), 
				std::end(m_GameObjects));
		}

		void Scene::Update(float deltaTime)
		{
			Refresh();

			for (const auto& gameObject : m_GameObjects)
			{
				gameObject->Update(deltaTime);
			}
		}

		void Scene::Render()
		{

		}
	}
}

