#pragma once

#include <memory>

namespace DersEngine
{
	namespace core
	{
		class GameObject;

		class GameComponent
		{
		protected:
			GameObject* m_GameObject;
			bool m_Enabled;
		public:
			virtual void OnBegin() {}
			virtual void OnUpdate(float deltaTime) {}
			virtual void OnDestroy() {}
			virtual void OnEnable() {}
			virtual void OnDisable() {}

			void SetGameObject(GameObject& gameObject) { m_GameObject = &gameObject; }
			inline GameObject& GetGameObject() const { return *m_GameObject; }
			void Enable(bool enable) 
			{ 
				if (enable)
				{
					OnEnable();
				}
				else
				{
					OnDisable();
				}

				m_Enabled = enable; 
			}
			inline bool IsEnabled() const { return m_Enabled; }
		};
	}
}


