#include "core/SceneManager.h"

namespace DersEngine
{
	namespace core
	{
		
		SceneStore SceneManager::m_Scenes; 

		SceneManager::SceneManager()
		{

		}

		SceneManager::~SceneManager()
		{
			m_Scenes.clear();
		}

		void SceneManager::AddScene(const std::string& sceneName, std::shared_ptr<Scene> scene)
		{
			m_Scenes[sceneName] = scene;
		}

		void SceneManager::LoadScene(const std::string& sceneName)
		{

		}
		
	}
}