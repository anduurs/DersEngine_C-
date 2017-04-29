#pragma once

#include <unordered_map>

#include "Scene.h"


namespace DersEngine
{
	namespace core
	{
		using SceneStore = std::unordered_map<std::string, std::shared_ptr<Scene>>;

		class SceneManager
		{
		private:
			static SceneStore m_Scenes;

		public:
			SceneManager();
			~SceneManager();
			static void LoadScene(const std::string& sceneName);
			static void AddScene(const std::string& sceneName, std::shared_ptr<Scene> scene);
		};
	}
}