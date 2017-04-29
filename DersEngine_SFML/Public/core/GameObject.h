#pragma once

#include <vector>
#include <memory>
#include <string>
#include <bitset>
#include <array>



namespace DersEngine
{
	namespace core
	{
		class GameComponent;
		constexpr std::size_t MAX_COMPONENTS{ 32 };

		class GameObject
		{
		private:
			std::vector<std::unique_ptr<GameComponent>> m_Components;
			std::bitset<MAX_COMPONENTS> m_ComponentBitset;
			std::array<GameComponent*, MAX_COMPONENTS> m_ComponentArray;

			bool m_Alive{ true };
			std::string m_Tag;

		public:
			GameObject();
			~GameObject();
			void Update(float dt);
			inline bool IsAlive() const { return m_Alive; }
			void Destroy() { m_Alive = false; }

			template<typename T, typename... Args>
			T& AddComponent(Args&&... args)
			{
				//assert(!HasComponent<T>());

				T* component(new T(std::forward<Args>(args)...));
				component->SetGameObject(*this);
				std::unique_ptr<GameComponent> componentPtr{ component };
				m_Components.emplace_back(std::move(componentPtr));

				m_ComponentArray[GetComponentTypeID<T>()] = component;
				m_ComponentBitset[GetComponentTypeID<T>()] = true;

				component->OnBegin();

				return *component;
			}

			template<typename T>
			T& GetComponent() const
			{
				assert(HasComponent<T>());
				return *static_cast<T*>((m_ComponentArray[GetComponentTypeID<T>()]));
			}

			template<typename T>
			bool HasComponent() const 
			{ 
				return m_ComponentBitset[GetComponentTypeID<T>()];
			}

			inline std::size_t GetUniqueComponentID() noexcept
			{
				static std::size_t ID{ 0u };
				return ID++;
			}

			template<typename T> 
			inline std::size_t GetComponentTypeID() noexcept
			{
				static_assert(std::is_base_of<GameComponent, T>::value, 
					"T must inherit from GameComponent");
				static std::size_t typeID{ GetUniqueComponentID() };
				return typeID;
			}
		};
	}
}

