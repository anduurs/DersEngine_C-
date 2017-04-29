#include "core/GameObject.h"
#include "core/GameComponent.h"

namespace DersEngine
{
	namespace core
	{
		GameObject::GameObject() 	
		{
		}

		GameObject::~GameObject()
		{
			for (const auto& c : m_Components)
			{
				c->OnDestroy();
			}
		}

		void GameObject::Update(float dt)
		{
			for (const auto& c : m_Components)
			{
				c->OnUpdate(dt);
			}
		}
	}
}


